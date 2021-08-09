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

const int oo = 1e9 + 7;
const int Mxn = 1e5 + 5;
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 0;
        fori(i,0,n) cin >> a[i], ans += a[i] <= 0;
        sort(a, a+n);
        int mn = oo;
        fori(i,0,n) {
            if(a[i] > 0) mn = min(mn, a[i]);
        }
        bool flag = mn < oo;
        fori(i,1,n) {
            if(a[i] <= 0) flag &= a[i]-a[i-1] >= mn;
        }
        if(flag) ans++;
        cout << ans << endl;
    }
    return 0; 
}