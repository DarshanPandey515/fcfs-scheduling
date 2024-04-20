# Process Scheduling Simulator

This is a simple C program that simulates process scheduling using basic algorithms. The program allows you to input details of processes, such as arrival time and burst time, and then displays a Gantt chart and a table summarizing process metrics.

## How to Use

1. **Compile and Run**
   - Compile the program using a C compiler (e.g., gcc).
   - Run the compiled executable.

2. **Input**
   - Enter the number of processes when prompted.
   - For each process (P1, P2, ...), enter the arrival time and burst time.

3. **Output**
   - A Gantt chart displaying the sequence of processes and their execution times.
   - A table summarizing process details including completion time (CT), turnaround time (TAT), waiting time (WT), and response time (RT).
   - Average turnaround time and average waiting time for all processes.

## Sample Output

- Enter the number of processes: 5
- Enter arrival time and burst time for Process P1: 0 2
- Enter arrival time and burst time for Process P2: 1 3
- Enter arrival time and burst time for Process P3: 2 5
- Enter arrival time and burst time for Process P4: 3 4
- Enter arrival time and burst time for Process P5: 4 6

Gantt Chart:
| Process | AT | BT | CT | TAT | WT | RT |
|---------|----|----|----|-----|----|----|
| P1      | 0  | 2  | 2  | 2   | 0  | 0  |
| P2      | 1  | 3  | 5  | 4   | 1  | 1  |
| P3      | 2  | 5  | 10 | 8   | 3  | 3  |
| P4      | 3  | 4  | 14 | 11  | 7  | 7  |
| P5      | 4  | 6  | 20 | 16  | 10 | 10 |

#### Average Turnaround Time: 8.20
#### Average Waiting Time: 4.20



## Cleanup

The program automatically frees memory after execution.

## Note

- This code demonstrates basic process scheduling simulation and can be expanded or optimized further based on specific scheduling algorithms.
