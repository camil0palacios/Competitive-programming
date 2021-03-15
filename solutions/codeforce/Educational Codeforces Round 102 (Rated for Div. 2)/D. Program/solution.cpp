#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;
        vi cur(n+2);
        vi pmx(n+2), pmn(n+2);
        for(int i = 1; i <= n; i++) {
            int v = s[i-1] == '+' ? 1 : -1;
            cur[i] = cur[i-1] + v;
            pmx[i] = max(pmx[i-1], cur[i]);
            pmn[i] = min(pmn[i-1], cur[i]);
        }
        vi smx(n+2), smn(n+2);
        for(int i = n; i >= 1; i--) {
            int v = s[i-1] == '+' ? 1 : -1;
            smx[i] = max(0, smx[i+1] + v);
            smn[i] = min(0, smn[i+1] + v);
        }
        for(int i = 0; i < m; i++) {
            int l, r; cin >> l >> r;
            l--; r++;
            int a = max(pmx[l], smx[r] + cur[l]);
            int b = min(pmn[l], smn[r] + cur[l]);
            cout << a - b + 1 << endl;
        }
    }
    return 0; 
}