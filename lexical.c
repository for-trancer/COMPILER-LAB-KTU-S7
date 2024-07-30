#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char x[])
{
	if(strcmp(x,"int")==0||
 	 strcmp(x,"char")==0||
 	 strcmp(x,"printf")==0||
 	 strcmp(x,"scanf")==0||
 	 strcmp(x,"switch")==0||
 	 strcmp(x,"case")==0||
	 strcmp(x,"FILE")==0||
	 strcmp(x,"float")==0||
	 strcmp(x,"double")==0||
	 strcmp(x,"main")==0||
	 strcmp(x,"void")==0||
	 strcmp(x,"for")==0||
	 strcmp(x,"while")==0||
	 strcmp(x,"do")==0||
	 strcmp(x,"if")==0||
	 strcmp(x,"else")==0||
	 strcmp(x,"return")==0||
	 strcmp(x,"goto")==0||
	 strcmp(x,"break")==0||
	 strcmp(x,"continue")==0||
	 strcmp(x,"include")==0||
	 strcmp(x,"define")==0)
	 {
	 	return 1;
	 }
	 else
	 {
	 	return 0;
	 }
}

int isOperator(char x[])
{
	char ch=x[0];
	switch (ch) 
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
		case '!':
		case '&':
		case '|':
		case '=':
		case '<':
		case '>':
		    return 1; 
		default:
		    return 0; 
    	}
}

int isSymbol(char x[])
{
	char ch=x[0];
	switch (ch) 
	{
		case '"':
		case '\'':
		case '\\':
		case '{':
		case '}':
		case '#':
		case ';':
		case ':':
		case '[':
		case ']':
		case ',':
		case '.':
		case '>':
		case '<':
		case '(':
		case ')':
		    return 1; 
		default:
		    return 0; 
    	}
}


void main()
{
	FILE *fp;
	int i=0,j=0,k=0,size=0;
	char ch,a[100][100];

	fp = fopen("test.c","r");
	
	while((ch=fgetc(fp))!=EOF)
	{
		if(isalnum(ch))
		{
			a[i][j]=ch;
			j++;
		}
		else
		{
			if(j>0&&(isalnum(a[i][0])))
			{
				a[i][j]='\0';
				j=0;
				i++;
			}
			a[i][0]=ch;
			a[i][1]='\0';
			i++;
		}
	}
	fclose(fp);
	size=i;
	i=0;
	while(i<size)
	{
		if(a[i][0]=='\'')
		{
			printf("Character : %s\n",a[i+1]);
			i+=3;
		}
		else if(a[i][0]=='"')
		{
			printf("String : ");
			for(i++;a[i][0]!='"';i++)
			{
				printf("%s",a[i]);
			}
			printf("\n");
			i++;
		}
		else if(isdigit(a[i][0]))
		{
			printf("Constant : %s\n",a[i]);
			i++;
		}
		else if(isKeyword(a[i]))
		{
			printf("Keyword : %s\n",a[i]);
			i++;
		}
		else if(isalpha(a[i][0]))
		{
			printf("Identifier : %s\n",a[i]);
			i++;
		}
		else if(isOperator(a[i]))
		{
			if(isOperator(a[i+1]))
			{
				printf("Operator : %s%s\n",a[i],a[i+1]);
				i+=2;
			}
			else
			{
				printf("Operator : %s\n",a[i]);
				i++;
			}
		}
		else if(isSymbol(a[i]))
		{
			printf("Symbol : %s\n",a[i]);
			i++;
		}
		else if(a[i][0]!=' '&&a[i][0]!='\n')
		{
			// printf("Unknown Token: %s\n",a[i]);  line breaks not working
			i++;
		}
		else
		{
			i++;
		}
	}
}

/*

File Contents : test.c

#include <stdio.h>
void main()
{
	int c,d,x,i;
	char a,b;
	a='x';
	b='y';
	c=5;
	d=6;
	x=4+5;
	i++;
	printf("\n Sum : %d",x);
}

*/

