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
typedef vector<ll> vl;

const int Mxn = 110;
string a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    bool ok1 = 0;
    fori(i,0,n) {
        bool ok = 0;
        fori(j,0,n) ok |= a[i][j] == '.';
        if(!ok) ok1 = 1; 
    }
    bool ok2 = 0;
    fori(j,0,n) {
        bool ok = 0;
        fori(i,0,n) ok |= a[i][j] == '.';
        if(!ok) ok2 = 1;
    }
    if(ok1 && ok2) {
        cout << -1 << endl;
        return 0;
    }
    vii ans;
    fori(i,0,n) fori(j,0,n) {
        if(a[i][j] == '.') {
            ans.eb(i+1, j+1);
            break;
        }
    }
    if(sz(ans) != n) {
        ans.clear();
        fori(j,0,n) fori(i,0,n) {
            if(a[i][j] == '.') {
                ans.eb(i+1, j+1);
                break;
            }
        }
    }
    fori(i,0,n) cout << ans[i].ft << ' ' << ans[i].sd << endl;
    return 0; 
}