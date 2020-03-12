#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

void read(int & x) {
    scanf("%d", &x);
}

void sol() {
    int n;
    read(n);
    long long mx = 0;
    pair<int,int> stk[n + 1];
    int it = 0;
    stk[it++] = mp(0, 0);
    for(int i = 0; i < n; i++) {
        int x;
        read(x);
        if(stk[it - 1].first < x) {
            stk[it++] = mp(x, i);
        } else {
            int lst = i;
            while(x <= stk[it - 1].first) {
                mx = max(mx,  (long long) stk[it - 1].first * (i - stk[it - 1].second));
                lst = min(lst, stk[it - 1].second);
                it--;
            }
            stk[it++] = mp(x,  lst);
        }
    }
    while(it) {
        mx = max(mx, (long long)stk[it - 1].first *(n - stk[it - 1].second));
        it--;
    }
    printf("%d\n", mx);
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    read(t);
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": ";
        sol();
    }
    return 0;
}