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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vi p(n), q(n);
    fori(i,0,n) cin >> p[i];
    fori(i,0,n) {
        ll x = 0, tx = 0;
        cout << "i: " << i+1 << endl;  
        fore(j,1,n) {
            cout << (i+1) % j << ' ';
            x ^= ((i+1) % j);
            if(j <= i+1) tx ^= ((i+1) % j);
        }
        cout << endl << "xor: " << x << endl;
        cout << "txor: " << tx << endl;
        q[i] = p[i] ^ x;
    }
    int ans = 0;
    fori(i,0,n) ans ^= q[i];
    cout << ans << endl;
    return 0; 
}