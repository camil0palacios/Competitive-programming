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

const int Mxn = 1e5 + 5;
ll a[Mxn], b[Mxn];
int l[Mxn], r[Mxn], d[Mxn];
int op[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    fore(i,1,n) cin >> a[i];
    fore(i,1,m) cin >> l[i] >> r[i] >> d[i];
    fore(i,1,k) {
        int x, y; cin >> x >> y;
        op[x]++, op[y+1]--;
    }
    fore(i,1,m) op[i] += op[i-1];
    fore(i,1,m) {
        b[l[i]] += 1ll*op[i]*d[i];
        b[r[i]+1] -= 1ll*op[i]*d[i];
    }
    fore(i,1,n) b[i] += b[i-1];
    fore(i,1,n) a[i] += b[i];
    fore(i,1,n) cout << a[i] << ' ';
    cout << endl;
    return 0; 
}