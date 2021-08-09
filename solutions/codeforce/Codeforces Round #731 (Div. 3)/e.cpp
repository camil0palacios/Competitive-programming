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

const int Mxn = 3e5 + 5;
int a[Mxn], t[Mxn], l[Mxn], r[Mxn];
int ans[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--) {
        int n, k;
        cin >> n >> k;
        fore(i,1,n) l[i] = 2e9, r[i] = 2e9;
        fori(i,0,k) cin >> a[i];
        fori(i,0,k) {
            cin >> t[i];
            l[a[i]] = r[a[i]] = t[i];
        }
        int acc = 2e9;
        forr(i,n,1) {
            acc = min(acc + 1, r[i]);
            r[i] = acc;
        }
        acc = 2e9;
        fore(i,1,n) {
            acc = min(acc + 1, l[i]);
            l[i] = acc;
        }
        fore(i,1,n) ans[i] = min(l[i], r[i]);
        fore(i,1,n) cout << ans[i] << ' ';
        cout << endl;
    } 
    return 0; 
}