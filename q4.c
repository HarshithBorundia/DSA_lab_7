/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int b[n+1];
    for(int i=0;i<=n;i++){
        b[i] = 0;
    }
    for(int i =0;i<n;i++){
        b[a[i]]++;
    }
    int c[n+1];
    int j = 0;
    for(int i=1;i<n+1;i++){
        if(b[i]==0){
            c[j++] = i;
        }
    }
    int i = 0;
    j--;
    bool val = false;
    while(i<j){
        if(c[i]+c[j]==k){
            printf("yes\n");
            val = true;
            break;
        }
        else if(c[i]+c[j]>k){
            j--;
        }
        else{
            i++;
        }
    }
    if(!val)printf("no\n");
    

    return 0;
}

