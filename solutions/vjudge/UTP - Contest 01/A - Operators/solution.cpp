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

const int N = 500;
const int S = 125250;
int n, s;
bool dp[N+5][S+5];
// vi ans;

// int go(int i, int x) {
//     if(i == n+1) return x - (n*(n+1)/2 - x) == s;
//     if(dp[i][x] != -1) return dp[i][x];
//     if(x + i <= S && go(i + 1, x + i)) {
//         ans.eb(i);
//         return dp[i][x] = 1; 
//     }
//     if(i > 1 && go(i + 1, x)) {
//         ans.eb(-i);
//         return dp[i][x] = 1;
//     }
//     return dp[i][x] = 0;
// }

int main() { 
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    // cin >> n >> s;
    // memset(dp, -1, sizeof dp);
    // if(go(1, 0)) {
    //     reverse(all(ans));
    //     for(auto & i : ans) {
    //         if(i > 0 && i != 1) cout << "+";
    //         cout << i;
    //     }
    // } else cout << "Impossible" << endl;
    scanf("%d %d", &n, &s);
    fore(j,0,S) dp[n+1][j] = j - (n*(n+1)/2 - j) == s; 
    forr(i,n,1) {
        fore(j,0,S) {
            if(i+j <= S && dp[i+1][j+i]) {
                dp[i][j] = 1;
            }
            else if(i > 1 && dp[i+1][j]) {
                dp[i][j] = 1;
            }
        }
    }
    if(dp[1][0]) {
        int j = 0;
        fore(i,1,n) {
            int x;
            if(i+j <= S && dp[i][j] == dp[i+1][j+i]) {
                x = i;
                j += i;
            }
            else if(i > 1 && dp[i][j] == dp[i+1][j]) {
                x = -i;
            }
            // if(x > 0 && x != 1) cout << "+";
            // cout << x;
            if(x > 0 && x > 1) printf("%c", '+');
            printf("%d", x);
        }
    } else {
        printf("%s", "Impossible");
        // cout << "Impossible" << endl;
    }
    return 0;
}