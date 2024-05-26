/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
} node;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int freq[n+1];
    for(int i=0;i<n+1;i++){
        freq[i]=0;
    }
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    node*bucket[n+1];
    for(int i=0;i<n+1;i++){
        bucket[i] = NULL;
    }
    for(int i=0;i<n;i++){
        if(bucket[freq[a[i]]]==NULL){
            node * head = malloc(sizeof(node));
            head->data = a[i];
            head->prev = NULL;
            head->next = NULL;
            bucket[freq[a[i]]] = head;
        }
        else{
            node* temp = bucket[freq[a[i]]];
            if(temp->data==a[i])continue;
            bool val = false;
            while (temp->next != NULL) {
                if(temp->data == a[i]){
                    val = true;
                    break;
                }
                temp = temp->next;
            }
            if(val)continue;
            node* newNode = malloc(sizeof(node));
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = NULL;
            newNode->data = a[i];
        }
    }
    int ans[n];
    int j  =0;
    for(int i=1;i<n+1;i++){
        node * temp = bucket[i];
        while(temp!=NULL){
            int cnt = i;
            while(cnt){
                ans[j++] = temp->data;
                cnt--;
            }
            temp=temp->next;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}

