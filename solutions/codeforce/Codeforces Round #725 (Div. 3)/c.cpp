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

const int Mxn = 2e5 + 5;
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, L, R;
        cin >> n >> L >> R;
        fori(i,0,n) cin >> a[i];
        sort(a, a+n);
        ll ans = 0;
        fori(i,0,n) {
            int l = 0, r = n-1;
            int lb = -1, rb = -1;
            while(l <= r) {
                int m = (l+r) >> 1;
                int x = a[m] + a[i];
                if(L <= x) lb = m, r = m-1;
                else l = m+1;
            }
            l = 0, r = n-1;
            while(l <= r) {
                int m = (l+r) >> 1;
                int x = a[m] + a[i];
                if(x <= R) rb = m, l = m+1;
                else r = m-1;
            }
            if(lb != -1 && rb != -1 && lb <= rb) {
                ans += rb-lb+1;
                if(lb <= i && i <= rb) ans--;
            }
        }
        ans /= 2;
        cout << ans << endl;
    }
    return 0; 
}