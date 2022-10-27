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

const int Mxn = 1e5 + 5;
vi a[Mxn];
int ord[Mxn];
int mn_num[Mxn];

bool check(ll x, int n) {
    fori(p,0,n) {
        int i = ord[p];
        fori(j,0,sz(a[i])) {
            if(x <= a[i][j]) return 0;
            x++;
        }
    }
    return 1;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) {
            int k;
            cin >> k;
            a[i].clear();
            a[i].resize(k, 0);
            fori(j,0,k) cin >> a[i][j];
        }
        fori(i,0,n) {
            int mn = a[i][0] + 1;
            fori(j,1,sz(a[i])) {
                if(mn + j <= a[i][j]) {
                    mn = a[i][j] - j + 1;
                }
            }
            mn_num[i] = mn;
        }
        fori(i,0,n) ord[i] = i;
        sort(ord, ord + n, [](int i, int j) {
            return mn_num[i] < mn_num[j];
        });
        ll l = 0, r = 1e12;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(check(mid, n)) r = mid-1;
            else l = mid+1;
        }
        cout << r+1 << endl;
    }
    return 0; 
}