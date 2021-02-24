#include<stdio.h>

int main() {
	int n;
	printf("Enter number of processes -> \n");
	scanf("%d",&n);
	int bt[n],wt[n],tt[n],avg_wt,avg_tt,sum_wt=0,sum_tt=0,rem_bt[n],tq;
	printf("Enter Time Quantum : ");
	scanf("%d",&tq);
	printf("\nEnter Processes along with their Burst Times in sequence\n");
	
	for(int i=0;i<n;i++) {
		printf("\nEnter burst time for Process P%d\t",i+1);
		scanf("%d",&bt[i]);
		rem_bt[i] = bt[i];
	}

	int time = 0;
	int done = 0; // bool done
	while(done!=n) {
		for(int i=0;i<n;i++) {
			if(rem_bt[i]==0)
				continue;

			if(tq<rem_bt[i]) {
				time+=tq;
				rem_bt[i]-=tq;
			}
			else {
				time+=rem_bt[i];
				wt[i]=time-bt[i];
				sum_wt+=wt[i];
				done++;
				rem_bt[i] = 0;
				tt[i] = bt[i] + wt[i];
				sum_tt+=tt[i];
			}
		}
	}

		printf("P\tBT\tWT\tTT\n");
	for(int i=0;i<n;i++) {
		printf("%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tt[i]);
	}
	printf("Average Waiting Time: %0.02f ms\n", (float)sum_wt/n);
	printf("Average Turnaround Time: %0.02f ms\n", (float)sum_tt/n);





	return 0;
}