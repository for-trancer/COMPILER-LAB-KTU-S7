%{
#include <stdio.h>
%}

identifier [a-zA-Z][a-zA-Z0-9]*
operator "+"|"-"|"/"
symbols ","|"("|")"

%%
#.* {printf("\n%s is a preprocessor directive",yytext);}
int |
float |
char |
double |
while |
for |
struct |
typedef |
do |
if |
break |
continue |
void |
switch |
return |
else |
goto {printf("\n\t%s is a keyword",yytext);}
{identifier}(\[[0-9]*\])? {printf("\n %s IDENTIFIER",yytext);}
= {printf("\n\t %s is an ASSIGNMENT OPERATOR",yytext);}
\<= |
\>= |
\< |
== |
\> {printf("\n\t%s is a RELATIONAL OPERATOR",yytext);}
{operator} {printf("\n\t%s is a BINARY OPERATOR",yytext);}
{symbols} {printf("\n\t%s is a SYMBOL",yytext);}
\".*\" {printf("\n\t %s is a STRING",yytext);}
[0-9]+ {printf("\n %s is a NUMBER ",yytext);}
%%

int main(int argc, char **argv)
{
	FILE *file;
 	file=fopen("a.c","r");
 	if(!file)
 	{
  		printf("could not open the file");
 		exit(0);
 	}
 	yyin=file;
 	yylex();
 	printf("\n");
	return(0);
}

int yywrap()
{
	return(1);
}
