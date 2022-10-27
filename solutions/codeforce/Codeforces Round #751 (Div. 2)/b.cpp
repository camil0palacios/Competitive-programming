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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 2010;
int a[Mxn][Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n;
        fori(i,0,n) cin >> a[0][i];
        fore(i,1,n) {
            int cnt[n+1];
            memset(cnt, 0, sizeof cnt);
            fori(j,0,n) a[i][j] = a[i-1][j];
            fori(j,0,n) cnt[a[i][j]]++;
            fori(j,0,n) a[i][j] = cnt[a[i][j]];
        }
        cin >> q;
        fori(i,0,q) {
            int x, k;
            cin >> x >> k;
            k = min(k, n);
            cout << a[k][x-1] << endl;
        }
    }
    return 0; 
}