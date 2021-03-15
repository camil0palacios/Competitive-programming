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

const ll mod = 1e9 + 9;
ll n, m, k;

ll be(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    // if(n - (n / k) >= m) {
    //     cout << m << endl;
    //     return 0;
    // }
    ll x = max(0ll, m - (n - n%k)/k*(k-1) - n%k);
    ll r = be(2ll, x+1) - 2;
    ll ans = r*k + m - x*k; 
    cout << (ans%mod + mod)%mod << endl;
    return 0; 
}