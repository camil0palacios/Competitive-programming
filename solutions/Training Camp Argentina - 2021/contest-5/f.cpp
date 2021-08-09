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
int a[Mxn], b[Mxn], ans[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,n) cin >> a[i];
    fori(i,0,m) cin >> b[i];
    sort(a, a+n);
    fori(i,0,m) {
        int l = 0, r = n-1, p = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(a[mid] <= b[i]) p = mid, l = mid+1;
            else r = mid-1;
        }
        if(p != -1) ans[i] = p+1;
    }
    fori(i,0,m) cout << ans[i] << ' ';
    cout << endl;
    return 0; 
}