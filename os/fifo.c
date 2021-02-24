#include<stdio.h>

int arrayContains(int a[],int item,int len) {
	for(int i=0;i<len;i++) {
		if(a[i] == item) 
			return 1;
	}
	return 0;
}

int main() {
	int lref,lq,pg_fault=0,isFull=0,tc=0;
	printf("\nEnter length of reference string : ");
	scanf("%d",&lref);
	printf("\nEnter length of page queue : ");
	scanf("%d",&lq);
	int ref[lref],q[lq];
	printf("\nEnter elements of reference string :");
	for(int i=0;i<lref;i++)
		scanf("%d",&ref[i]);
	for(int i=0;i<lq;i++)
		q[i]=-1;
	int ptr=0;
	for(int i=0;i<lref;i++) {
		if(tc!=lq) {
			q[ptr] = ref[i];
			pg_fault++;
			tc++;
			ptr++;
			ptr%=lq;

		}
		else {
			if(!arrayContains(q,ref[i],lq)) {
				for(int j=0;j<lq;j++)
				printf("%d\t",q[j]);
			printf("\n");
			pg_fault++;
			q[ptr++] = ref[i];
			ptr%=lq;
			
			}
		}
	}
	printf("\n Number of page faults is :\t %d",pg_fault);

	return 0;
}

/*

1)Bankers algorithm [x]
2)FCFS [x]
3)Round Robin [x]
4)Paging [x]
5)sjf [x]
6)sstf [x]
7)FIFO [x]
8)best fit [x]
9)LRU 
10)sequential file allocation [x]
11)Optimal 
12)Priority [x]
13)worst fit [x]

*/