#include <iostream>
using namespace std;

struct ProcessNode {
    int process_id;
    int remaining_time;
    int execution_time;
    ProcessNode* next;
    // constructor to initialize the struct's members
    ProcessNode(int id, int time) {
        process_id = id;
        remaining_time = time;
        execution_time = time;
        next = nullptr;
    }
};

class CircularLinkedList {
public:
    ProcessNode* head;
    //constructor
    CircularLinkedList() {
        head = nullptr;
    }
    //function to add a new process (node) to the circular linked list
    void addProcess(int process_id, int execution_time) {
        ProcessNode* new_process = new ProcessNode(process_id, execution_time);
        if (!head) {
            head = new_process;
            head->next = head; //circular link itself
        }
        else {
            ProcessNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_process;
            new_process->next = head; //circular connection back to head
        }
    }
    //Function to removes a process (node) from the circular linked list
    void removeProcess(ProcessNode* process) {
        if (head == process && head->next == head) {
            //only one process in the list
            delete head;
            head = nullptr;
        }
        else {
            ProcessNode* temp = head;
            while (temp->next != process) {
                temp = temp->next;
            }
            temp->next = process->next;
            if (process == head) {
                head = process->next;
            }
            delete process;
        }
    }
    //function to display the current state of all processes in the circular linked list
    void display_process() {
        if (!head) {
            cout << "No processes in the system" << endl;
            return;
        }
        ProcessNode* temp = head;
        do {
            cout << "Process ID: " << temp->process_id << " (Remaining: " << temp->remaining_time << ") " << endl;
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

// Function to handle CPU scheduling
void CPUScheduling(CircularLinkedList& process_list, int time_slice) {
    ProcessNode* current_process = process_list.head;
    int cycle = 1;

    while (process_list.head != nullptr) {
        cout << "Cycle " << cycle << ": ";

        if (current_process->remaining_time > time_slice) {
            current_process->remaining_time -= time_slice;
            cout << "Process " << current_process->process_id << " executed for " << time_slice << " units.\n";
        }
        else {
            cout << "Process " << current_process->process_id << " completes." << endl;
            process_list.removeProcess(current_process);  // Remove the completed process

            // If list becomes empty, terminate
            if (!process_list.head) {
                break;
            }
            current_process = process_list.head;  // Reset to head if the current process is removed
            continue;
        }

        // Display the state of the processes after this cycle
        process_list.display_process();

        // Move to the next process in the circular list
        current_process = current_process->next;
        cycle++;
        // Simulate new process arrival with user input
        if (cycle == 3) {
            char add_process;
            cout << "Do you want to add a new process? (y/n): ";
            cin >> add_process;

            if (add_process == 'y' || add_process == 'Y') {
                int new_process_id, new_execution_time;
                cout << "Enter Process ID: ";
                cin >> new_process_id;
                cout << "Enter Execution Time: ";
                cin >> new_execution_time;
                process_list.addProcess(new_process_id, new_execution_time);
                cout << "New process added: P" << new_process_id << " (Remaining: " << new_execution_time << ")" << endl;
            }
        }
    }
 
}

int main() {
    CircularLinkedList process_list;

    // Add initial processes: process_id, execution_time
    process_list.addProcess(1, 10);  // P1 requires 10 units
    process_list.addProcess(2, 5);   // P2 requires 5 units
    process_list.addProcess(3, 8);   // P3 requires 8 units

    // Get the time slice (CPU time per process per cycle) from the user
    int time_slice;
    cout << "Enter the CPU Time per Process per Cycle: ";
    cin >> time_slice;

    // Start the CPU scheduling
    cout << "Initial Processes: [(P1, 10), (P2, 5), (P3, 8)]\n";
    CPUScheduling(process_list, time_slice);

    cout << "\nAll processes completed." << endl;
    return 0;
}
