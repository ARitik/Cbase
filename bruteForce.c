#include<stdio.h>
#include<string.h>

int bruteForce(char[],char[],int,int);

void main() {
    int size_pattern,size_text,found;
    printf("Enter size of text and pattern\n");
    scanf("%d%d",&size_text,&size_pattern);
    char text[size_text];
    char pattern[size_pattern];
    printf("Enter text :\t");
    scanf("%s",text);
    printf("\nEnter pattern to be matched :\t");
    scanf("%s",pattern);
    found=bruteForce(text,pattern,size_pattern,size_text);
    (found==-1)?printf("\nPattern does not exist within text"):printf("\nPattern exists at index %d\n",found);
}


int bruteForce(char text[],char pattern[],int size_p,int size_t) {
    int i,j=0;
    int found_index;
    for(i=0;i<size_t;i++) {
            for(j=0;j<size_p;j++) {
                found_index=i;
                if(text[i+j]!=pattern[j]) 
                break;
                if(j==size_p-1) {
                    return found_index;
                }
            }
        }
        return -1;
}
