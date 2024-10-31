%{
#include <stdio.h>
int vow_count=0;
int const_count=0;
%}

vowel [aeiouAEIOU]
consonant [bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]

%%

{vowel} {vow_count++;}
{consonant} {const_count++;}

%%

int main()
{
	yylex();
	printf("Vowels:%d And Consonants:%d\n",vow_count,const_count);
	return 0;
}

int yywrap()
{
	return -1;
}
