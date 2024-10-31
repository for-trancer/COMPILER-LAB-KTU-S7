#include <stdio.h>
#include <string.h>

char input[100],m[100],stack[100],x;
int top=0;

int isop(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
		case '*':
		case '\\':
		case '%':
		case '(':
		case ')':
		case '=':
		case '^':
			return 1;
		default:
			return 0;
	}
}

int prio(char ch)
{
	switch(ch)
	{
		case '(':return 0;
		case '_':return 1;
		case '^':return 2;
		case '%':return 3;
		case '/':return 4;
		case '*':return 5;
		case '+':return 6;
		case '-':return 7;
		case ')':return 8;
		case '=':return 9;
		case '$':return 10;
		default:return 11;
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
	char first,second;
	int k=0,i;
	printf("Enter The Expression : ");
	scanf("%s",input);
	stack[top]='$';
	for(i=0;i<strlen(input);i++)
	{
		if(input[i]=='-'&&(i==0||isop(input[i-1])))
		input[i]='_';
	}
	for(i=0;i<strlen(input);i++)
	{
		if(isop(input[i]))
		{
			if(top<=0||stack[top]=='('||input[i]=='(')
			{
				push(input[i]);
			}
			else if(input[i]==')')
			{
				while((x=pop())!='(')
				{
					m[k++]=x;
				}
			}
			else if(prio(input[i])<prio(stack[top]))
			{
				push(input[i]);
			}
			else
			{
				m[k++]=pop();
				push(input[i]);
			}
		}
		else
		{
			m[k++]=input[i];
		}
	}
	
	while((x=pop())!='$')
	{
	m[k++]=x;
	}
	m[k++]='\0';
	
	printf("Postfix Form : ");
	puts(m);
	
	printf("\nOP\tFIRST\tSECOND\tRESULT\n");
	
	for(i=0,x='0';m[i]!='\0';i++)
	{
		if(!isop(m[i]))
		{
			push(m[i]);
		}
		else
		{
			if(m[i]=='_'||m[i]=='=')
			{
				second='_';
			}
			else
			{
				second=pop();
			}
			first=pop();
			if(m[i]=='_')
			{
				printf("UMINUS\t%c\t%c\t%c\n",first,second,x);
				push(x++);
			}
			else
			{
				if(m[i]=='=')
				{
					char temp=pop();
					printf("%c\t%c\t%c\t%c\n",m[i],first,second,temp);
				}
				else
				{
					printf("%c\t%c\t%c\t%c\n",m[i],first,second,x);
					push(x++);
				}
			}
		}
	}
}
