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

const int Mxn = 505;
ll a[Mxn][Mxn];
int x[Mxn];
ll ans[Mxn], t[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fore(i,1,n) fore(j,1,n) cin >> a[i][j];
    fore(i,1,n) cin >> x[i];
    forr(k,n,1) {
        t[x[k]] = 1, ans[k] = 0;
        fore(i,1,n) fore(j,1,n) {
            a[i][j] = min(a[i][j], a[i][x[k]] + a[x[k]][j]);
            if(t[i] && t[j]) ans[k] += a[i][j];
        }
    }
    fore(i,1,n) cout << ans[i] << ' ';
    cout << endl;
    return 0; 
}