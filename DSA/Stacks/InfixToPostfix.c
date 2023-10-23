// A simple C program to convert Infix expression to Postfix
#include <stdio.h>
#include <string.h>

#define size 100

char stack[size];
int top = -1;

void push(char ch)
{
    if (top >= size - 1)
        return;
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int priority(char ch) //add some more
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;   
    default:
        return 0;
    }
}

void infixToPrefix(char *str)
{
    char expression[size];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
            push(str[i]);
        else if (str[i] == ')')
        {
            while (top > -1)
            {
                expression[j++] = pop();
                if (stack[top] == '(')
                {
                    pop();
                    break;
                }    
            }

        }
        else if((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^')) // add some more
        {
            //if((top == -1) || (stack[top] == '('))
            //    push(str[i]);
            if ((priority(str[i]) > priority(stack[top])) && (top >= -1))
                push(str[i]);
            else if ((priority(str[i]) < priority(stack[top])) && (top > -1))
            {
                while ((priority(str[i]) < priority(stack[top])) && (top > -1))
                    expression[j++] = pop();
                push(str[i]);
            }
            else if ((priority(str[i]) == priority(stack[top])) && (top > -1))
            {
                expression[j++] = pop();
                push(str[i]);
            }
        }
        else
            expression[j++] = str[i];
    }
    while (top != -1)
        expression[j++] = pop();
    expression[j] = '\0';
    printf("\nPostfix Expression:\n%s\n", expression);
}

int main()
{
    char str[size];
    printf("Please use '(' instead of '{' and '['\n");
    printf("Enter the expresssion\n");
    scanf("%s",str);
    infixToPrefix(str);
    return 0;
}
