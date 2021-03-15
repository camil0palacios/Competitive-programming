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
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vi k(n), c(m);
        fori(i,0,n) cin >> k[i];
        fori(i,0,m) cin >> c[i];
        sort(all(k), greater<int>());
        int j = 0;
        ll ans = 0;
        fori(i,0,n) {
            if(j < m && c[j] < c[k[i]-1]) {
                ans += c[j];
                j++;
            } else  ans += c[k[i]-1]; 
        }
        cout << ans << endl;
    }
    return 0; 
}