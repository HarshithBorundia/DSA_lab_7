#include <stdio.h>
#include <string.h>

int val[6] = {10, 11, 12, 13, 14, 15};

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char arr[n][101];
    for(int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    int a[n][10];
    for(int i = 0; i < n; i++) {
        int j = strlen(arr[i]) - 1;
        for(int t = 0; t < 10; t++) {
            if(j >= 0 && (arr[i][j] >= '0' && arr[i][j] <= '9')) {
                a[i][t] = arr[i][j] - '0';
            } else if(j >= 0 && (arr[i][j] >= 'A' && arr[i][j] <= 'F')) {
                a[i][t] = val[arr[i][j] - 'A'];
            } else {
                a[i][t] = 0;
            }
            j--;
        }
    }

    char ans[n][101];
    for(int i = 0; i < n; i++) {
        strcpy(ans[i], arr[i]);
    }

    char temp[n][101];
    int a1[n][10];
    for(int i=0;i<n;i++){
        for(int t=0;t<10;t++){
            a1[i][t] = a[i][t]; 
        }
    }
    int a2[n][10];
    for(int i=0;i<n;i++){
        for(int t=0;t<10;t++){
            a2[i][t] = a[i][t]; 
        }
    }
    int j = 0;// Temporary array to hold sorted elements
    while(k--) {
        int b[n];
        for(int i = 0; i < n; i++) {
            b[i] = a2[i][j];
        }
        j++;

        int cnt[16];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++) {
            cnt[b[i]]++;
        }
        for(int i = 1; i < 16; i++) {
            cnt[i] += cnt[i - 1];
        }
        for(int i = n - 1; i >= 0; i--) {
            strcpy(temp[cnt[b[i]] - 1], ans[i]);
            for(int t = 0;t<10;t++){
                a1[cnt[b[i]]-1][t] = a2[i][t];
            }
            cnt[b[i]]--;
        }
        for(int i = 0; i < n; i++) {
            strcpy(ans[i], temp[i]);
        }
        for(int i=0;i<n;i++){
            for(int t=0;t<10;t++){
                a2[i][t] = a1[i][t];
            }
        } 
        // Copy sorted elements from temp back to ans
    }

    for(int i = 0; i < n; i++) {
        printf("%s ", ans[i]);
    }

    return 0;
}


