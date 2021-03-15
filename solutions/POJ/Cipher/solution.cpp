#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MXN = 205;
int a[MXN], t[MXN];

int main() {
    int n, k;
    char s[MXN], ans[MXN];
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        memset(t, 0, sizeof t);
        for(int i = 1; i <= n; i++) {
            int j = a[i], cnt = 1;
            while(i != j) j = a[j], cnt++;
            t[i] = cnt;
        }
        while(1) {
            scanf("%d", &k);
            if(k == 0) break;
            getchar();
            gets(s + 1);
            for(int i = strlen(s + 1) + 1; i <= n; i++) s[i] = ' ';
            s[n + 1] = 0;
            for(int i = 1; i <= n; i++) {
                int p = i;
                for(int j = 0; j < k % t[i]; j++) {
                    p = a[p];
                }
                ans[p] = s[i];
            }
            ans[n + 1] = 0;
            puts(ans + 1);
        }
        printf("\n");
    }
    return 0;
}