#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Recursive descent parser for the grammar
// E->TE'
// E'->+TE' | null
// T->FT'
// T'->*FT' | null
// F->(E) | id

char str[100], look_ahead;
int i = 0;
bool error = false; 

void E(); 

void match(char ch) {
    if (look_ahead == ch) {
        look_ahead = str[++i]; 
    } else {
        printf("\nError! Expected '%c' but found '%c'\n", ch, look_ahead);
        error = true; 
    }
}

void F() {
    if (look_ahead == '(') {
        match('(');
        E();
        match(')');
    } else if (look_ahead == 'i') { 
        match('i');
    } else {
        printf("\nError in F! Unexpected character: '%c'\n", look_ahead);
        error = true; 
    }
}

void T_() {
    if (look_ahead == '*') {
        match('*');
        F();
        if (!error) T_();
    }
}

void T() {
    F();
    if (!error) T_();
}

void E_() {
    if (look_ahead == '+') {
        match('+');
        T();
        if (!error) E_();
    }
}

void E() {
    T();
    if (!error) E_();
}

int main() {
    printf("Enter The Input String: ");
    scanf("%s", str);
    int len = strlen(str);
    str[len] = '$'; // Append end symbol
    str[len + 1] = '\0';
    look_ahead = str[i];
    E();
    if (look_ahead == '$' && !error) {
        printf("\nParsing Successful!\n");
    } else if (!error) {
        printf("\nError! Unexpected end of input.\n");
    } else {
        printf("\nParsing Failed!\n");
    }
    return 0;
}
