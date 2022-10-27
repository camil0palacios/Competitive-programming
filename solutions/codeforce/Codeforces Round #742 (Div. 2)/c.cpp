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

const int Mxn = 14;
string s;
int dp[Mxn][1 << Mxn][2][2];

bool check(int i, int msk) {
    int a = (msk >> i) & 1;
    int b = (msk >> (i+1)) & 1;
    return !a && !b;
}

int go(int i, int msk, int x, int y) {
    if(i == sz(s)) return check(i, msk) && x && y;
    int & ans = dp[i][msk][x][y];
    if(ans != -1) return ans;
    ans = 0; int c = (msk >> i) & 1;
    fore(a,0,9) {
        fore(b,0,9) {
            int num = a + b + c;
            int acc = num / 10;
            int r = num % 10;
            if(r == s[i]-'0') 
                ans += go(i+1, msk | (acc << (i+2)), x || a > 0, y || b > 0);
        }
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        reverse(all(s));
        memset(dp, -1, sizeof dp);
        cout << go(0, 0, 0, 0) << endl;
    }
    return 0; 
}