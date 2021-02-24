#include<stdio.h>
#include<string.h>

struct fileTable {
    char name[20];
    int sb,nob;
}ft[30];

int main() {
    int n,i;
    char s[20];
    printf("\nEnter no. of files");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%s",ft[i].name);
        scanf("%d",&ft[i].sb);
        scanf("%d",&ft[i].nob);
    }
    printf("\nEnter file to be searched");
    scanf("%s",s);
    for(i=0;i<n;i++) {
        if(strcmp(s,ft[i].name)==0) {
            break;
        }   
    }
    if(i==n) 
            printf("\nFile not found!");
        else {
            printf("\nFILE NAME\tSTARTING BLOCK\tNUMBER OF BLOCKS\tBLOCKS OCCUPIED");
            printf("\n%s\t%d\t%d",ft[i].name,ft[i].sb,ft[i].nob);
            for(int j=0;j<ft[i].nob;j++)
                printf("%d ",ft[i].sb+j);
        }
    return 0;
}