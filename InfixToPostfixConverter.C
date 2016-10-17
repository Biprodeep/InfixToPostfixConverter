/*
###########################################################################################################################################################################################################
##																																																		 ##									
## Author: Biprodeep Roy a.k.a (Virtu4lgh0st)																																			                 ##										
##																																																		 ##
## Version:v0.17 																																														 ##
##																																									                                     ##									
## Date: 17/10/2016																																														 ##
##																																																		 ##
## Note: This is infix to postfix covertor that will convert your expression with accuracy! But you need to put the initial brackets before the expression. For Example: (A+B).                          ##
##																																																		 ##
## You are entitled to copy,modify,change,develop this project more with your own builds.Giving credits to the Author will highly be appreciated and will hold up the ethics of Opensource. Good Day! :D ##
##																																																	     ##
###########################################################################################################################################################################################################
*/

#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>
char stack[100],inf[100],pf[100];
int top=-1;
void push(char c)
{
	stack[++top]=c;
}
char pop()
{
	return stack[top--];
}
int priority(char c)
{
	switch(c)
	{
		case '^': return 3;
		case '/':
		case '*': return 2;
		case '+':
		case '-': return 1;
		default:  return 0;
	}
}
int main()
{
	int i,j=0;
	char ch,c;
	//clrscr();
	printf("\n********");
	printf("\n*      *");
	printf("\n ****** ");
	printf("\n  ****  ");
	printf("\n   **   ");
	printf("\n  ****  ");
	printf("\n ****** ");
	printf("\n*      *");
	printf("\n********");
	printf("\n\n\nEnter the infix expression:");
	scanf("%s",inf);
	for(i=0;inf[i]!='\0';i++)
	{
		ch=inf[i];
		switch(ch)
		{
			case '(': push(ch);
				  break;
			case ')': c=pop();
				  while(c!='(')
				  {
					pf[j++]=c;
					c=pop();
				  }
				  break;
		}
		if(ch>=65 && ch<=90)
		pf[j++]=ch;
		else if((ch != '(') && (ch != ')'))
		{
			while((priority(stack[top])>=priority(ch)) && (top!=-1))
			pf[j++]=pop();
			push(ch);
		}
	}
	while(top!=-1)
	pf[j++]=pop();
	 pf[j]='\0';
	printf("\n \nYour Postfix Expression is:--\n %s",pf);
	printf("\n");
	//puts(pf);
	//getch();
	return 0;
}