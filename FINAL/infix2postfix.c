#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "arraystackadt.h"

bool isoperator(char token)
{
    switch(token)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return true;
    }
    return false;
}

int priority(char token)
{  
    if(token=='^')
        return 3;
    else if(token=='*' || token=='/')
        return 2;
    else if(token=='+' || token=='-')
        return 1;
    return 0;
}

int main()
{
    AST *ph;
    char postfix[25], token;
    char *pt;
    int i = 0;
    ph = createstack();
    printf("Enter Infix expression ('0' at end)\n");
    while((token = getchar()) != '0')
    {
        if(token == '(')
        {
            pt=(char*)malloc(sizeof(char));
             *pt=token;
             pushstack(ph,pt);
        }
        else if(token == ')')
        {
           pt = (char*)popstack(ph);
            while(*pt != '(')
            {
                postfix[i++] = *pt;
                free(pt);
                pt = (char*)popstack(ph);
            }
            free(pt); // Free the '(' character
        }
        else if(isoperator(token))
        {
            pt = (char*)stacktop(ph);
            while(!stackempty(ph) && priority(token) <= priority(*pt))
            {
                pt = (char*)popstack(ph);
                postfix[i++] = *pt;
                free(pt);
                pt = (char*)stacktop(ph);
            }
            pt = (char*)malloc(sizeof(char));
            *pt = token;
            pushstack(ph, (void*)pt);
        }
        else
            postfix[i++] = token;
    }

    // Pop any remaining operators from the stack

    while(!stackempty(ph))
    {
        pt = (char*)popstack(ph);
        postfix[i++] = *pt;
        free(pt);
    }
    postfix[i] = '\0';
    printf("Postfix expression: %s", postfix);
    destroystack(ph);
    return 0;
}                                           

