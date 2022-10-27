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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1e6 + 5;
int n, q;
int t[Mxn];

void upd(int i, int val) {
    for(; i <= n; i += (i & -i)) t[i] += val;
}
int qry(int i) {
    int s = 0;
    for(; i; i -= (i & -i)) s += t[i];
    return s;
}
int find(int k) {
    int l = 1, r = n, idx = -1;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(qry(m) >= k) idx = m, r= m-1;
        else l = m+1; 
    }
    return idx;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    fori(i,0,n) {
        int a; cin >> a;
        upd(a, 1);
    }
    fori(i,0,q) {
        int k; cin >> k;
        if(k > 0) upd(k, 1);
        else {
            k = abs(k);
            upd(find(k), -1);
        }
    }
    int ans = find(1);
    cout << (ans == -1 ? 0 : ans) << endl;
    return 0; 
}