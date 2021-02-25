#include<stdio.h>
#include<string.h>

int main() {
    int i,x;
    char str[100];

    while(1) {
    printf("\n1. Enter 1 for Encryption\n2. Enter 2 for Decryption\n");
    int c;
    scanf("%d",&c);
    printf("\nEnter a string \n");
    scanf("%s",str);
    switch(c) {
        case 1:
            for(int i=0;(i<100 && str[i]!='\0');i++) {
                str[i]=str[i]-((8*5)-3);
            }
            printf("Encrypted string is: %s\n",str);
        break;
        case 2:
            for(int i=0;(i<100 && str[i]!='\0');i++) {
                str[i]=str[i]+((8*5)-3);
            }
            printf("Decrypted string is: %s\n",str);
        break;
        default:
            return 0;
        break;
    }
    }
    return 1;
}



