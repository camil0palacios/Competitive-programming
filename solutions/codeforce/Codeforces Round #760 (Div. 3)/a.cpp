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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

void debug(vi v) {
    for(auto & i : v) cout << i << ' ';
    cout << endl;
}

void sol() {
    int n = 7;
    vi b(n);
    fori(i,0,n) cin >> b[i];
    fori(i,0,n) fori(j,i+1,n)  fori(k,j+1,n) {
        int a[3] = {b[i], b[j], b[k]}; 
        vi tmp;
        fori(p,1,1 << 3) {
            int s = 0;
            fori(t,0,3) if((p >> t) & 1) s += a[t]; 
            tmp.eb(s);
        }
        sort(all(tmp));
        // debug(tmp), debug(b);
        if(tmp == b) {
            fori(t,0,3) cout << a[t] << ' ';
            cout << endl;
            return;
        }
    } 
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) sol();
    return 0; 
}