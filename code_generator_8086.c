#include <stdio.h>


void main()
{
	char input[10][10];
	int n;
	
	printf("Enter The Number Of Expressions : ");
	scanf("%d",&n);
	
	printf("Enter The Expressions : ");
	
	for(int i=0;i<n;i++)
	{
		scanf("%s",&input[i]);
	}
	
	for(int k=0;k<n;k++)
	{
		char s=input[k][3];
		switch(s)
		{
			case '+':
				printf("\nMOV R%d,%c\n",k+1,input[k][2]);
				printf("ADD R%d,%c\n",k+1,input[k][4]);
				printf("MOV %c,R%d\n",input[k][0],k+1);
				break;
			case '-':
				printf("\nMOV R%d,%c\n",k+1,input[k][2]);
				printf("SUB R%d,%c\n",k+1,input[k][4]);
				printf("MOV %c,R%d\n",input[k][0],k+1);
				break;
			case '*':
				printf("\nMOV R%d,%c\n",k+1,input[k][2]);
				printf("MUL R%d,%c\n",k+1,input[k][4]);
				printf("MOV %c,R%d\n",input[k][0],k+1);
				break;
			default:
				printf("\nExit!");
				break;
				
		}
	}
}
