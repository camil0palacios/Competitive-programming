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

const int oo = 1e9;
const int Mxv = 1e6 + 5;
int a[10];
int dp[Mxv];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v;
    cin >> v;
    fori(i,0,9) cin >> a[i];
    fore(i,1,v) fori(j,0,9)
        if(a[j] <= i)
            dp[i] = max(dp[i], dp[i - a[j]] + 1);
    if(dp[v] == 0) cout << -1;
    else {
        while(1) {
            int mx = 0, to = -1;
            fori(i,0,9) {
                if(a[i] <= v && dp[v] == dp[v - a[i]] + 1 && mx < i+1) {
                    mx = i+1;
                    to = v - a[i];
                }
            }
            if(to != -1) {
                cout << mx;
                v = to;
            }
            else break;
        }
    }
    cout << endl;
    return 0; 
}