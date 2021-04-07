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

const int Mxn = 2e5 + 5;
int l[Mxn], r[Mxn];
ll a[Mxn], p[Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    priority_queue<int> mx;
    fore(i,1,n) {
        cin >> a[i];
        mx.push(a[i]);
    }
    fore(i,1,q) {
        cin >> l[i] >> r[i];
        p[l[i]]++, p[r[i]+1]--;
    }
    fore(i,1,n) p[i] += p[i-1];
    priority_queue<pair<ll,int>> pos;
    fore(i,1,n) pos.push({p[i], i});
    while(!pos.empty()) {
        int idx = pos.top().sd;
        a[idx] = mx.top();
        pos.pop(), mx.pop();
    }
    fore(i,1,n) a[i] += a[i-1];
    ll ans = 0;
    fore(i,1,q) ans += a[r[i]] - a[l[i]-1];
    cout << ans << endl;
    return 0; 
}