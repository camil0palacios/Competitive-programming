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

const int Mxn = 1e5;
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, s, n;
    cin >> t >> s >> n;
    fori(i,0,n) cin >> a[i];
    a[n] = t;
    int x = s, y = 0, tr = 1;
    fori(i,1,n+1) {
        int mn = tr ? min(x, a[i]-a[i-1]) : min(y, a[i]-a[i-1]);
        if(tr) x -= mn, y += mn;
        else x += mn, y -= mn;
        tr ^= 1;
    }
    tr ^= 1;
    int ans = tr ? x : y;
    cout << ans << endl;
    return 0; 
}