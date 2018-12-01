#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char stack[MAX];
int top=-1;
void push(char item)
{
    stack[++top]=item;
}
char pop()
{
    return stack[top--];
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int checkParentheses(char exp[])
{
    int i;
    char x;
    for(i=0; i<strlen(exp); i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            {
                push(exp[i]);
                continue;         // no need to check the remaining conditions of closing brackets
            }

    if(isEmpty())
        return 0;

          if(exp[i]==')')
         {
            x=pop();
            if(x!='(')
                return 0;
         }
          else if(exp[i]=='}')
        {
            x=pop();
            if(x!='{')
                return 0;
        }
          else if(exp[i]==']')
        {
             x=pop();
             if(x!='[')
                return 0;
        }
    }

    if(isEmpty())
        return 1;
    else
        return 0;
}
int main()
{
    char exp[MAX];
    printf("\nEnter the expression:- ");
    gets(exp);
    if(checkParentheses(exp))
        printf("\nBalanced!!\n");
    else
        printf("\nNot-Balanced!!\n");
    return 0;
}

