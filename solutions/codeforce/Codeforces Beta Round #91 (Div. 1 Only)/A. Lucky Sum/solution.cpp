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

vector<ll> p;
int val[3] = {0,4,7};

void rec(int idx, ll x, bool z) {
    if(idx == 12) {
        if(x > 0) p.eb(x);
        return;
    }
    int mn = z ? 1 : 0;
    fori(i,mn,3) {
        rec(idx + 1, x*10 + val[i], z || val[i] != 0);
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    rec(0,0,0);
    int l, r;
    cin >> l >> r;
    int n = sz(p), i = 0;
    while(i < n && p[i] < l) i++;
    ll ans = 0;
    while(i < n && p[i] < r) {
        ans += 1ll*(p[i] - l + 1)*p[i];
        l = p[i]+1, i++;
    }
    ans += (r - l + 1)*p[i];
    cout << ans << endl;
    return 0;
}