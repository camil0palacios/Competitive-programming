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

const int Mxn = 1e5 + 5;
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    fori(i,0,n) cin >> a[i];
    sort(a, a+n);
    ll s = 0, l = 0;
    ii ans = {0, 0};
    fori(i,0,n) {
        s += a[i];
        while(1ll*(i - l + 1)*a[i] > s + k) s -= a[l++];
        ans = max(ans, {i-l+1, -a[i]});
    }
    cout << ans.ft << ' ' << -ans.sd << endl;
    return 0; 
}