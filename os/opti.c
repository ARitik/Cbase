#include<stdio.h>

int arrayContains(int a[],int item,int len) {
	for(int i=0;i<len;i++) {
		if(a[i] == item) 
			return 1;
	}
	return 0;
}

int computeDistance(int x,int ref[],int lref,int si) {
	int dis = 0;
	for(int i=si;i<lref;i++) {
		if(x==ref[i])
			break;
		dis++;
	}
	return dis;
}

int determinePointer(int q[],int lq,int ref[],int lref,int si) {
	int max = -1,dis,ind;
	for(int i=0;i<lq;i++) {
		dis = computeDistance(q[i],ref,lref,si);
		if(dis>max) {
			max=dis;
			ind=i;
		}
	}
	return ind;
}

int main() {
	int lref,lq,pg_fault=0,isFull=0,tc=0;
	printf("\nEnter length of reference string : ");
	scanf("%d",&lref);
	printf("\nEnter length of page queue : ");
	scanf("%d",&lq);
	int ref[lref],q[lq];
	printf("\nEnter elements of reference string : \n");
	for(int i=0;i<lref;i++)
		scanf("%d",&ref[i]);
	for(int i=0;i<lq;i++)
		q[i]=-1;
	int ptr=0;
	for(int i=0;i<lref;i++) {
		if(tc!=lq) {
			ptr = determinePointer(q,lq,ref,lref,i);
			q[ptr] = ref[i];
			pg_fault++;
			tc++;

		}
		else {
			if(!arrayContains(q,ref[i],lq)) {
			pg_fault++;
			q[ptr++] = ref[i];
			ptr%=lq;
			
			}
		}
		for(int k=0;k<lq;k++)
			printf("%d\t",q[k]);
		printf("\n");
	}
	printf("\n Number of page faults is :\t %d",pg_fault);

	return 0;
}