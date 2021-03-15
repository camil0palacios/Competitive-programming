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

const int Mxn = 1e5 + 5;
int n;
ll a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    ll s = 0, mx = 0;
    fori(i,0,n) {
        cin >> a[i];
        s += a[i];
        mx = max(mx, a[i]);
    }
    ll x = (s + (n - 1) - 1) / (n - 1);
    cout << max(mx, x) << endl;
    return 0; 
}