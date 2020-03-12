#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, p;
int a[1000005], b[1000005];

int div(int * v, int sz){
    for(int i = 0; i < sz; i++){
        if(v[i] % p)return i;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> p;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int t = div(a, n) + div(b, m);
    cout << t << endl;
    return 0;
}