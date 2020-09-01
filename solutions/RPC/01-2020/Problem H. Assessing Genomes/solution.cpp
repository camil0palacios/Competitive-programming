#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MAXN = 50;
const int MOD = 1e9 + 7;
string av[MAXN], v[MAXN];
int sav[MAXN], sv[MAXN];

ll score(string & s){
    int n = (int)s.size();
    int sc = n;
    for(int l = 1; l <= n; l++) {
        string x = s.substr(0, l);
        bool ok = 1;
        int i = 0;
        for(; i + l - 1 < n; i += l){
            string y = s.substr(i, l);
            if(x != y) {
                ok = 0;
                break;
            }
        }
        if(ok && i == n)sc = min(sc, l);
    }
    return sc;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> av[i];
    }
    for(int i = 0; i < n; i++) {
        sv[i] = score(v[i]);
    }
    for(int i = 0; i < n; i++) {
        sav[i] = score(av[i]);
    }
    sort(sav, sav + n);
    sort(sv, sv + n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll diff = sav[i] - sv[i];
        ans += diff*diff;
    }
    cout << ans << endl;
    return 0;
}