#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
    
    char *data;
    int top;
    int size;
};

struct Stack *createStack(int cap){
    struct Stack* st= (struct Stack*)malloc(sizeof(struct Stack));
    st->data= (char*)malloc(sizeof(int)*cap);
    st->top=-1;
    st->size=cap;
    return st;

}

void push(struct Stack *st, char val){
    if(st->top>=st->size-1)return;
    st->data[++st->top]=val;
    return;
}

char pop(struct Stack *st){
    if(st->top==-1){
        char a;
        return a;
    }
    return st->data[st->top--];
}

bool isEmpty(struct Stack *st){
    if(st->top==-1)return 1;
    return 0;
}

char reverse(char tbr){
    if(tbr=='}')return '{';
    else if(tbr==']')return '[';
    else return '(';
}
bool isValid(char* s) {
    int n=strlen(s);
    struct Stack* st=createStack(n);
    for(int i=0;i<n;i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            push(st,s[i]);
        }
        else{
            if(isEmpty(st) || st->data[st->top]!=reverse(s[i]))return false;
            pop(st);
        }
    }
    if(isEmpty(st))return true;
    else return false;
}
void main(){
    bool b1 = isValid("((())))");
    bool b2 = isValid("(((}))");
    bool b3 = isValid("(({}))");
    printf("%d %d %d",b1,b2,b3);
}
