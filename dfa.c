#include <stdio.h>

// Change the switch according to your DFA 


int main()
{
	int s,i;
	char a[100];
	printf("Enter The String : ");
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!='a'&&a[i]!='b')
		{
			printf("Invalid Input!");
			return 0;
		}
	}
	
	s=0; // initial state 
	
	for(i=0;a[i]!='\0';i++)
	{
		switch(s)
		{
			case 0: if(a[i]=='a')
				s=0;
				else if(a[i]=='b')
				s=1;
				break;
			case 1: if(a[i]=='a')
				s=2;
				else if(a[i]=='b')
				s=1;
				break;
			case 2: if(a[i]=='a')
				s=0;
				else if(a[i]=='b')
				s=3;
				break;
		}
	}
	
	if(s==3)
	{
		printf("String Accepted!");
	}
	else
	{
		printf("String Rejected!");
	}
}
