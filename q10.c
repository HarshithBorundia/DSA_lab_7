/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
void max_heapify(int a[][2], int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < n && a[l][0] > a[largest][0]) {
        largest = l;
    }
    if (r < n && a[r][0] > a[largest][0]) {
        largest = r;
    }

    if (largest != i) {
        int temp1  =a[i][0];
        int temp2 = a[i][1];
        a[i][0] = a[largest][0];
        a[i][1] = a[largest][1];
        a[largest][0] = temp1;
        a[largest][1] = temp2;
        max_heapify(a, largest, n);
    }
}
void build_max_heap(int a[][2], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(a, i, n);
    }
}
int main()
{
    int n,x;
    scanf("%d %d",&n,&x);
    int a[n];
    int b[n][2];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        b[i][0] = a[i];
        b[i][1] = i+1;
    }
    build_max_heap(b,n);
    while(n>0 && b[0][0]>x){
        b[0][0] = b[n-1][0];
        b[0][1] = b[n-1][1];
        n--;
        max_heapify(b,0,n);
    }
    printf("%d\n",n);
    for(int i=0;i<n;i++){
        printf("%d ",b[i][1]);
    }

    return 0;
}

