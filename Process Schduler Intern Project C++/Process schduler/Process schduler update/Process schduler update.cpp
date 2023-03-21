#include <iostream>
#include <vector>

#include <thread>

using namespace std;

// Process states
enum ProcessState { READY_TO_RUN, WAITING, STOPPED, COMPLETED };

// Process struct
struct Process {
    int id;
    int time_cycle;
    ProcessState state;
    int cpu;

    int ready_to_run_time;
    int waiting_time;
    int stopped_time;
    int completed_time;
};

// Simulate a time cycle of 1 second
void simulateTimeCycle() {
    this_thread::sleep_for(chrono::seconds(1));
}

// Simulate a process
void simulateProcess(Process& process) {
    // Run the process for a time slice of 1 second
    simulateTimeCycle();
    process.time_cycle--;

    // Update process state randomly
    int state_num = rand() % 4;
    switch (state_num) {
    case 0:
        process.state = READY_TO_RUN;
        process.ready_to_run_time++;
        break;
    case 1:
        process.state = WAITING;
        process.waiting_time++;
        simulateTimeCycle();
        simulateTimeCycle();
        simulateTimeCycle();
        break;
    case 2:
        process.state = STOPPED;
        process.stopped_time++;
        cout << "Process " << process.id << " is stopped." << endl;
        break;
    case 3:
        process.state = COMPLETED;
        process.completed_time++;
        cout << "Process " << process.id << " is completed." << endl;
        break;
    default:
        break;
    }
}

int main() {
    // Initialize random seed
    srand(time(nullptr));

    // Initialize processes
    vector<Process> processes;
    const int NUM_PROCESSES = 3;
    for (int i = 0; i < NUM_PROCESSES; i++) {
        Process process;
        process.id = i + 1;
        process.time_cycle = rand() % 3 + 1;  // Random time cycle between 1 and 10 seconds
        process.state = READY_TO_RUN;
        process.cpu = -1;  // -1 means process is not running on any CPU
        process.ready_to_run_time = 0;
        process.waiting_time = 0;
        process.stopped_time = 0;
        process.completed_time = 0;
        processes.push_back(process);
    }

    // Start simulation
    int time_elapsed = 0;
    while (true) {
        cout << "Time Elapsed: " << time_elapsed << " seconds" << endl;

        // Schedule processes to run on CPUs
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (processes[i].state == READY_TO_RUN && processes[i].cpu == -1) {
                // Find an available CPU to run the process
                for (int j = 0; j < NUM_PROCESSES; j++) {
                    if (processes[j].cpu == -1) {
                        processes[j].cpu = i;
                        break;
                    }
                }
            }
        }

        // Simulate running processes on CPUs
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (processes[i].cpu != -1) {
                simulateProcess(processes[i]);
                if (processes[i].time_cycle == 0) {
                    // Process has completed its time cycle
                    processes[i].cpu = -1;
                }
            }
        }

        // Update process states
          // Update process states that are waiting
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (processes[i].state == WAITING) {
                processes[i].waiting_time++;
                if (processes[i].waiting_time >= 3) {
                    processes[i].state = READY_TO_RUN;
                    processes[i].waiting_time = 0;
                    cout << "Process " << processes[i].id << " is ready to run." << endl;
                }
            }
        }

        // Update process states that are stopped
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (processes[i].state == STOPPED) {
                cout << "Process " << processes[i].id << " is stopped. Press 'r' to make it ready to run: ";
                char input;
                cin >> input;
                if (input == 'r') {
                    processes[i].state = READY_TO_RUN;
                    processes[i].stopped_time = 0;
                    cout << "Process " << processes[i].id << " is ready to run." << endl;
                }
            }
        }

        // Check if all processes are completed
        bool all_completed = true;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (processes[i].state != COMPLETED) {
                all_completed = false;
                break;
            }
        }
        if (all_completed) {
            break;
        }

        time_elapsed++;
    }

    // Print process statistics
    for (int i = 0; i < NUM_PROCESSES; i++) {
        cout << "Process " << processes[i].id << ":" << endl;
        cout << "  Ready to Run Time: " << processes[i].ready_to_run_time << " seconds" << endl;
        cout << "  Waiting Time: " << processes[i].waiting_time << " seconds" << endl;
        cout << "  Stopped Time: " << processes[i].stopped_time << " seconds" << endl;
        cout << "  Completed Time: " << processes[i].completed_time << " seconds" << endl;
    }

    return 0;
}

