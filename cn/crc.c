#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int msglen,keylen,i,j;
    char input[100],temp[50],key[50],rem[50],quot[50],key1[50];
    printf("Enter the Data: ");
    gets(input);
    printf("\nEnter Key: ");
    gets(key);
    msglen = strlen(input);
    keylen = strlen(key);
    strcpy(key1,key);
    for(i=0;i<keylen-1;i++)
        input[i+msglen]='0';
    printf("%s\n",input);
    for(i=0;i<msglen;i++)
        temp[i]=input[i];
    printf("%s\n",temp);
    for(i=0;i<msglen;i++){
        quot[i] = temp[0];
        printf("\n : %c",quot[i]);
        if(quot[i]=='0')
            for(j=0;j<keylen;j++)
                key[j] = '0';
        else
            for(j=0;j<keylen;j++)
                key[j] = key1[j];
        for(j=keylen-1;j>0;j--){
            if(temp[j]==key[j])
                rem[j-1] = '0';
            else
                rem[j-1] = '1';
        }
        rem[keylen-1] = input[i+keylen];
        strcpy(temp,rem);

    }
    strcpy(rem,temp);
    printf("\nQuotient is: ");
    for(i=0;i<msglen;i++)
        printf("%c",quot[i]);
    printf("\nRemainder is :  ");
    for(i=0;i<keylen-1;i++)
        printf("%c",rem[i]);
    printf("\nThe final Data is : ");
    for(i=0;i<msglen;i++)
        printf("%c",input[i]);
    for(i=0;i<keylen-1;i++)
        printf("%c",rem[i]);
}
