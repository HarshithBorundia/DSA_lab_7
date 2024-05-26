#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    double data;
    struct node* next;
    struct node* prev;
} node;

int main() {
    int n;
    scanf("%d", &n);

    double a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    node* arr[n];
    int cnt[n];
    for (int i = 0; i < n; i++) {
        cnt[i] = 0;
    }

    // Initialize each bucket to NULL
    for (int i = 0; i < n; i++) {
        arr[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int val = (int)(a[i] * n);
        if (arr[val] == NULL) {
            node* head = malloc(sizeof(node));
            head->data = a[i];
            head->next = NULL;
            head->prev = NULL;
            arr[val] = head;
            cnt[val]++;
        } else {
            node* temp = arr[val];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            node* newNode = malloc(sizeof(node));
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = NULL;
            newNode->data = a[i];
            cnt[val]++;
        }
    }

    double ans[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == NULL) continue;
        else if (arr[i]->next == NULL) {
            ans[j++] = arr[i]->data;
            continue;
        } else {
            node* temp = arr[i]->next;
            while (temp != NULL) {
                double key = temp->data;
                node* temp1 = temp;
                temp1 = temp1->prev;
                while (temp1 != NULL) {
                    if (temp1->data > key) {
                        temp1->next->data = temp1->data;
                        if (temp1->prev == NULL) {
                            temp1->data = key;
                        }
                        temp1 = temp1->prev;
                    } else {
                        break;
                    }
                }
                if (temp1 != NULL) temp1->next->data = key;
                temp = temp->next;
            }
            temp = arr[i];
            while (temp != NULL) {
                ans[j++] = temp->data;
                temp = temp->next;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%g ", ans[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", cnt[i]);
    }

    return 0;
}

