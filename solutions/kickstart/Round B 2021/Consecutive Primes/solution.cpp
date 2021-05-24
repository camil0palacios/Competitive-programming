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

const int Mxn = 40000;
bool s[Mxn];
vi p;

void cal() {
    memset(s, 0, sizeof s);
    p.eb(2);
    for(ll i = 3; i < Mxn; i += 2) {
        if(!s[i]) {
            p.eb(i);
            for(ll j = i*i; j < Mxn; j += i)
                s[j] = 1;
        }
    }
}

void solve() {
    ll z;
    cin >> z;
    ll mx = 0;
    fori(i,0,sz(p)-1) {
        // cout << p[i] << ' ';
        if(1ll*p[i]*p[i+1] <= z) mx = max(mx, 1ll*p[i]*p[i+1]);
    }
    cout << mx << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}