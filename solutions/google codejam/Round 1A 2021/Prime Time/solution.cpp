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

const int Mxm = 96;
const int Mxp = 499;
int m;
ll P[Mxm], N[Mxm];

int ans;

void backtrack(int idx, ll pr, int s) {
    if(pr > s) return;
    if(pr == s) ans = max(ans, s);
    if(idx == m) return;
    ll mul = 1;
    for(int i = 0; i <= N[idx] && mul*pr <= s - i*P[idx]; i++) {
        backtrack(idx + 1, mul*pr, s - i*P[idx]);
        mul *= P[idx];
    }
}

void solve() {
    cin >> m;
    int s = 0;
    fori(i,0,m) {
        cin >> P[i] >> N[i];
        s += P[i]*N[i];
    }
    ans = 0;
    backtrack(0, 1, s);
    cout << ans << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}