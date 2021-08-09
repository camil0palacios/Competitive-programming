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
        int n;
        cin >> n;
        ll acc = 0;
        int j = 0;
        map<ll,ll> m;
        ll ans = 0, s = 0;
        fori(i,0,n) {
            int a; cin >> a;
            ll x = s;
            if(m.count(a)) x += m[a];
            m[a] += (i+1);
            ans += x;
            s = x;
        }
        cout << ans << endl;
    }
    return 0; 
}