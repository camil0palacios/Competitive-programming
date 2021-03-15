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
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 55;
ll dp[Mxn][Mxn][Mxn][Mxn];
int lst[Mxn];
char A[Mxn], B[Mxn], C[Mxn], D[Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    scanf("%s %s %s %s", A+1, B+1, C+1, D+1);
    int n = strlen(A + 1) + 1;
    int m = strlen(B + 1) + 1;
    int p = strlen(C + 1) + 1;
    int q = strlen(D + 1) + 1;
    map<int,int> pos;
    fori(i,0,n) {
        lst[i] = pos[A[i]];
        pos[A[i]] = i;
    }
    fori(i,0,n) fori(j,0,m) fori(k,0,p) fori(l,0,q) {
        auto & ans = dp[i][j][k][l];
        if(!i || !j || !k || !l) ans = 1;
        else if(A[i] == B[j] && A[i] == C[k] && A[i] == D[l]) {
            ans = dp[i-1][j][k][l] + dp[i-1][j-1][k-1][l-1];
            if(lst[i]) ans -= dp[lst[i]-1][j-1][k-1][l-1];
        } else {
            ans = (dp[i-1][j][k][l] + dp[i][j-1][k][l] + dp[i][j][k-1][l] + dp[i][j][k][l-1]) -
                (dp[i-1][j-1][k][l] + dp[i-1][j][k-1][l] + dp[i-1][j][k][l-1] + dp[i][j-1][k-1][l] + dp[i][j-1][k][l-1] + dp[i][j][k-1][l-1]) + 
                (dp[i-1][j-1][k-1][l] + dp[i-1][j-1][k][l-1] + dp[i-1][j][k-1][l-1] + dp[i][j-1][k-1][l-1]) - 
                (dp[i-1][j-1][k-1][l-1]);
        }
    }
    cout << dp[n-1][m-1][p-1][q-1]-1 << endl;
    return 0;
}