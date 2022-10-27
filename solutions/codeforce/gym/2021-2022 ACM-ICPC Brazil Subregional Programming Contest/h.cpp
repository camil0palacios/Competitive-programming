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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int N = 1e5 + 5;
map<int, vi> a, p;
int ans[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    fori(i,0,n) {
        int x, c;
        cin >> x >> c;
        a[c].eb(x);
        p[c].eb(i);
    }
    for(auto & p1 : a) {
        int col = p1.ft;
        auto & v = p1.sd;
        sort(all(v));
        fori(i,0,sz(p[col])) {
            int idx = p[col][i];
            ans[idx] = v[i];
        }
    }
    bool ok = is_sorted(ans, ans+n);
    cout << (ok ? 'Y' : 'N') << endl;
    return 0;
}