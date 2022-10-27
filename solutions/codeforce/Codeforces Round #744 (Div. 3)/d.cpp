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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        priority_queue<ii> q;
        fori(i,0,n) {
            int a; cin >> a;
            if(a) q.push(mp(a, i));
        }
        vii ans;
        while(sz(q) > 1) {
            auto x = q.top(); q.pop();
            auto y = q.top(); q.pop();
            if(x.ft-1 > 0) q.push(mp(x.ft-1, x.sd));
            if(y.ft-1 > 0) q.push(mp(y.ft-1, y.sd));
            ans.eb(x.sd, y.sd);
        }
        cout << sz(ans) << endl;
        for(auto & p : ans) cout << p.ft+1 << ' ' << p.sd+1 << endl;
    }
    return 0; 
}