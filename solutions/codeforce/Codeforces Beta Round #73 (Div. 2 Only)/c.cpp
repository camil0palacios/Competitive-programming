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

ll lcm(int a, int b) {
    return 1ll * a / __gcd(a, b) * b;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    ll l = lcm(a, b);
    // cout << l << endl;
    // cout << l/a << ' ' << l/b << endl;
    ll x = l/a, y = l/b;
    if(abs(x - y) <= 1) cout << "Equal" << endl;
    else cout << (x > y ? "Dasha" : "Masha") << endl;
    return 0; 
}