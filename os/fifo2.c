#include<stdio.h>

int main() {
    int i,j,k,pf=0,count=0,rs[25],m[10],n,f;
    printf("\nEnter length of reference string ");
    scanf("%d",&n);
    printf("\nEnter elements of ref string \n");
    for(i=0;i<n;i++) {
        scanf("%d",&rs[i]);
    }
    printf("\nEnter length of frame ");
    scanf("%d",&f);
    for(i=0;i<f;i++)
        m[i]=-1;
    printf("\nPage Replacement is \n");
    for(i=0;i<n;i++) {
        for(k=0;k<f;k++) {
            if(m[k]==rs[i])
                break;
        }
        if(k==f) {
            m[count++] = rs[i];
            pf++;
        }
        for(j=0;j<f;j++)
            printf("\t%d",m[j]);
        if(k==f)
            printf("\t PF No. %d",pf);
        printf("\n");
        if(count==f)
            count=0;
    }

    return 0;
}