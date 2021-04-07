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
        map<int,int> m;
        fori(i,0,n) {
            int a; cin >> a;
            m[a]++;
        }
        priority_queue<int> q;
        for(auto & p : m) q.emplace(p.sd);
        while(sz(q) > 1) {
            int x = q.top(); q.pop();
            int y = q.top(); q.pop();
            x--, y--;
            if(x) q.push(x);
            if(y) q.push(y);
        }
        int ans = 0;
        while(!q.empty()) ans += q.top(), q.pop();
        cout << ans << endl;
    }
    return 0; 
}