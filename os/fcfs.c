 #include<stdio.h>

int main() {
	int n;
	printf("Enter number of processes -> \n");
	scanf("%d",&n);
	int bt[n],wt[n],tt[n],avg_wt,avg_tt,sum_wt,sum_tt;
	printf("Enter Processes along with their Burst Times in sequence\n");

	printf("Enter burst time for Process P1\t");
	scanf("%d",&bt[0]);
	wt[0] = 0;
	tt[0] = wt[0] + bt[0];
	sum_wt = 0;
	sum_tt = tt[0];

	for(int i=1;i<n;i++) {
		printf("\nEnter burst time for Process P%d\t",i+1);
		scanf("%d",&bt[i]);
		wt[i] = wt[i-1]+bt[i-1];
		tt[i] = wt[i] + bt[i];
		sum_wt+= wt[i];
		sum_tt+= tt[i];
	}
		printf("P\tBT\tWT\tTT\n");
	for(int i=0;i<n;i++) {
		printf("%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tt[i]);
	}
	printf("Average Waiting Time: %0.02f ms\n", (float)sum_wt/n);
	printf("Average Turnaround Time: %0.02f ms\n", (float)sum_tt/n);
	return 0;
}

// p1 - 16 p2 -3 p3 - 3