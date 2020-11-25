# include <bits/stdc++.h>
using namespace std;
#define f(a,b) for(int a=0;a<b;a++)

int ret_time(int x,int y){
	return (y-x);
}

void fcfs(int a,int b[],int c[]){
	int completion_time[a+1];
	completion_time[0] = b[0];
	f(i,a){
		if(b[i] > completion_time[i]){
			completion_time[i+1] = b[i] + c[i];
		}
		else{
			completion_time[i+1] = completion_time[i] + c[i];
		} 	 
	}
	int awt = 0,atat = 0;
	cout<<"+-----------------------------------------------------------------------------------------------------------+"<<endl;
	cout<<"| Process   Arrival Time   Burst Time   Completion Time   Turn Around Time   Waiting Time   Response Time |"<<endl;
	f(i,a){
		int tat = ret_time(b[i],completion_time[i+1]);
		cout<<"| P"<<i<<"\t\t"<<b[i]<<"\t\t"<<c[i]<<"\t\t"<<completion_time[i+1]<<"\t\t"<<tat<<"\t\t"<<tat-c[i]<<"\t\t\t"<<tat-c[i]<<"   |"<<endl;
		awt += tat-c[i];
		atat += tat;
	}
	cout<<"+-----------------------------------------------------------------------------------------------------------+"<<endl;
	cout<<"Average waiting time "<<awt*1.0/a<<endl;
	cout<<"Average turn around time "<<atat*1.0/a<<endl;
	cout<<endl<<endl;
}

void sjf(int a,int b[],int c[]){
	int mr = 1000000007;
	int completion_time[a];
	bool visited[a];
	f(i,a){
		visited[i] = false;
	}
	int process = 0,m=0,m1,p,prev=0,ara = 0;
	f(j,a){
		m1 = mr,p=0;
		f(i,a){
			if(!visited[i] and b[i] <= process){
				if(m1 > c[i]){
					m1 = c[i];
					m = b[i];
					p = i;
				}
			}
		}
		if(p==0 and m==0 and m1==mr){
			ara++;
		}
		else{
			visited[p] = true;
			completion_time[p] = ara + m1;
			ara = ara + m1;
		}
		process = ara;
	}
	int awt = 0,atat = 0;
	cout<<"+-----------------------------------------------------------------------------------------------------------+"<<endl;
	cout<<"| Process   Arrival Time   Burst Time   Completion Time   Turn Around Time   Waiting Time   Response Time |"<<endl;
	f(i,a){
		int tat = ret_time(b[i],completion_time[i]);
		cout<<"| P"<<i<<"\t\t"<<b[i]<<"\t\t"<<c[i]<<"\t\t"<<completion_time[i]<<"\t\t"<<tat<<"\t\t"<<tat-c[i]<<"\t\t\t"<<tat-c[i]<<"   |"<<endl;
		awt += tat-c[i];
		atat += tat;
	}
	cout<<"+-----------------------------------------------------------------------------------------------------------+"<<endl;
	cout<<"Average waiting time "<<awt*1.0/a<<endl;
	cout<<"Average turn around time "<<atat*1.0/a<<endl;
	cout<<endl<<endl;
}

void rr(int a,int b[],int c[]){
	int i,n,time,remain,temps=0,time_quantum=2;
	int wt=0,tat=0;
	int wat[a],tatt[a],rt[a];
	remain=a;

	f(i,a){
		rt[i]=c[i];
	}

	cout<<"\n\nProcess\t:Turnaround Time:Waiting Time\n\n";
	for(time=0,i=0;remain!=0;)
	{
		if(rt[i]<=time_quantum && rt[i]>0)
		{
			time += rt[i];
			rt[i]=0;
			temps=1;
		}

		else if(rt[i]>0)		{
			rt[i] -= time_quantum;
			time += time_quantum;
		}

		if(rt[i]==0 && temps==1){
			remain--;
			tatt[i] = time-b[i];
			wat[i] = time-b[i]-c[i];
			wt += time-b[i]-c[i];
			tat += time-b[i];
			temps=0;
		}

		if(i == n-1)
			i=0;
		else if(b[i+1] <= time)
			i++;
		else
			i=0;
	}
	cout<<"+-----------------------------------------------------------------------+"<<endl;
	cout<<"| Process   Arrival Time   Burst Time   Turn Around Time   Waiting Time |"<<endl;
	f(y,a){
		cout<<"| P"<<y<<"\t\t"<<b[y]<<"\t\t"<<c[y]<<"\t\t"<<tatt[y]<<"\t\t"<<wat[y]<<"       |"<<endl;
	}
	cout<<"+-----------------------------------------------------------------------+"<<endl;
	cout<<"Average waiting time "<<wt*1.0/a<<endl;
	cout<<"Average turn around time "<<tat*1.0/a<<endl;
	cout<<endl<<endl;

}

void caint(int a,int b[],int c[]){
	bool run = true;
	int d;
	while(run){
		cout<<"1. First Come First Serve"<<endl;
		cout<<"2. Shortest Job First"<<endl;
		cout<<"3. Round Robin"<<endl;
		cout<<"4. Exit"<<endl;
		cin>>d;
		switch(d){
			case 1:
				fcfs(a,b,c);
				break;
			case 2:
				sjf(a,b,c);
				break;
			case 3:
				rr(a,b,c);
				break;
			case 4:
				run = false;
				break;
		}
	}
}


int main(){
	int number_of_process;
	cout<<"Enter total number of process :";cin>>number_of_process;
	int arrival_time[number_of_process],burst_time[number_of_process];
	f(a,number_of_process){
		cout<<"Enter arrival time and brust time of process "<<a<<" :";
		cin>>arrival_time[a]>>burst_time[a];
	}
	caint(number_of_process,arrival_time,burst_time); 
}


/*

Output of the code
Enter total number of process :4
Enter arrival time and brust time of process 0 :0 5
Enter arrival time and brust time of process 1 :1 4
Enter arrival time and brust time of process 2 :2 2
Enter arrival time and brust time of process 3 :4 1
1. First Come First Serve
2. Shortest Job First
3. Round Robin
4. Exit
1
+-----------------------------------------------------------------------------------------------------------+
| Process   Arrival Time   Burst Time   Completion Time   Turn Around Time   Waiting Time   Response Time   |
| P0            0               5               5               5               0                       0   |
| P1            1               4               9               8               4                       4   |
| P2            2               2               11              9               7                       7   |
| P3            4               1               12              8               7                       7   |
+-----------------------------------------------------------------------------------------------------------+
Average waiting time 4.5
Average turn around time 7.5


1. First Come First Serve
2. Shortest Job First
3. Round Robin
4. Exit
2
+-----------------------------------------------------------------------------------------------------------+
| Process   Arrival Time   Burst Time   Completion Time   Turn Around Time   Waiting Time   Response Time   |
| P0            0               5               5               5               0                       0   |
| P1            1               4               12              11              7                       7   |
| P2            2               2               8               6               4                       4   |
| P3            4               1               6               2               1                       1   |
+-----------------------------------------------------------------------------------------------------------+
Average waiting time 3
Average turn around time 6


1. First Come First Serve
2. Shortest Job First
3. Round Robin
4. Exit
3


Process :Turnaround Time:Waiting Time

+-----------------------------------------------------------------------+
| Process   Arrival Time   Burst Time   Turn Around Time   Waiting Time |
| P0            0               5               12              7       |
| P1            1               4               10              6       |
| P2            2               2               4               2       |
| P3            4               1               3               2       |
+-----------------------------------------------------------------------+
Average waiting time 4.25
Average turn around time 7.25


1. First Come First Serve
2. Shortest Job First
3. Round Robin
4. Exit

*/
