#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int i = 0, j = 0, size, flag = 0, count = 0;
    char ch, a[100][100];
    FILE *fp;
    fp = fopen("test.c", "r");
	
    while ((ch = fgetc(fp)) != EOF) 
    {
        if (isalnum(ch)) {
            a[i][j] = ch;
            j++;
        } 
        else {
            if (j > 0 && isalnum(a[i][0])) {
                a[i][j] = '\0';
                j = 0;
                i++;
            }
            a[i][0] = ch;
            a[i][1] = '\0';
            i++;
        }
    }
    
    fclose(fp);
    size = i;

    flag = 0;
    i = 0;

    while (i < size) {
        if (strcmp(a[i], "for") == 0) { // check for keyword 'for'
            flag = 1;
            printf("%s : found\n", a[i]);
            break;
        }
        i++;
    }

    if (flag) {
        flag = 0;
        i++; // move to next token after 'for'

        while (i < size && strcmp(a[i], ")") != 0) {
            if (strcmp(a[i], "(") == 0) { // check for opening '(' parenthesis
                flag = 1;
                printf("%s : found\n", a[i]);
                break;
            }
            i++;
        }

        if (flag) {
            flag = 0;
            i++; // move to next token after '('

            while (i < size && strcmp(a[i], ")") != 0) {
                if (strcmp(a[i], ";") == 0) { // check for number of ';' semicolons
                    count++;
                }
                i++;
            }

            if (count == 2) { // checking there are two semicolons
                flag = 1;
                printf("2 semicolons : found\n");
            }

            if (flag) {
                flag = 0;
                i++; // move to next token after the second ';'

                while (i < size && strcmp(a[i], "{") != 0) {
                    if (strcmp(a[i], ")") == 0) { // check for closing ')' parenthesis
                        printf("%s : found\n", a[i]);
                        flag = 1;
                        break;
                    }
                    i++;
                }

                if (flag) {
                    flag = 0;
                    i++; // move to next token after ')'

                    while (i < size && strcmp(a[i], "}") != 0) {
                        if (strcmp(a[i], "{") == 0) { // check for '{' brace
                            flag = 1;
                            printf("%s : found\n", a[i]);
                            break;
                        }
                        i++;
                    }

                    if (flag) {
                        flag = 0;
                        i++; // move to next token after '{'

                        while (i < size) {
                            if (strcmp(a[i], "}") == 0) { // check for '}' brace
                                flag = 1;
                                printf("%s : found\n", a[i]);
                                break;
                            }
                            i++;
                        }

                        if (flag) {
                            printf("No Errors Found!\n");
                        } else {
                            printf("Error: } Braces Not Found!\n");
                        }
                    } else {
                        printf("Error: { Braces Not Found!\n");
                    }
                } else {
                    printf("Error: ) Parenthesis Not Found!\n");
                }
            } else {
                printf("Error: Minimum 2 semicolons are required\n");
            }
        } else {
            printf("Error: ( Parenthesis Not Found!\n");
        }
    } else {
        printf("for keyword not found!\n");
    }

    return 0;
}

// test.c 
/* 
#include <stdio.h>


void main()
{
	for(i=0;i<n;i++)
		printf("%d",i);
	}
} 
*/
