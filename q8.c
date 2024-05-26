/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
void min_heapify(int a[], int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < n && a[l] < a[largest]) {
        largest = l;
    }
    if (r < n && a[r] < a[largest]) {
        largest = r;
    }

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        min_heapify(a, largest, n);
    }
}

void build_min_heap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_heapify(a, i, n);
    }
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int b[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    
    int c[n];
    for(int i=0;i<n;i++)
    {
        c[i]=a[i]+b[i];
    }
    int d[n];
    int j = 0;
    for(int i=0;i<n;i++){
        if(c[i]>0){
            d[j]=c[i];
            j++;
        }
    }
    int size = j;
    int arr[k];
    int i1 = 0;
    for( i1=0;i1<k && i1<size;i1++){
        arr[i1]=d[i1];
    }
    build_min_heap(arr,i1);
    for(int i=i1;i<size;i++){
        if(d[i]>arr[0]){
            arr[0]=d[i];
            min_heapify(arr,0,i1);
        }
    }
    int sum = 0;
    for(int i=0;i<i1;i++){
        sum+=arr[i];
    }
    printf("%d",sum);
    return 0;
}


