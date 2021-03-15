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
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

set<int> g;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    set<int> s;
    int n;
    cin >> n;
    fori(i,0,n) {
        int a; cin >> a;
        set<int> x;
        x.insert(a);
        for(auto & i : s) x.insert(i | a);
        s = x;
        g.insert(s.begin(), s.end());
    }
    cout << sz(g) << endl;
    return 0; 
}