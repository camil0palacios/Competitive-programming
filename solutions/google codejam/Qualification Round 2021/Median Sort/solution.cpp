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

int query(int i, int j, int k) {
    cout.flush();
    cout << i << ' ' << j << ' ' << k;
    int x; cin >> x; 
    return x;
}

void solve(int t) {
    int n, q;
    cin >> n >> q;
    int av = q / t;
    int i = 1, j = 2, k = 3; 
    fori(r,0,av) {
        
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) solve(t);
    return 0; 
}