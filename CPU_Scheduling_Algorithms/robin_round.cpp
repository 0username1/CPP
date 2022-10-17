#include<iostream>
using namespace std;
void Avg_wt(int processes[],int n,int bt[],int wt[],int quantum)
{
	// Make a copy of burst times bt[] to store remaining
	// burst times.
	int rem_bt[n];
	for (int i=0;i<n;i++) rem_bt[i] = bt[i];
	int t = 0; // Current time
	// Keep traversing processes in round robin manner until all of them are not done.
	while (1)
	{
		bool done = true;
		// Traverse all processes one by one repeatedly
		for (int i=0;i<n;i++)
		{
			// If burst time of a process is greater than 0 then only need to process further
			if (rem_bt[i] > 0)
			{
				done = false; // There is a pending process
				if (rem_bt[i] > quantum)
				{
					// Increase the value of t i.e. shows how much time a process has been processed
					t += quantum;
					// Decrease the burst_time of current process by quantum
					rem_bt[i] -= quantum;
				}
				// If burst time is smaller than or equal to quantum. Last cycle for this process
				else
				{
					// Increase the value of t i.e. shows how much time a process has been processed
					t = t + rem_bt[i];
					// Waiting time is current time minus time used by this process
					wt[i] = t - bt[i];
					// As the process gets fully executed make its remaining burst time = 0
					rem_bt[i] = 0;
				}
			}
		}
		// If all processes are done
		if (done == true)
		break;
	}
    int total_wt = 0;
   for(int i=0;i<n;i++) total_wt = total_wt + wt[i];
   cout<<"Average waiting time: "<< (float)total_wt / (float)n;
}

void Avg_tat(int processes[],int n,int bt[],int wt[],int tat[])
{
    int total_tat = 0;
	for (int i = 0; i < n ; i++) tat[i] = bt[i] + wt[i];
   for(int i=0;i<n;i++) total_tat = total_tat + tat[i];
   cout<<"\nAverage turn around time: "<< (float)total_tat / (float)n;
}

int main()
{
    int n,processes[50],bt[50],wt[50],tat[50],total_wt,total_tat,quantum;
    cout<<"Enter no.of processes: ";
    cin>>n;
    cout<<"Enter processes: ";
    for(int i=0;i<n;i++) cin>> processes[i];
    cout<<"Enter their respective burst times: ";
    for(int i=0;i<n;i++) cin>> bt[i];
    cout<<"Enter time quantum: ";
    cin>> quantum;
	Avg_wt(processes,n,bt,wt,quantum);
    Avg_tat(processes,n,bt,wt,tat);
	return 0;
}

