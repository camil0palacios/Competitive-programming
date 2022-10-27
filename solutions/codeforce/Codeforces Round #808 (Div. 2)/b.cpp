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

// typedef __int128_t i128; // only for extreme cases
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
        int n, l, r;
        cin >> n >> l >> r;
        bool ok = 1;
        vl ans;
        fore(i,1,n) {
            int x = (l+i-1)/i;
            if(1ll*i*x <= r) ans.eb(1ll*i*x);
            else ok = 0;
        }
        if(ok) {
            cout << "YES" << endl;
            for(auto i : ans) cout << i << ' ';
            cout << endl;
        } else cout << "NO" << endl;
    }
    return 0; 
}