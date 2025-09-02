#include <stdio.h>
// Process structure
struct process {
    int pid, bt, wt, tt;     
};

void SJF(struct process p[], int n) {
    int i, j;
    struct process temp;

    // Sort the processes based on burst time (shortest job first)
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++) 
        {
            if (p[i].bt > p[j].bt)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    // Calculate waiting time and turnaround time for each process
    p[0].wt = 0;
    p[0].tt = p[0].bt;
    for (i = 1; i < n; i++)
    {
        p[i].wt = p[i - 1].tt;
        p[i].tt = p[i].wt + p[i].bt;
    }
    // Calculate average waiting time and turnaround time
    float avg_wt = 0, avg_tt = 0;
    for (i = 0; i < n; i++)
    {
        avg_wt += p[i].wt;
        avg_tt += p[i].tt;
    }
    avg_wt /= n;
    avg_tt /= n;

    // Print the table with process details and calculated times
    printf("PID\tBT\tWT\tTT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tt);
    }
    printf("Average WT: %.2f\n", avg_wt);
    printf("Average TT: %.2f\n", avg_tt);
}

int main() {
    int n, i;
    struct process p[10];

    // Read input data
    printf("Enter number of processes (max 10): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].pid = i + 1;
    }

    // Run the SJF algorithm
    SJF(p, n);

}
