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

const ll oo = 1e14;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vi a(n+1);
        fore(i,1,n) cin >> a[i];
        ll ans = -oo;
        forr(i,n,max(1, n-100)) {
            forr(j,i-1,max(1, n-100)) {
                ans = max(ans, 1ll*i*j - 1ll*k*(a[i] | a[j]));
            }   
        }
        cout << ans << endl;
    }
    return 0; 
}