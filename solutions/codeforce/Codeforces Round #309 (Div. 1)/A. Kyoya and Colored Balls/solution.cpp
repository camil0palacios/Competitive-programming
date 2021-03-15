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

const int Mxn = 1010;
const ll mod = 1e9 + 7;
int a[Mxn];
ll c[Mxn][Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    c[0][0] = 1;
    for(int i = 1; i < Mxn; i++) {
        c[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    }
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    ll ans = 1, tot = 0;
    fori(i,0,n) {
        ans = (ans * c[tot + a[i] - 1][a[i]-1]) % mod;
        tot += a[i];
    }
    cout << ans << endl;
    return 0; 
}