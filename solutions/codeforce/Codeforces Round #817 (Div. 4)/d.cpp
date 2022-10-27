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

// typedef __int128_t i128; // only for extreme cases
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
        int n; string s;
        cin >> n >> s;
        vi c;
        ll ans = 0;
        fori(i,0,n) {
            ans += s[i] == 'L' ? i : n-i-1;
            if(s[i] == 'L') c.eb(max(i, n-i-1) - i);
            else c.eb(max(i, n-i-1) - (n-i-1));
        }
        sort(all(c), greater<int>());
        fori(i,0,n) {
            ans += c[i];
            cout << ans << ' ';
        }
        cout << endl;
    }
    return 0; 
}