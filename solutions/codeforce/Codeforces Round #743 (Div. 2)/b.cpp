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
const int Lg = 17;
int n;
int a[Mxn], b[Mxn], mn[2*Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fore(i,0,2*n + 5) mn[i] = 1e9;
        fori(i,0,n) cin >> a[i];
        fori(i,0,n) cin >> b[i], mn[b[i]] = i;
        forr(i,2*n,0) mn[i] = min(mn[i], mn[i+1]);
        int ans = 1e9;
        fori(i,0,n) {
            ans = min(ans, i + mn[a[i]]);
        }
        cout << ans << endl;
    }
    return 0; 
}