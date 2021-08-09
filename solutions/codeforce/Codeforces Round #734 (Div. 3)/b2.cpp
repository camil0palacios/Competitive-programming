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
int n, k;
int a[Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        map<int, vi> m;
        fori(i,0,n) {
            cin >> a[i];
            if(sz(m[a[i]]) < k) m[a[i]].eb(i);
        }
        int s = 0;
        for(auto & p : m) s += sz(p.sd);
        s -= s % k;
        vi ans(n);
        int c = 0;
        for(auto & p : m) {
            for(auto & i : p.sd) {
                ans[i] = ++c;
                c %= k;
                if(--s == 0) goto out;
            }
        }
        out:
        for(auto & i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0; 
}