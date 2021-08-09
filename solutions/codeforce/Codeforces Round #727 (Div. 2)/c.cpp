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
ll a[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; ll k, x;
    cin >> n >> k >> x;
    fori(i,0,n) cin >> a[i];
    sort(a, a+n);
    int m = 0;
    fori(i,0,n-1) {
        if(a[i]+x < a[i+1]) {
            b[m] = (a[i+1]-a[i]-1)/x;
            m++;
        }  
    }
    int ans = m+1;
    sort(b, b+m);
    fori(i,0,m) {
        if(k >= b[i]) {
            ans--;
            k -= b[i];
        }
    }
    cout << ans << endl;
    return 0; 
}