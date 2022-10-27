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

const int Mxn = 2e5 + 5;
int x[Mxn], y[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> x[i] >> y[i];
    map<int,int> mx, my;
    map<ii, int> same;
    ll ans = 0;
    fori(i,0,n) {
        ans += mx[x[i]];
        ans += my[y[i]];
        ans -= same[mp(x[i], y[i])];
        mx[x[i]]++;
        my[y[i]]++;
        same[mp(x[i], y[i])]++;
    }
    cout << ans << endl;
    return 0; 
}