#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
	char buf[128];

	while(1){
		printf("1 - Display\n2 - Edit\n3 - Logout\n");
		int x;
		printf("Please enter your option: ");
		scanf("%d",&x);
		
		FILE *fp = fopen("/home/F/x.txt","r+");
		if(fp == NULL){
			perror("Unable to open file - x\n");
			exit(1);
		}	
		FILE *fp1 = fopen("/home/S/y.txt","r+");
		if(fp1 == NULL){
			perror("Unable to open file - y\n");
			exit(1);
		}	
		FILE *fp2 = fopen("/home/H/z.txt","r+");
		if(fp2 == NULL){
			perror("Unable to open file - z\n");
			exit(1);
		}
		char v[4] = {'X','Y','Z'};
		int i = 0;	
		switch(x){
			case 1:
			        while(fgets(buf,sizeof(buf),fp) != NULL){
					printf("X - ");	
					fputs(buf,stdout);
				}
				fclose(fp);
			        while(fgets(buf,sizeof(buf),fp1) != NULL){
					printf("Y - ");	
					fputs(buf,stdout);
				}
				fclose(fp1);
			        while(fgets(buf,sizeof(buf),fp2) != NULL){
					printf("Z - ");	
					fputs(buf,stdout);
				}
				fclose(fp2);
				printf("\n");
				break;
			case 2:
				fp = freopen("/home/F/x.txt","w",fp);
				fp1 = freopen("/home/S/y.txt","w",fp1);
				fp2 = freopen("/home/H/z.txt","w",fp2);
				printf("Enter values accordingly:\n");
				char num[100];
				
				for(int j = 0;j < 4;j++){
					if(j!=0){
						printf("Enter the value of %c: ",v[i]);
						i++;
					}
					fgets(num,10,stdin);
					if(j != 0){
						if(j == 1)
							fputs(num,fp);
						if(j == 2)
							fputs(num,fp1);
						if(j == 3)
							fputs(num,fp2);
					}
					
				}	
				i=0;
				printf("\n");
				fclose(fp);	
				fclose(fp1);	
				fclose(fp2);	
				break;
			case 3:
				fclose(fp);
				fclose(fp1);
				fclose(fp2);
				exit(0);		
				break;
			default:
				printf("Please enter correct option!!");
				fclose(fp);
				fclose(fp1);
				fclose(fp2);
		}
	
	}
return 0;
}
