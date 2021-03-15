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
// #define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const ll oo = 1e18;
string h;
int b, s, c, pb, ps, pc;
ll rub;
int B, S, C;

bool can(ll m) {
    ll x = 1ll*max(0ll, m*B - 1ll*b)*pb;
    ll y = 1ll*max(0ll, m*S - 1ll*s)*ps;
    ll z = 1ll*max(0ll, m*C - 1ll*c)*pc;
    return x + y + z <= rub;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> h;
    cin >> b >> s >> c;
    cin >> pb >> ps >> pc;
    cin >> rub;
    int n = sz(h);
    fori(i,0,n) {
        B += h[i] == 'B';
        S += h[i] == 'S';
        C += h[i] == 'C';
    }
    ll l = 0, r = 1e13; 
    while(l <= r) {
        ll m = (l + r) >> 1;
        if(can(m)) l = m+1;
        else r = m-1;
    }
    cout << l-1 << endl;
    return 0; 
}