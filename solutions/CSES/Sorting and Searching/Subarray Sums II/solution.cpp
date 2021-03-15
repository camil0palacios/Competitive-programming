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
    int n, x;
    cin >> n >> x;
    // p[i] - p[j] = x
    // p[i] - x = p[j]
    map<ll, int> m;
    m[0]++;
    ll ans = 0, s = 0;
    fori(i,0,n) {
        int a; cin >> a;
        s += a;
        if(m.count(s - x)) ans += m[s - x];
        m[s]++;
    }
    cout << ans << endl;
    return 0; 
}