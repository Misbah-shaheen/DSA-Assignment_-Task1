## DSA-Assignment_-Task1
# Simple Process Scheduling Algorithm

## Overview

This project implements a CPU Process Scheduling Algorithm using a Circular Linked List. The algorithm cycles through processes, assigning CPU time until all processes complete their execution. The program can also handle the dynamic addition of new processes during execution.

## Approach

1. **Circular Linked List Structure**:
   - Each process is represented as a node in the circular linked list, containing attributes for `process_id`, `execution_time`, and `remaining_time`.
   - The list supports dynamic management of processes, allowing for easy addition and removal.

2. **Scheduling Logic**:
   - A fixed amount of CPU time (time slice) is assigned to each process in each cycle.
   - After executing for the designated time, the remaining execution time for the process is updated.
   - If a process's remaining time reaches zero, it is removed from the list.

3. **Cycle Management**:
   - The state of all processes is displayed after each cycle, showing which process is currently executing and its remaining time.
   - The system simulates new process arrivals based on user input during the scheduling process.

4. **User Interaction**:
   - The program prompts the user to add new processes during the execution, enabling dynamic management of the scheduling queue.

## Assumptions

- The CPU time slice is a positive integer that represents the amount of time each process gets in each cycle.
- The input for new processes, including process ID and execution time, is valid and positive.
- The initial processes are added to the list before the scheduling begins.

## Challenges Faced

- Implementing the circular linked list required careful management of pointers to ensure proper linking and removal of nodes.
- Ensuring that the system correctly handles the state of processes, especially after dynamic additions and removals, was a key focus.
- Validating user input during process addition while maintaining the smooth execution of the scheduling algorithm added complexity.

## Setup and Running Instructions

1. Ensure you have a C++ compiler (e.g., g++) installed on your system.

## Contributors


 Misbah Shaheen    
 Email:
 [misbahshaheentiwana007@gmail.com](mailto:misbahshaheentiwana007@gmail.com) 

