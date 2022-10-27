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

const int N = 1e5 + 5;
int dp[N][2][10][2];
string n, s;

bool go(int i, bool top, int lst, bool up) {
    if(i == sz(n)) return 1;
    int & ans = dp[i][top][lst][up];
    if(ans == -1) {
        ans = 0;
        int mx = top ? n[i]-'0' : 9;
        forr(j,mx,0) {
            if(up && lst <= j && (
                go(i+1, top && j == mx, j, 1) || 
                go(i+1, top && j == mx, j, 0)
            )) {
                s += char(j + '0');
                return ans = 1;
        
            }
            if(!up && lst >= j && go(i+1, top && j == mx, j, 0)) {
                s += char(j + '0');
                return ans = 1;
            }
        }
    }
    return ans = 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fori(i,0,sz(n)) fori(j,0,2) fore(lst,0,9) fori(k,0,2) {
            dp[i][j][lst][k] = -1;
        }
        s.clear();
        if(!go(0, 1, 0, 1)) go(0, 1, 9, 0);
        reverse(all(s));
        cout << s << endl;
    }
    return 0; 
}