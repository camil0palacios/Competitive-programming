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
        int x[3], y[3];
        fori(i,0,3) cin >> x[i] >> y[i];
        int ans = abs(x[0] - x[1]) + abs(y[0] - y[1]); 
        if(x[0] == x[1] && x[0] == x[2]) {
            ans += min(y[0], y[1]) <= y[2] && y[2] <= max(y[0], y[1]) ? 2 : 0;
        }
        if(y[0] == y[1] && y[0] == y[2]) {
            ans += min(x[0], x[1]) <= x[2] && x[2] <= max(x[0], x[1]) ? 2 : 0;
        }
        cout << ans << endl;
    }
    return 0; 
}