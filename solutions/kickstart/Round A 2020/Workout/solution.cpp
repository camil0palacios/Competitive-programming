#include <bits/stdc++.h>
#define endl '\n'
#define mp make_pair
using namespace std;

int const MAXN = 1e5;
int a[MAXN];

bool can(int n, int k, int x) {
    long long sumk = 0;
    for(int i = 1; i < n; i++) {
        int dif = a[i] - a[i - 1];
        sumk += (dif - 1) / x;
    }
    if(sumk <= k)return 1;
    return 0;
}

void sol() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = 1e9;
    while(r - l > 1) {
        int mid = (l + r) >> 1;
        if(can(n, k, mid))r = mid;
        else l = mid;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol();
    }
    return 0;
}