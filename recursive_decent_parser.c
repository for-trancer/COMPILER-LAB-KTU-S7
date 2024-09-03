#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[1000];
int i=0;

void E()
{
	T();
	EPRIME();
}

void T()
{
	F();
	TPRIME();
}

void F()
{
	if(a[i]=='(')
	{
		ADVANCE();
		E();
		if(a[i]==')')
		{
			ADVANCE();
		}
		else
		{
			printf("Parsing Error!");
			exit(0);
		}
	}
	else if(a[i]=='i')
	{
		ADVANCE();
	}
	else
	{
		printf("Parsing Error!");
		exit(0);
	}
}

void ADVANCE()
{
	if(a[i]!='\0')
	{
		i++;
	}
}

void EPRIME()
{
	if(a[i]=='+')
	{
		ADVANCE();
		T();
		EPRIME();
	}
}

void TPRIME()
{
	if(a[i]=='*')
	{
		ADVANCE();
		F();
		TPRIME();
	}
}



int main()
{
	printf("Enter The Input String : ");
	gets(a);
	E();
	if(a[i]!='\0')
	{
		printf("Parsing Error!");
		exit(0);
	}
	else
	{
		printf("No Errors found. Parsing complete!");
	}
}
