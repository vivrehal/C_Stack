#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

struct Stack{
    int *data;
    int top;
    int size;
};
struct Stack* createStack(int cap){
    struct Stack* st=malloc(sizeof(struct Stack));
    st->data=(int*)malloc(sizeof(int)*cap);
    st->top=-1;
    st->size=cap;
    return st;
}
void push(struct Stack* st, int val){
    if(st->top==st->size-1){
        return;
    }
    st->data[++st->top]=val;
}
int pop(struct Stack* st){
    if(st->top==-1){
        exit(EXIT_FAILURE);
        return -1;
    };
    return st->data[st->top--];
}
int peek(struct Stack* st){
    if(st->top==-1){
        exit(EXIT_FAILURE);
        return -1;
    }
    return st->data[st->top];
}
bool isEmpty(struct Stack* st){
    return st->top==-1;
}
int longestValidParentheses(char* s) {
    int n=strlen(s);
    // printf("%d",n);
    struct Stack* st=createStack(n+1);
    push(st,-1);
    int max=0;
    for(int i=0;i<n;i++){
        char c=s[i];
        if(c=='(')push(st,i);
        if(c==')'){
            if(!isEmpty(st))pop(st);
            if(!isEmpty(st)){
                if(i-peek(st)>max)max=i-peek(st);
            }
            else{
                push(st,i);
            }
        }
    }
    return max;
}
void main(){
    printf("%d",longestValidParentheses("()()())((((()))))))"));
}