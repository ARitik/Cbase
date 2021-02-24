#include<stdio.h>

int main() {
	int f,n,next=1,pf=0,rs[25],m[10],flag[25],count[10],min;
	scanf("%d",&n);
	printf("\nEnter resources\n");
	for(int i=0;i<n;i++) {
		scanf("%d",&rs[i]);
		flag[i] = 0;
	}
	printf("\nEnter number of frames\n");
	scanf("%d",&f);
	for(int i=0;i<f;i++) {
		m[i] = -1;
		count[i] = 0;
	}

	printf("\nLRU Page Replacement\n");
	for(int i=0;i<n;i++) {
		for(int j=0;j<f;j++) {
			if(m[j]==rs[i]) {
				flag[i]=1;
				count[j]=next;
				next++;
			}
		}
		if(flag[i]==0) {
			if(i<f) {
				m[i]=rs[i];
				count[i] = next;
				next++;
			}
			else {
				min=0;
				for(int j=1;j<f;j++)
					if(count[min]>count[j]) 
						min=j;
				m[min]=rs[i];
				count[min]=next;
				next++;

			}
			pf++;
		}
		for(int j=0;j<f;j++) {
			printf("%d\t",m[j]);
		}
		if(flag[i]==0)
			printf("\tPage Fault : %d\n",pf);
	}

	




	return 0;
}