#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vii e; vi id(n);
    fori(i,0,n) {
        int a, b;
        cin >> a >> b;
        id[i] = a;
        int idx = i+1;
        e.eb(a, -idx), e.eb(b, +idx);
    }
    sort(all(e));
    set<int> pos;
    int ans = 0;
    for(auto & p : e) {
        int x = p.ft;
        int i = p.sd;
        if(i > 0) {
            int l = id[i-1];
            auto it = pos.upper_bound(-l);
            if(it != pos.end()) ans++;
            pos.erase(-l);
        } else {
            pos.insert(-x);
        }
    }
    cout << ans << endl;
    return 0; 
}