#include <stdio.h>
#include <stdlib.h>

typedef struct Process
{
    int pid;           
    int arrivalTime;   
    int burstTime;     
    int completionTime;
    int turnaroundTime;
    int waitingTime;   
    int responseTime;  
    struct Process *next; 
} Process;

Process *createProcess(int pid, int arrivalTime, int burstTime)
{
    Process *newProcess = (Process *)malloc(sizeof(Process));
    if (newProcess == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newProcess->pid = pid;
    newProcess->arrivalTime = arrivalTime;
    newProcess->burstTime = burstTime;
    newProcess->completionTime = 0;
    newProcess->turnaroundTime = 0;
    newProcess->waitingTime = 0;
    newProcess->responseTime = 0;
    newProcess->next = NULL;
    return newProcess;
}

void insertProcess(Process **head, int pid, int arrivalTime, int burstTime)
{
    Process *newProcess = createProcess(pid, arrivalTime, burstTime);
    if (*head == NULL)
    {
        *head = newProcess;
    }
    else
    {
        Process *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newProcess;
    }
}

void displayTable(Process *head)
{
    printf("\n\n");
    printf("------------------------------------------\n");
    printf("| Process | AT | BT | CT | TAT | WT | RT |\n");
    printf("------------------------------------------\n");

    Process *current = head;
    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;
    int numProcesses = 0;

    while (current != NULL)
    {
        current->responseTime = currentTime - current->arrivalTime;
        current->completionTime = currentTime + current->burstTime;
        current->turnaroundTime = current->completionTime - current->arrivalTime;
        current->waitingTime = current->turnaroundTime - current->burstTime;

        printf("|    P%d   |  %d  |  %d  |  %d  |  %d  | %d | %d |\n",
               current->pid, current->arrivalTime, current->burstTime,
               current->completionTime, current->turnaroundTime,
               current->waitingTime, current->responseTime);

        totalTurnaroundTime += current->turnaroundTime;
        totalWaitingTime += current->waitingTime;
        numProcesses++;

        currentTime = current->completionTime;
        current = current->next;
    }

    printf("--------------------------------------------------\n");

    float avgTurnaroundTime = (float)totalTurnaroundTime / numProcesses;
    float avgWaitingTime = (float)totalWaitingTime / numProcesses;
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
}



void displayGanttChart(Process *head) {
    printf("\nGantt Chart:\n");
    printf("-----------------------------------------------------\n");

    Process *current = head;

    while (current != NULL) {
        printf("|   P%d   ", current->pid);
        current = current->next;
    }
    printf("|\n");

    current = head;

    int currentTime = 0;
    while (current != NULL) {
        printf("%d        ", currentTime);
        currentTime += current->burstTime;
        current = current->next;
    }
    printf("%d\n", currentTime);

    printf("-----------------------------------------------------\n");
}


int main()
{
    Process *head = NULL;
    int numProcesses;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    for (int i = 1; i <= numProcesses; i++)
    {
        int arrivalTime, burstTime;
        printf("Enter arrival time and burst time for Process P%d: ", i);
        scanf("%d %d", &arrivalTime, &burstTime);
        insertProcess(&head, i, arrivalTime, burstTime);
    }

    displayGanttChart(head);

    printf("\n");
    
    displayTable(head);

    printf("\n");


    Process *current = head;
    while (current != NULL)
    {
        Process *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

