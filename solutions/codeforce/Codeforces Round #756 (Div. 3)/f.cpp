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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 2e5 + 5;
ll a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; ll s;
        cin >> n >> s;
        fori(i,0,n) cin >> a[i];
        int ans = 0, x = 0, y = 0, l = -1;
        fori(i,0,n) {
            s += a[i];
            while(l < i && s < 0) s += -1*a[++l];
            if(s >= 0 && ans < i-l) {
                ans = i-l;
                x = l+1, y = i; 
            }
        }
        if(ans) cout << x+1 << ' ' << y+1 << endl;
        else cout << -1 << endl;
    }
    return 0; 
}