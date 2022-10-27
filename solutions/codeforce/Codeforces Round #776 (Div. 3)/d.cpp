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

const int Mxn = 2e3 + 5;
int a[Mxn], b[Mxn];
int ans[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,1,n) cin >> a[i], ans[i] = 0;
        int x = n;
        forr(p,n,1) {
            int idx = 0;
            fore(i,1,n) {
                if(a[i] == x) {
                    idx = i;
                    break;
                }
            }
            if(a[idx] != idx) {
                int j = 1;
                fore(i,idx+1,x) b[j++] = a[i];
                fore(i,1,idx) b[j++] = a[i];
                fore(i,1,x) a[i] = b[i];
                ans[p] = idx;
            }
            x--;
        }
        bool ok = 1;
        fore(i,2,n) ok &= a[i-1]+1 <= a[i];
        if(ok) {
            fore(i,1,n) cout << ans[i] << ' ';
            cout << endl;
        }
        else cout << -1 << endl;
    }
    return 0; 
}