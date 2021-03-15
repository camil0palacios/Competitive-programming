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
        int w, h, n;
        cin >> w >> h >> n;
        ll ans = 1;
        while(w % 2 == 0) ans *= 2, w /= 2;
        while(h % 2 == 0) ans *= 2, h /= 2;
        if(ans >= n) cout << "YES" << endl;
        else cout << "NO" << endl;
        // cout << ans << endl;
    }
    return 0; 
}