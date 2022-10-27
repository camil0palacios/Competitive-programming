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
const int Mxn = 8e5 + 5;
ll p[Mxn];

void solve() {
    int n;
    string s;
    cin >> n >> s;
    fore(i,0,n) p[i] = 0;
    int lst = 0;
    fori(i,0,n) {
        if(s[i] == 'O' || s[i] == 'X') {
            lst = i;
            break;
        }
    }
    fori(i,lst+1,n) {
        if(s[i] == 'F') p[i] = p[i-1];
        else if(s[i] == s[lst]) p[i] = p[i-1], lst = i;
        else {
            p[i] = (p[lst] + (lst + 1)) % mod;
            lst = i;
        }
    } 
    ll ans = 0;
    fore(i,0,n) ans = (ans + p[i]) % mod;
    cout << ans << endl;    
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}