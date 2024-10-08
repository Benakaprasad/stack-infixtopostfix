#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define max 100
int stack[max];
int top=-1;
void push(char ele)
{
if(top>=max-1)
{
printf("the stack is full");
}
else
{
stack[++top]=ele;
}
}
char pop()
{
if(top<0)
{
printf("the stack is empty");
}
else
{
char ele=stack[top--];
}
}
int precedence(char ch)
{
switch(ch)
{
case '+':
case '-':
return 1;
case '*':
case '/':
return 2;
case '^':
return 3;
defualt:
return 0;
}
}
void infixtopostfix()
{
char infix[max],postfix[max];
char ch;int i=0;int j=0;
printf("enter the infix expression\n");
scanf("%s",infix);
while((ch=infix[i++])!='\0')
{
if(isalnum(ch))
{
postfix[j++]=ch;
}
else if(ch=='(')
{
push(ch);
}
else if(ch==')')
{
while(top!=-1 && stack[top]!='(')
{
postfix[j++]=pop();
}
pop();
}
else
{
while(top!=-1 && precedence(stack[top])>=precedence(ch))
{
postfix[j++]=pop();
}
push(ch);
}
}
while(top!=-1)
{
postfix[j++]=pop();
}
postfix[j]='\0';
printf("the postfix expression is:%s\n",postfix);
}
int main()
{
infixtopostfix();
return 0;
}





