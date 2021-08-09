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

const int Mxn = 1010;
const int z = 1000;
int dp[Mxn][2*Mxn];
int n, k;
string s, res;

bool go(int i, int d) {
    if(i == n) return abs(d) == k;
    if(abs(d) == k) return 0;
    int & ans = dp[i][z+d];
    if(ans != -1) return ans;
    if(((s[i] == 'W') || (s[i] == '?')) && go(i+1, d+1)) {
        res += 'W';
        return ans = 1; 
    }
    if(((s[i] == 'L') || (s[i] == '?')) && go(i+1, d-1)) {
        res += 'L';
        return ans = 1;
    }
    if(((s[i] == 'D') || (s[i] == '?')) && go(i+1, d)) {
        res += 'D';
        return ans = 1;
    }
    return ans = 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k >> s;
    memset(dp, -1, sizeof dp);
    if(go(0, 0)) {
        reverse(all(res));
        cout << res << endl;
    } else cout << "NO" << endl;
    return 0; 
}