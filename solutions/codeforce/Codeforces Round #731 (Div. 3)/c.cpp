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

const int Mxn = 105;
int a[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int k, n, m;
        cin >> k >> n >> m;
        fori(i,0,n) cin >> a[i];
        fori(i,0,m) cin >> b[i];
        vi ans;
        int i = 0, j = 0;
        while(1) {
            if(i < n && a[i] == 0) k++, ans.eb(a[i++]);
            else if(i < n && a[i] <= k) ans.eb(a[i++]);
            else if(j < m && b[j] == 0) k++, ans.eb(b[j++]);
            else if(j < m && b[j] <= k) ans.eb(b[j++]);
            else break;
        }
        if(sz(ans) != n+m) ans.clear(), ans.eb(-1);
        for(auto & i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0; 
}