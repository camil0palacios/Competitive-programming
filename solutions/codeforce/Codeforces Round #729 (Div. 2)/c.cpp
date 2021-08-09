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

const int mod = 1e9 + 7;

ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans = 0, g = 1;
        fore(i,1,n) {
            g = lcm(g, i);
            if(g > n) break;
            ans += n/g;
        }
        cout << (ans + n) % mod << endl;
    }
    return 0; 
}