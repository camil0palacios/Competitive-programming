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

const int Mxn = 1e6 + 5;
ll S[Mxn], P[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; string s;
        cin >> n >> s;
        vi a;
        fori(i,0,n) if(s[i] == '*') a.eb(i);
        n = sz(a);
        if(!n) { cout << 0 << endl; continue; }
        int c = 1;
        P[0] = 0;
        fori(i,1,n) {
            P[i] = P[i-1] + 1ll*(a[i]-a[i-1]-1)*c;
            c++;
        }
        c = 1;
        S[n-1] = 0;
        forr(i,n-2,0) {
            S[i] = S[i+1] + 1ll*(a[i+1]-a[i]-1)*c;
            c++;
        }
        ll ans = 1e14;
        fori(i,0,n) 
            ans = min(ans, P[i]+S[i]);
        cout << ans << endl;
    }
    return 0; 
}