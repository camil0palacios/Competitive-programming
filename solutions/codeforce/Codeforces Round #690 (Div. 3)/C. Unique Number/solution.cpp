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

int x;
int dp[10][455][2][1 << 10];
string ans;

bool go(int i, int s, bool z, int msk) {
    if(i == 10) return s == x;
    if(dp[i][s][z][msk] != -1) return dp[i][s][z][msk];
    for(int j = 0; j <= 9; j++) {
        bool nz = z || j != 0;
        if(!((msk >> j) & 1) && j + s <= x && go(i + 1, j + s, nz, nz ? msk | (1 << j) : 0)) {
            ans += char(j + '0');
            return dp[i][s][z][msk] = 1;
        }
    } 
    return dp[i][s][z][msk] = 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> x;
        ans.clear();
        memset(dp, -1, sizeof dp);
        if(go(0, 0, 0, 0)) {
            reverse(all(ans));
            cout << stoi(ans) << endl;
        } else cout << -1 << endl;
    }
    return 0; 
}