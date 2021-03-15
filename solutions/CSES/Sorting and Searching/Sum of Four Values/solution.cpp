#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxn = 1010;
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    fori(i,0,n) cin >> a[i];
    // ai + aj + ak + aw = x
    // ai + aj = x - ak - aw
    map<ll, ii> m;
    fori(i,0,n) {
        fori(j,i+1,n) {
            if(m.count(a[i] + a[j])) {
                auto p = m[a[i] + a[j]];
                if(p.ft != i && p.ft != j && p.sd != i && p.sd != j) {
                    vi v({p.ft+1, p.sd+1, i+1, j+1});
                    sort(all(v));
                    fori(i,0,4) cout << v[i] << ' ';
                    return 0;
                }
            }
            m[x-a[i]-a[j]] = {i, j};
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0; 
}