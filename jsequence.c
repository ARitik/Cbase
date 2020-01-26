#include<stdio.h>
#include<stdlib.h>

void decsort();

typedef struct jobs {
	int profit;
	int deadline;
	char id;
}jobs;

typedef struct resultarr {

	int space;
	char id;
}result;

jobs job[5];
result res[3]; /*ASSUMING HIGHEST DEADLINE TO BE 3*/



int main() {
	int i;
	printf("Enter job in order: profit , deadline , id(character)\n");
	for(i=0;i<5;i++) {
		printf("Job %d\n",i+1);
		scanf("%d",&job[i].profit);
		scanf("%d",&job[i].deadline);
		scanf(" %c",&job[i].id);
	}
//Jobs are sorted in decreasing order
	decsort();
	/*initializing results array to 0*/
	for(i=0;i<3;i++) {
		res[i].space=0;
	}

int p;
p=job[0].deadline-1;
res[p].id=job[0].id;
res[p].space=1;

for(i=1;i<5;i++) {
	p=job[i].deadline-1;
	if(res[p].space==0) {
		res[p].id=job[i].id;
		res[p].space=1;
	}
	else {
		while(--p>=0) {
			if(res[p].space==0) {
			res[p].id=job[i].id;
			res[p].space=1;
	}
		}
	}
}
printf("\nJob sequencing finished:\n");
for(i=0;i<3;i++) {
	printf("%c\t --> \t",res[i].id);
}

return 0;
}

void decsort() {

int i,j;
jobs temp;

for(i = 0; i < 5; i++)
{
  for(j = i + 1; j < (5 - 1); j++)
  {
    if(job[i].profit < job[j].profit)
    {
      /* Exchange two elements */
      job[i]=temp;
      job[i]=job[j];
      job[j]=temp;
    }
  }
}
}

