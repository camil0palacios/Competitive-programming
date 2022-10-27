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

int p[1010];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,1,1000) p[i] = 0;
        fore(i,1,n) {
            int a; cin >> a;
            p[a] = i;
        }
        int ans = -1;
        fore(i,1,1000) {
            if(!p[i]) continue;
            fore(j,i,1000) {
                if(p[j] && __gcd(i, j) == 1) ans = max(ans, p[i] + p[j]);
            }
        }
        cout << ans << endl;
    }
    return 0; 
}