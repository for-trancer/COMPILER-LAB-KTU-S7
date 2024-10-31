#include <stdio.h>
#include <string.h>


char stack[100],input[100];
int top=0;

char pre[][6]={
// i + * $ ( )
{' ','>','>','>',' ','>'}, // i
{'<','>','<','>','<','>'}, // +
{'<','>','>','>','<','>'}, // *
{'<','<','<',' ','<',' '}, // $
{'<','<','<',' ','<','='}, // (
{' ','>','>','>',' ','>'}, // )
};

int value(char ch)
{
	switch(ch)
	{
		case 'i':return 0;
		case '+':return 1;
		case '*':return 2;
		case '$':return 3;
		case '(':return 4;
		case ')':return 5;
		default: return 0;
		break;
	}
}

void push(char ch)
{
	stack[++top]=ch;
}

char pop()
{
	return stack[top--];
}


void main()
{
	int len,j=0;
	char a,b,c;
	
	printf("Enter The Input String : ");
	scanf("%s",input);
	len=strlen(input);
	
	input[len]='$';
	input[len+1]='\0';
	stack[top]='$';
	
	while(1)
	{
		a=stack[top];
		b=input[j];
		c=pre[value(a)][value(b)];
		
		// printf("%c %c %c\n",a,b,c); use this for debugging
		
		if(a=='$'&&b=='$')
		{
			printf("Parsing Sucessfull!");
			break;
		}
		else if(c=='<'||c=='=')
		{
			push(c);
			push(b);
			j++;
		}
		else if(c=='>')
		{
			while(top!=0&&stack[top]!='<')
			{
				pop();
			}
			if(stack[top]=='<')
			{
				pop();
			}
		}
		else
		{
			printf("Parsing Error!");
			break;
		}
	}
}

