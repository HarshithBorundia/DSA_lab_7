/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int c[n+1];
    for(int i=0;i<=n;i++){
        c[i] = 0;
    }
    for(int i=0;i<n;i++){
        c[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        c[i] = c[i]  +c[i-1];
    }
    int b[n+1];
    int ind[n+1];
    for(int i=n-1;i>=0;i--){
        b[c[a[i]]-1] = a[i];
        ind[c[a[i]]-1] = i+1;
        c[a[i]]--;
    }
    for(int i=0;i<n;i++){
        printf("%d ",b[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",ind[i]);
    }
    
    return 0;
}

