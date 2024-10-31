#include <stdio.h>
#include <string.h>

// recursive decent parser for the grammar
// E->iE'
// E'->+iE'|null

int i=0,error_flag=0;
char str[100],look_ahead;

char get_ch()
{
	return str[++i];
}

void match(char ch)
{
	if(ch==look_ahead)
	{
		look_ahead=get_ch();
	}
}

void E_()
{
	if(look_ahead=='+')
	{
		match('+');
		match('i');
		E_();
	}
	else
	return ;
}

void E()
{
	if(look_ahead=='i')
	{
		match('i');
		E_();
	}
	else
	{
		printf("Error Expected Character Is 'i' But Encountered %c\n",look_ahead);
		error_flag=1;
		return;
	}
}







void main()
{
	printf("Enter The String : ");
	scanf("%s",str);
	int len=strlen(str);
	str[len]='$';
	look_ahead=str[i]; // setting the initial value of look ahead
	E(); 
	if(look_ahead=='$')
	{
		printf("Parsing Sucessfull!");
	}
	else
	{
		printf("Parsing Error!");
	}
}
