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

const ll oo = 1e15;
const int Mxn =  2e5 + 5;
int a[Mxn], ord[Mxn];
ll dp[Mxn];
int ans[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    fori(i,0,n) ord[i] = i;
    sort(ord, ord+n, [&](int i, int j) {
        return a[i] < a[j];
    });
    fore(i,0,n) dp[i] = oo;
    dp[n] = 0;
    forr(i,n-1,0) {
        fori(j,i+2,min(n, i+100)) {
            int p = ord[j], q = ord[i];
            dp[i] = min(dp[i], dp[j+1] + (a[p] - a[q]));
        }
    }
    int i = 0, c = 0;
    while(i < n) {
        int nxt = 0;
        fori(j,i+2,min(n, i+100)) {
            int p = ord[j], q = ord[i];
            if(dp[i] == dp[j+1] + (a[p] - a[q])) {
                nxt = j+1;
            }
        }
        fori(j,i,nxt) ans[ord[j]] = c+1;
        i = nxt;
        c++;
    }
    cout << dp[0] << ' ' << c << endl;
    fori(i,0,n) cout << ans[i] << ' ';
    cout << endl;
    return 0; 
}