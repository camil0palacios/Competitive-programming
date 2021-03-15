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

unordered_map<ll,ll> res, tmp, g;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) {
        ll x; cin >> x;
        tmp.clear();
        for(auto & p : g) tmp[__gcd(x, p.ft)] += p.sd;
        tmp[x]++;
        swap(tmp, g);
        for(auto & p : g) res[p.first] += p.sd;
    }
    int q;
    cin >> q;
    while(q--) {
        int x; cin >> x;
        cout << res[x] << endl;
    }
    return 0; 
}