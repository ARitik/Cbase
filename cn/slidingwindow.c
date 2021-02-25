#include<stdio.h>

int main() {
	int lw,lf,pointer=0;
	printf("Enter window size: \n");
	scanf("%d",&lw);
	printf("Enter number of frames to be sent \n");
	scanf("%d",&lf);
	int frames[lf];
	printf("Enter the frames\n");
	for(int i=0;i<lf;i++)
		scanf("%d",&frames[i]);
	for(int i=0;i<lf;i+=lw) {
		for(int j=0;j<lw;j++) {
			if(pointer==lf)
				break;
			printf("%d\t",frames[pointer++]);	
		}
		printf("\nAcknowledgement recieved from the reciever for sent data\n");
	}
}