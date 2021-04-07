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

const int Mxn = 110;
string a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,n) cin >> a[i];
    set<int> p;
    fori(i,0,n) {
        fori(j,i+1,n) {
            string t = a[j];
            reverse(all(t));
            if(a[i] == t) {
                p.insert(i);
            }
        }
    }
    int lst = -1;    
    fori(i,0,n) {
        string t = a[i];
        reverse(all(t));
        if(a[i] == t && !p.count(i)) lst = i; 
    }
    vi v;
    for(auto & i : p) v.eb(i);
    string ans;
    fori(i,0,sz(v)) ans += a[v[i]];
    if(lst != -1) ans += a[lst];
    forr(i,sz(v)-1,0) {
        string t = a[v[i]];
        reverse(all(t));
        ans += t;
    }
    cout << sz(ans) << endl;
    cout << ans << endl;
    return 0;
}