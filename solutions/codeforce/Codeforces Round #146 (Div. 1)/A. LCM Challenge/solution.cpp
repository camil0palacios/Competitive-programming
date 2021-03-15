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

ll lcm(ll a, ll b) { return  a*b / __gcd(a, b); }

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    ll mx = 0;
    if(n <= 6) {
        fore(i,1,n) fore(j,1,n) fore(k,1,n)
            mx = max(mx, lcm(i, lcm(j, k)));
    } else {
        ll a = n, b = n-1, c = 1;
        ll l = lcm(a, b);
        fore(i,1,n) mx = max(mx, lcm(i, l)); 
        a = n-1, b = n-2;
        l = lcm(a, b);
        fore(i,1,n) mx = max(mx, lcm(i, l));
    }
    cout << mx << endl;
    return 0; 
}