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

const int Mxn = 1e5 + 5;
int a[Mxn], q[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> m;
    fori(i,0,m) cin >> q[i];
    cin >> n;
    fori(i,0,n) cin >> a[i];
    sort(q, q+m);
    sort(a, a+n, greater<int>());
    int ans = 0;
    int i = 0;
    while(i < n) {
        if(i + q[0] < n) {
            fori(k,0,q[0]) ans += a[i++];
            i += 2;
        } else {
            while(i < n) ans += a[i++];
        }
    }
    cout << ans << endl;
    return 0; 
}