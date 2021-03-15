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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, d;
    cin >> n >> d;
    vi x(n);
    fori(i,0,n) cin >> x[i];
    sort(all(x));
    ll ans = 0;
    fori(i,0,n) {
        int l = i+1, r = n-1;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(x[m] - x[i] <= d) l = m+1;
            else r = m-1;
        }
        if(l-1 != i && x[l-1] - x[i] <= d) {
            int m = l-1 - i;
            ans += 1ll*m*(m-1)/2;
        }
    }
    cout << ans << endl;
    return 0; 
}