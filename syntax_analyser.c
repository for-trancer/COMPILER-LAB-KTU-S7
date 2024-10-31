
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
	int i=0,j=0,limit,flag,count=0;
	FILE *fp;
	char ch,a[1000][100];
	fp=fopen("test.c","r");
	while((ch=fgetc(fp))!=EOF)
	{
		if(isalnum(ch))
		{
			a[i][j++]=ch;
		}
		else
		{
			if(i>0&&isalnum(a[i][0]))
			{
				a[i++][j]='\0';
				j=0;
			}
			a[i][0]=ch;
			a[i++][1]='\0';
		}
	}
	limit=i;
	flag=0;
	for(i=0;i<limit;i++)
	{
		if(strcmp(a[i],"for")==0)
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		flag=0;
		while(i<limit&&strcmp(a[i],")")!=0)
		{
			if(strcmp(a[i],"(")==0)
			{
				flag=1;
				break;
			}
			i++;
		}
		if(flag)
		{
			while(i<limit&&strcmp(a[i],")")!=0&&strcmp(a[i],"{")!=0)
			{
				if(strcmp(a[i],";")==0)
				{
					count++;
				}
				i++;
			}
			if(count==2)
			{
				flag=0;
				while(i<limit&&strcmp(a[i],"{")!=0)
				{
					if(strcmp(a[i],")")==0)
					{
						flag=1;
						break;
					}
					i++;
				}
				if(flag)
				{
					flag=0;
					while(i<limit&&strcmp(a[i],"}")!=0)
					{
						if(strcmp(a[i],"{")==0)
						{
							flag=1;
							break;
						}
						i++;
					}
					if(flag)
					{
						flag=0;
						while(i<limit)
						{
							if(strcmp(a[i],"}")==0)
							{
								flag=1;
								break;
							}
							i++;
						}
						if(flag)
						{
							printf("No Error's Found");
							return 0;
						}
						else
						{
							printf("Error : } not found!");
							return 0;
						}
					}
					else
					{
						printf("Error : { not found!");
					}
				}
				else
				{
					printf("Error : ) not found!\n");
					return 0;
				}
				
			}
			else
			{
				printf("Error : 2 semicolon's not found!\n");
				return 0;
			}
		}
		else
		{
			printf("Error : ( not found\n");
			return 0;
		}
	}
	else
	{
		printf("Error : for keyword not found!\n");
		return 0;
	}
}
