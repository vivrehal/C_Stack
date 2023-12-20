#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
struct Stack{
    int *data;
    int top;
    int size;
};

struct Stack* createStack(int cap){
    struct Stack* st= (struct Stack*)malloc(sizeof(struct Stack));
    st->data=(int*)malloc(sizeof(int)*cap);
    st->top=-1;
    st->size=cap;
    return st;
}

void push(struct Stack* st, int val){
    if(st->top==st->size-1)return;
    st->data[++st->top]=val;
}

int pop(struct Stack* st){
    if(st->top==-1)return -1;
    return st->data[st->top--];
}

bool isEmpty(struct Stack* st){
    return st->top==-1;
}

int solve(int a, int b, char c){
    if(c=='+')return a+b;
    else if(c=='-')return a-b;
    else if(c=='*')return a*b;
    else return a/b;
}
int main() {
    int N;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++){
        char str[100];
        int l=0;
        char k;
        scanf("%c",&k);
        while(k!='?'){
            str[l++]=k;
            scanf("%c",&k);
        }
        str[l++]='?';
        // printf("%s\n",str);
        
        struct Stack* st=createStack(strlen(str));
        int j=0;
        while(str[j]!='?'){
            // printf("%c \n",str[j]);
            if(str[j]=='+' || str[j]=='-' || str[j]=='/' || str[j]=='*'){
                int a=pop(st);
                int b=pop(st);
                int tba=solve(b,a,str[j]);
                

                
                push(st,tba);
                // printf("%c -> operation\n",str[j]);
                
            }
            else if(str[j]==' '){
                j++;
                continue;
            }
            else if(isdigit(str[j])){
                int num=0;
                while(isdigit(str[j])){
                    num=(num*10)+(str[j]-'0');
                    j++;
                }
                push(st,num);
                // printf("%d -> operand\n",num);
            }
            j++;
        }
        printf("%d\n",pop(st));
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}