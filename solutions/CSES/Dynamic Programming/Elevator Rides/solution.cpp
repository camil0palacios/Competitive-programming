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
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxn = 21;
int n, x;
int w[Mxn];
pair<int,ll> dp[1 << Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> x;
    fori(i,0,n) cin >> w[i];
    dp[0] = {1, 0};
    fori(msk,1,1 << n) {
        dp[msk] = {n+1, 0};
        fori(i,0,n) {
            if((msk >> i) & 1) {
                auto p = dp[msk^(1 << i)];
                if(p.sd + w[i] <= x) p.sd += w[i];
                else {
                    p.ft++;
                    p.sd = w[i];
                }
                dp[msk] = min(dp[msk], p);
            } 
        }
    }
    cout << dp[(1 << n)-1].ft << endl;
    return 0; 
}