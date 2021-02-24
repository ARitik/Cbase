#include<stdio.h>

#define resources 3

int compare_arrays(int x[],int y[]) {
    for(int i=0;i<resources;i++) {
        if(x[i]>y[i]) 
            return 0;
    }
    return 1;
}

int main() {
    int size;
    printf("Enter the number of processes\t");
    scanf("%d",&size);
    int finish[size],available[resources],work[resources];
    int allocation[size][resources],need[size][resources],max[size][resources];
    for(int i=0;i<size;i++) {
        printf("\nEnter P%d Allocation of A B C: \t",i);
        scanf("%d%d%d",&allocation[i][0],&allocation[i][1],&allocation[i][2]);
        printf("\nEnter P%d Max of A B C: \t",i);
        scanf("%d%d%d",&max[i][0],&max[i][1],&max[i][2]);
        need[i][0] = max[i][0] - allocation[i][0];
        need[i][1] = max[i][1] - allocation[i][1];
        need[i][2] = max[i][2] - allocation[i][2];
    }
    printf("\nEnter Available of A B C: \t");
    scanf("%d%d%d",&available[0],&available[1],&available[2]);

    printf("\n Allocation Matrix is:\n");
    for(int i=0;i<size;i++) {
        for(int j=0;j<resources;j++)
            printf("%d ",allocation[i][j]);
        printf("\n");
    }

    printf("\n Max Matrix is:\n");
    for(int i=0;i<size;i++) {
        for(int j=0;j<resources;j++)
            printf("%d ",max[i][j]);
        printf("\n");
    }

     printf("\n Need Matrix is:\n");
    for(int i=0;i<size;i++) {
        for(int j=0;j<resources;j++)
            printf("%d ",need[i][j]);
        printf("\n");
    }

    for(int i=0;i<3;i++)
        work[i] = available[i];

    for(int i=0;i<size;i++) {
        finish[i] = 0; //false
    }
    int flag = 0;
    while(flag!=size) {
        for(int j=0;j<size;j++) {
            if(finish[j] == 0 && compare_arrays(need[j],work)) {
                work[0]+=allocation[j][0];
                work[1]+=allocation[j][1];
                work[2]+=allocation[j][2];
                printf("\n Process P%d is allocated\t Now available/work: %d %d %d",j,work[0],work[1],work[2]);
                finish[j] = 1;
                flag++;
        }
    }
    }
    printf("\n Available resources after work: %d %d %d",work[0],work[1],work[2]);
    return 0;
}