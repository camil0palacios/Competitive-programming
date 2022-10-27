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

int a[3][4];
int ans[4];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    fore(t,1,T) {
        fori(i,0,3) fori(j,0,4) cin >> a[i][j];
        int x = 1e6;
        fori(j,0,4) {
            int tmp = 1e9;
            fori(i,0,3) tmp = min(tmp, a[i][j]);
            int mn = min(tmp, x);
            x -= min(x, mn);
            ans[j] = mn;
        }        
        cout << "Case #" << t << ": ";
        if(!x) {
            fori(i,0,4) {
                if(i) cout << ' ';
                cout << ans[i];
            }
            cout << endl;
        } else cout << "IMPOSSIBLE" << endl;
    }
    return 0; 
}