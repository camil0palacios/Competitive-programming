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
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        int n = sz(a), m = sz(b);
        int ans = 1e9;
        fore(l,1,min(n,m)) {
            fori(i,0,n-l+1) {
                fori(j,0,m-l+1) {
                    if(a.substr(i, l) == b.substr(j, l)) {
                        int x = i + (n - (l + i));
                        int y = j + (m - (l + j));
                        ans = min(ans, x + y);
                    }
                }
            }
        }
        if(ans == 1e9) ans = n + m;
        cout << ans << endl;
    }
    return 0; 
}