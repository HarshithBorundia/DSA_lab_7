/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
typedef struct target{
    int diff;
    int data;
    int ind;
}target;
void max_heapify(target a[], int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < n && a[l].diff > a[largest].diff) {
        largest = l;
    }
    if (r < n && a[r].diff > a[largest].diff) {
        largest = r;
    }
    if(largest==i){
        if(l<n && a[l].diff==a[largest].diff && a[l].data>a[largest].data){
            largest = l;
        }
        if(r<n && a[r].diff==a[largest].diff && a[r].data>a[largest].data){
            largest = r;
        }
    }
    if (largest != i) {
        target temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, largest, n);
    }
}

void build_max_heap(target a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(a, i, n);
    }
}
int main()
{
    int n,k,x;
    scanf("%d %d %d",&n,&k,&x);
    int a[n];
    target arr[k];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for(int i=0;i<k;i++){
        arr[i].diff = abs(abs(a[i]-abs(x)));
        arr[i].data = a[i];
        arr[i].ind = i;
    }
    build_max_heap(arr,k);
    for(int i=k;i<n;i++){
        target temp;
        temp.diff = abs(abs(a[i]-abs(x)));
        temp.data = a[i];
        temp.ind = i;
        if(temp.diff<arr[0].diff){
            arr[0] = temp;
            max_heapify(arr,0,k);
        }
        else if(temp.diff==arr[0].diff && arr[0].data>temp.data){
            arr[0] = temp;
            max_heapify(arr,0,k);
        }
    }
    int ans[k];
    int j = k-1;
    for(int i=0;i<k;i++){
        ans[j] = arr[0].data;
        arr[0] = arr[j] ;
        max_heapify(arr,0,j);
        j--;
    }
    for(int i=0;i<k;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}

