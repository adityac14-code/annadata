#include <bits/stdc++.h> 
using namespace std;
struct process {
	int pid;
	int arrival_time;
	int burst_time;
	int start_time;
	int completion_time;
	int turnaround_time;
	int waiting_time;
	};
int main() {
	int x;
	struct process p[100];
	float avg_turnaround_time;
	float avg_waiting_time;
	int total_turnaround_time = 0;
	int total_waiting_time = 0;
	int burst_remaining[100];
	int is_completed[100];
	memset(is_completed,0,sizeof(is_completed));
	cout << setprecision(2) << fixed;
	cout<<"Enter the number of processes: ";
	cin>>x;
	for(int i = 0; i < x; i++) {
		 cout<<"Enter arrival time of the process "<<i+1<<": ";
		 cin>>p[i].arrival_time;
		 cout<<"Enter burst time of the process "<<i+1<<": ";
		 cin>>p[i].burst_time;
		 p[i].pid = i+1;
		 burst_remaining[i] = p[i].burst_time;
		 cout<<endl;
	}
	int current_time = 0;
	int completed = 0;
	int prev = 0;
	while(completed != x) {
		 int idx = -1;
		 int mn = 10000000;
		 for(int i = 0; i < x; i++) {
			  if(p[i].arrival_time <= current_time && is_completed[i] == 0) {
					if(burst_remaining[i] < mn) {
						 mn = burst_remaining[i];
						 idx = i;
					}
					if(burst_remaining[i] == mn) {
						 if(p[i].arrival_time < p[idx].arrival_time) {
							  mn = burst_remaining[i];
							  idx = i;
						 }
					}
			  }
		 }
		 if(idx != -1) {
			  if(burst_remaining[idx] == p[idx].burst_time) {
					p[idx].start_time = current_time;
						  }
			  burst_remaining[idx] -= 1;
			  current_time++;
			  prev = current_time;
			  
			  if(burst_remaining[idx] == 0) {
					p[idx].completion_time = current_time;
					p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
					p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
					total_turnaround_time += p[idx].turnaround_time;
					total_waiting_time += p[idx].waiting_time;
					is_completed[idx] = 1;
					completed++;
			  }
		 }
		 else {
				current_time++;
		 }  
	}
	int min_arrival_time = 10000000;
	int max_completion_time = -1;
	for(int i = 0; i < x; i++) {
		 min_arrival_time = min(min_arrival_time,p[i].arrival_time);
		 max_completion_time = max(max_completion_time,p[i].completion_time);
	}
	avg_turnaround_time = (float) total_turnaround_time / x;
	avg_waiting_time = (float) total_waiting_time / x;
	cout<<endl<<endl;
	cout<<"Process\t"<<"Arrival Time\t"<<"Burst Time\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<endl;
	for(int i = 0; i < x; i++) {
		 cout<<p[i].pid<<"\t"<<p[i].arrival_time<<"\t""\t"<<p[i].burst_time<<"\t""\t"<<p[i].start_time<<"\t"<<p[i].completion_time<<"\t"<<p[i].turnaround_time<<"\t"<<p[i].waiting_time<<"\t"<<"\n"<<endl;
	}
	cout<<"Average Turnaround Time = "<<avg_turnaround_time<<endl;
	cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;
	}