#include <iostream>
#include <thread>
#include<vector>


using namespace std;

// Process states
enum ProcessState { READY_TO_RUN, WAIT, STOP, COMPLETE };

// Process Class 
class Process {

public : 
    int pId;
    int time_cycle;
    ProcessState state;
    int cpuID;
    int ready_to_run_time;
    int wait_time;
    int stop_time;
    int complete_time;
};

void simulateTimecycle(){
    // sleep for 1 sec 
    this_thread::sleep_for(chrono::seconds(1));
}

void simulateProcess(Process& p) {
    // Simulate each process for  1 sec and then timecycle drcreament by 1 
    simulateTimecycle();
    p.time_cycle--;

    // Update Process
    int state_status = rand() % 4 ;

    switch (state_status)
    {
    case 0:
        p.state = READY_TO_RUN;
        p.ready_to_run_time++;
        break;

    case 1:
        p.state = WAIT;
        p.wait_time++;
        simulateTimecycle();
        simulateTimecycle();
        simulateTimecycle();
        break;

    case 2:
        p.state = STOP;
        p.stop_time++;
        cout << "Process " << p.pId << " is Stoped " << endl;
        break;

    case 3:
        p.state = COMPLETE;
        p.complete_time++;
        cout << "Process " << p.pId << " is Completed " << endl;
        break;

    default:
        break;
    }

}


int main() {

    srand(time(nullptr));
    // for storing information of process is in array format 
    vector<Process> processes;
    // use input no of process 
    cout << "No of Process: "; 
    int no_process;
    cin >> no_process;

    // Intialize No of Process 
    for (int i = 0; i < no_process; i++) {

        Process p;
        // Process id start from 1 to n
        p.pId = i + 1;
        // random time between 1 to 5
        p.time_cycle = rand() % 5 + 1; // random time between 1 to 5 
        p.state = READY_TO_RUN;
        p.cpuID = -1;
        p.ready_to_run_time = 0;
        p.wait_time = 0;
        p.complete_time = 0;
        p.stop_time = 0;
        processes.push_back(p);
    }


    // Start Simulation 

    int time = 0;

    while (true) {

        cout << "Time " << time << " Passes" << endl;
        // Assign Process to CPU for schduling 

        for (int i = 0; i < no_process; i++) {
            if (processes[i].state == READY_TO_RUN && processes[i].cpuID == -1) {

                // Assign CPU to Process 
                for (int j = 0; j < no_process; j++) {
                    if (processes[j].cpuID == -1) {
                        processes[j].cpuID = i;
                    }
                }
            }
        }

        // simulate process on CPU 
        for (int i = 0; i < no_process; i++) {
            if (processes[i].cpuID != -1) {
                simulateProcess(processes[i]);
                // if Process timecycle completed then to be removed 
                // CPU from process 
                if (processes[i].time_cycle == 0) {
                    processes[i].cpuID = -1;
                }
            }
        }

        // update the Process states for  waiting 
        for (int i = 0; i < no_process; i++) {
            if (processes[i].state == WAIT) {
                processes[i].wait_time++;

                if (processes[i].wait_time > 3) {
                    processes[i].state = READY_TO_RUN;
                    processes[i].wait_time = 0;
                    cout << "Process " << processes[i].pId << " is ready to run" << endl;
                }
            }
        }

        

        // Stop the Process state 
        for (int i = 0; i < no_process; i++) {
            if (processes[i].state == STOP) {
                cout << "Process " << processes[i].pId << " is Stoped. Press 'S' start to go into the ready state " << endl;
                char ch;
                cin >> ch;
                

                if (ch == 'S') {
                    processes[i].state == READY_TO_RUN;
                    processes[i].stop_time = 0;
                    cout << "Process " << processes[i].pId << " is ready to run" << endl;

                }


            }
        }

        bool all_completed = true;

        for (int i = 0; i < no_process; i++) {
            if (processes[i].state != COMPLETE) {
                all_completed = false;
                break;
            }
            if (all_completed == true) {
                break;
            }
        }

        time++;
    }
    // Display Process schduler Log 

    for (int i = 0; i < no_process; i++) {
        cout << "Process " << processes[i].pId << ":-" << endl;
        cout << "Process state: " << processes[i].state << " " << endl;

        cout << "  Ready to Run Time: " << processes[i].ready_to_run_time << " seconds" << endl;
        cout << "  Wait Time: " << processes[i].wait_time << "seconds" << endl;
        cout << "  Stop Time: " << processes[i].stop_time << "seconds" << endl;
        cout << "  Complete Time: " << processes[i].complete_time << " seconds" << endl;
    }

}










