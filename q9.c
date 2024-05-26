/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
typedef struct arr{
    int data;
    char ch;
}arr;
void max_heapify(arr a[], int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < n && a[l].data > a[largest].data) {
        largest = l;
    }
    if (r < n && a[r].data > a[largest].data) {
        largest = r;
    }

    if (largest != i) {
        arr temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, largest, n);
    }
}
void build_max_heap(arr c[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(c, i, n);
    }
}
int main()
{
    int n,k;
    scanf("%d %d",&n ,&k);
    char a[n];
    int vec[26];
    int prefix[n];
    for(int i=0;i<26;i++){
        vec[i] = 0;
    }
    for(int i=0;i<n;i++){
        prefix[i] = 0;
    }
    for(int i=0;i<n;i++){
        scanf(" %c",a+i);
        vec[a[i]-'a']++;
        prefix[i] = vec[a[i]-'a'];
    }
    arr c[k];
    for(int i=0;i<k;i++){
        c[i].data = prefix[i];
        c[i].ch = a[i];
    }
    build_max_heap(c,k);
    for(int i=k;i<n;i++){
        if(c[0].data>prefix[k]){
            c[0].data = prefix[k];
            c[0].ch = a[k];
            max_heapify(c,0,k);
        }
    }
    int cnt[26];
    for(int i=0;i<26;i++){
        cnt[i] = 0;
    }
    for(int i=0;i<k;i++){
        cnt[c[i].ch-'a']++;
    }
    long long sum = 0;
    for(int i=0;i<26;i++){
        sum+= cnt[i]*cnt[i];
    }
    printf("%lld",sum);
    return 0;
}

