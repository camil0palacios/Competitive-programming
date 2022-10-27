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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int N = 5050;
int a[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    ll ans = 1e18;
    fori(i,0,n) {
        ll pr = 0, tmp = 0;
        forr(j,i-1,0) {
            ll x = (pr + a[j]) / a[j];
            tmp += x;
            pr = a[j]*x;
        }
        pr = 0;
        fori(j,i+1,n) {
            ll x = (pr + a[j]) / a[j];
            tmp += x;
            pr = a[j]*x;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0; 
}