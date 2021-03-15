#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int Mxn = 1e5 + 5;
int a[Mxn];

vi f[200005];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) {
        int x;
        cin >> x;
        for(int j = 2; j*j <= x; j++) {
            if(x % j == 0) {
                int cnt = 0;
                while(x % j == 0) {
                    cnt++;
                    x /= j;
                }
                f[j].emplace_back(cnt);
            }
        }
        if(x) f[x].emplace_back(1);
    }
    ll ans = 1;
    for(int i = 1; i <= 200000; i++) {
        sort(f[i].rbegin(), f[i].rend());
        if(n-2 < sz(f[i])) {
            int cnt = f[i][n-2];
            for(int j = 0; j < cnt; j++) {
                ans *= i;
            }
        }
    }
    cout << ans << endl;
    return 0; 
}