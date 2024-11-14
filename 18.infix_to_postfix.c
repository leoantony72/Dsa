//infix to postfix evaluation
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char stack[20];
int stackEval[20];
int top=-1;
int top2=-1;
int variable[26];

void push(char c){
    top++;
    stack[top]=c;
}
char pop(){
    char item = stack[top];
    top--;
    return item;
}

void pushEval(int o){
    top2++;
    stackEval[top2]=o;
}
char popEval(){
    char item = stackEval[top2];
    top2--;
    return item;
}

int priority(char optr){
    switch (optr)
    {
    case '*': return 2;break;
    case '/': return 2;break;
    case '+': return 1;break;
    case '-': return 1;break;
    default: return 0; 
    }
}
void infixToPostfix(char infix[], char postfix[]){
    int i=0,j=0;

    for(i=0;infix[i]!='\0';i++){
        if(infix[i]=='(' ){
            push(infix[i]);
        }else if(infix[i]==')' ){
            while(stack[top]!='('){
                postfix[j]=pop(stack);
                j++;
            }
            top--;
        }else if(isalnum(infix[i])){
            postfix[j]=infix[i];
            j++;
        }else{
            while(top!=-1 && priority(stack[top]) >= priority(infix[i])){
                postfix[j]=pop(stack);
                j++;
            }
            push(infix[i]);
        }
    }

    while(top!=-1){
        postfix[j]=pop(stack);
        j++;
    }
    postfix[j]='\0';
}
void readVariables(char infix[]){
    int i;
    for(i=0;infix[i]!='\0';i++){
        if(isalnum(infix[i])){
            if(variable[infix[i] - 'a']==0){
                printf("enter value for %c",infix[i]);
                scanf("%d",&variable[infix[i]-'a']);
            }
        }
    }
}

int evaluatePostix(char postfix[]){

    int  i,op2,op1,r;

    for(i=0;postfix[i]!='\0';i++){
        if(isalnum(postfix[i])){
            if(isdigit(postfix[i])){
                continue;
            }
            pushEval(variable[postfix[i]-'a']);
        }else{
            op2= popEval(stackEval);
            op1= popEval(stackEval);
            switch(postfix[i]){
                case '+': r=op1+op2;break;
                case '-': r=op1-op2;break;
                case '*': r=op1*op2;break;
                case '/': r=op1/op2;break;
            }
            pushEval(r);
        }
    }
    return popEval();
}
void main(){
    int r;
    char infix[20],postfix[20];

    printf("enter the infix expression:");
    scanf("%s",infix);

    infixToPostfix(infix,postfix);

    printf("postfix expression:%s \n",postfix);
    readVariables(infix);
    r=evaluatePostix(postfix);
    printf("Result = %d\n",r);
}