#include <stdio.h>

// Function to sort processes based on burst time
void sortProcesses(int n, int processes[], int bt[], int at[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                // Swap burst times
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap arrival times
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap process IDs
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// Function to find waiting time for all processes
void findWaitingTime(int n, int bt[], int wt[]) {
    wt[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
}

// Function to find turnaround time for all processes
void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to print Gantt chart
void printGanttChart(int processes[], int n, int bt[]) {
    printf("\nGantt Chart:\n");
    printf("|");
    for (int i = 0; i < n; i++) {
        printf("  P%d  |", processes[i]);
    }
    printf("\n");

    int time = 0;
    printf("0");
    for (int i = 0; i < n; i++) {
        time += bt[i];
        printf("      %d", time);
    }
    printf("\n");
}


int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], bt[n], wt[n], tat[n], at[n];

    // Input burst times and process IDs
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sort processes based on burst time
    sortProcesses(n, processes, bt, at);

    // Calculate waiting times
    findWaitingTime(n, bt, wt);

    // Calculate turnaround times
    findTurnAroundTime(n, bt, wt, tat);

    // Print results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    // Calculate and print average waiting and turnaround time
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

    // Print Gantt chart
    printGanttChart(processes, n, bt);

    return 0;
}
