#include<stdio.h> 

void findWaitingTime(int processes[], int n, int bt[], int wt[]) 
{ 
    wt[0] = 0; 
    for (int i = 1; i < n; i++) 
        wt[i] = bt[i - 1] + wt[i - 1]; 
} 

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) 
{ 
    for (int i = 0; i < n; i++) 
        tat[i] = bt[i] + wt[i]; 
} 

void findavgTime(int processes[], int n, int bt[]) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
    findWaitingTime(processes, n, bt, wt); 
    findTurnAroundTime(processes, n, bt, wt, tat); 
    
    printf("Processes   Burst time   Waiting time   Turn around time\n"); 
    for (int i = 0; i < n; i++) 
    { 
        total_wt += wt[i]; 
        total_tat += tat[i]; 
        printf("       %d        %d              %d                %d\n", processes[i], bt[i], wt[i], tat[i]); 
    } 
    
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("\nAverage waiting time = %f\n", avg_wt);
    printf("Average turn around time = %f\n", avg_tat); 
    
    // Display Gantt Chart
    printf("\nGantt Chart:\n");
    printf("|");
    for (int i = 0; i < n; i++) 
    {
        printf("  P%d  |", processes[i]);
    }
    printf("\n");
    
    int time = 0;
    printf("0");
    for (int i = 0; i < n; i++) 
    {
        time += bt[i];
        printf("      %d", time);
    }
    printf("\n");
}

int main() 
{ 
    int processes[] = {1, 2, 3}; 
    int n = sizeof(processes) / sizeof(processes[0]); 
    int burst_time[] = {10, 5, 8}; 

    findavgTime(processes, n, burst_time); 
    return 0; 
} 
