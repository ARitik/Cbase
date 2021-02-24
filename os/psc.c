#include<stdio.h>

void swap(int *ptr1,int *ptr2) {
	int temp;
	temp = *ptr1;
	*ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {

	int n;
	printf("Enter number of processes -> \n");
	scanf("%d",&n);
	int p[n],pr[n],bt[n],wt[n],tt[n],avg_wt,avg_tt,sum_wt,sum_tt;
	printf("Enter Processes along with their Burst Times and Priority in sequence\n");

	for(int i=0;i<n;i++) {
		printf("\nEnter burst time and priority for Process P%d\t",i+1);
		scanf("%d%d",&bt[i],&pr[i]);
		p[i] = i+1;
	}

	//SORT PROCESSES BASED ON PRIORITY
	int sorted = 0;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			if(pr[j]<pr[i]) {
				swap(&pr[j],&pr[i]);
				swap(&bt[j],&bt[i]);
				swap(&p[j],&p[i]);
			}
		}
	}

	wt[0] = 0;
	tt[0] = wt[0] + bt[0];
	sum_wt = 0;
	sum_tt = tt[0];

	for(int i=1;i<n;i++) {
		wt[i] = wt[i-1]+bt[i-1];
		tt[i] = wt[i] + bt[i];
		sum_wt+= wt[i];
		sum_tt+= tt[i];
	}

	printf("P\tPR\tBT\tWT\tTT\n");
	for(int i=0;i<n;i++) {
		
		printf("%d\t%d\t%d\t%d\t%d\n",p[i],pr[i],bt[i],wt[i],tt[i]);
	}
	printf("Average Waiting Time: %0.02f ms\n", (float)sum_wt/n);
	printf("Average Turnaround Time: %0.02f ms\n", (float)sum_tt/n);

	return 0;
}