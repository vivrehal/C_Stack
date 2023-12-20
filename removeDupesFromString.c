#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

struct Stack{
    char *data;
    int top;
    int size;
};
struct Stack* createStack(int cap){
    struct Stack* st=malloc(sizeof(struct Stack));
    st->data=(char*)malloc(sizeof(char)*cap);
    st->top=-1;
    st->size=cap;
    return st;
}
void push(struct Stack* st, char val){
    if(st->top==st->size-1){
        return;
    }
    st->data[++st->top]=val;
}
char pop(struct Stack* st){
    if(st->top==-1){
        exit(EXIT_FAILURE);
        return 'a';
    };
    return st->data[st->top--];
}
char peek(struct Stack* st){
    if(st->top==-1){
        exit(EXIT_FAILURE);
        return 'a';
    }
    return st->data[st->top];
}
bool isEmpty(struct Stack* st){
    return st->top==-1;
}
void removeDuplicateLetters(char* s) {
    int n=strlen(s);
    
    struct Stack* st=createStack(strlen(s)+1);
    int vis[26];
    int map[26];
    for(int i=0;i<26;i++){
        map[i]=0;
        vis[i]=0;
    }
    for(int i=0;i<n;i++){
        map[s[i]-'a']=i;
    }
    for(int i=0;i<n;i++){
        char c=s[i];
        if(isEmpty(st) || c<peek(st) && vis[c-'a']==0){
            while(!isEmpty(st) && c<peek(st)){
                if(map[peek(st)-'a']>i){
                    vis[peek(st)-'a']=0;
                    pop(st);
                }
                else{
                    break;
                }
            }
        }
        if(vis[c-'a']==0){
            vis[c-'a']=1;
            push(st,c);
        // printf("%c\n",peek(st));

        }
    }
    // printf("%d\n",st->top);
    char ans[st->top+2];
    int j=0;
    while(!isEmpty(st)){
        // printf("%c",peek(st));
        ans[j++]=pop(st);
    }
    ans[j]='\0';
    int l=0, h=j-1;
    while(l<h){
        char temp=ans[l];
        ans[l]=ans[h];
        ans[h]=temp;
        l++;
        h--;
    }
    printf("%s",ans);


}
void main(){
    removeDuplicateLetters("bcabc");

}