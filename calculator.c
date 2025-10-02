#include<stdio.h>
#include<string.h>
#include<math.h>
#define size 100
char stack[size];
int stack2[size];
int top=-1;
void push(char c){
    stack[++top]=c;
}
void push2(int c){
    stack2[++top]=c;
}
char pop(){
    char c= stack[top--];
    return c;
}
int pop2(){
    int c= stack2[top--];
    return c;
}
int isoperator(char c){
    if (c=='+'||c=='-'||c=='*'||c=='/'||c=='%'||c=='^')
    {
       return 1;
    }
  return 0;  
}
int isoperand(char c){
    if ((c>='0'&&c<='9')||(c>='A'&&c<='Z')||(c>='a'&&c<='z'))
    {
        return 1;
    }
    return 0;
}
int isp(char c){
    if(c=='+'||c=='-')
        return 2;
    else if(c=='*'||c=='/'||c=='%')
        return 4;
    else if(c=='^')
        return 6;
    else
        return 0;
    
}
int icp(char c){
    if(c=='+'||c=='-')
        return 3;
    else if(c=='*'||c=='/'||c=='%')
        return 5;
    else if(c=='^')
        return 7;
    else
        return 0;
}
void infixtopostfix(char postfix[size]){
    char c;int i=0;
    
    while ((c =getchar())!='\n')
    {
        if (isoperand(c))
        {
            postfix[i]=c;
            i++;
        }else if (c=='(')
        {
            push(c);
        }
        else if(isoperator(c)){
            if (icp(c)>isp(stack[top]))
                push(c);
            else{
                postfix[i]=pop();
                i++;
                push(c);}
        }
        else if (c==')'){
            while (stack[top]!='(')
            {
                postfix[i]=pop();
                i++;
            }stack[top--];
            
            
        }
        
    } while (top!= -1)
            {
                postfix[i]=pop();
                i++;
            }
    postfix[i]='\0';
}
int postevaluation(char postfix[size]){
    int i=0,v;
    while (postfix[i]!='\0')
    {   char c=postfix[i];
       if ((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
       {
        printf("enter value for %c: ",c);
        scanf("%d",&v);
        push2(v);
        i++;
       }else if(c>='0'&&c<='9'){
            push2(c-'0');i++;
       }else
       {
            int y=pop2(),x=pop2(),result;
            switch (c)
            {
            case '+':
                result=x+y;
                break;
             case '-':
                result=x-y;
                break;
             case '*':
                result=x*y;
                break;
             case '/':
                result=x/y;
                break;
             case '%':
                result=x%y;
                break;
             case '^':
                result=pow(x,y);
                break;
            
            default:
                break;
            }i++;
            push2(result);
       }
       
       
    }
   return stack2[top]; 
    
}
int main(){
    char postfix[size];
    printf("enter infix expression\n");
    infixtopostfix(postfix);
    printf("postfix expression: ");
    for (int i = 0; postfix[i] !='\0'; i++)
    {
        printf("%c",postfix[i]);
    }
    printf("\n");
    int res=postevaluation(postfix);
    printf("result= %d",res);

return 0;
}