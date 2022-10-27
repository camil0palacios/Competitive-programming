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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int mx = max(a, max(b, c));
        int ans[3];
        ans[0] = mx == a && a > b && a > c ? 0 : mx - a + 1;
        ans[1] = mx == b && b > a && b > c ? 0 : mx - b + 1;
        ans[2] = mx == c && c > a && c > b ? 0 : mx - c + 1;
        fori(i,0,3) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0; 
}