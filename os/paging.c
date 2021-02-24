#include<stdio.h>

int main() {
    int ms,ps,nop,np,offset,rempages,x,y,pa;
    int s[10],fno[10][10];
    printf("\nEnter Memory Size and Process Size");
    scanf("%d%d",&ms,&ps);
    nop = ms/ps;
    printf("\nNumber of pages is %d",nop);
    printf("\nEnter number of processes");
    scanf("%d",&np);
    rempages = nop;
    for(int i=0;i<np;i++) {
        printf("Enter number of pages required for Process %d\n",i);
        scanf("%d",&s[i]);

        if(s[i]>rempages) {
            printf("\nMemory is full!");
            break;
        }
        
        rempages-=s[i];
        printf("\nEnter Page Table for Process %d",i);


        for(int j=0;j<s[i];j++) {
            scanf("%d",&fno[i][j]);
        }
    }

    printf("\nEnter Logical Address to find Physical Address");
    printf("\nEnter process no. , page no. and offset");
    scanf("%d%d%d",&x,&y,&offset);

    if(x>np || y>s[x] || offset>=ps) 
        printf("\nInvalid!");
    else {
        printf("fno : %d ps : %d offset : %d",fno[x][y],ps,offset);
        pa=(fno[x][y]*ps)+offset;
        printf("\nPhysical Address : %d",pa);
    }
    
    return 0;

}