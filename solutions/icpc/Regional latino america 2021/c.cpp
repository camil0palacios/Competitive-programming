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

ll s, g;

ll cal(vi a) {
    int n = sz(a);
    ll ans = 0, acc = 0;
    fori(i,0,3*n) {
        ans += acc;
        if(a[i%n] > g) {
            acc += a[i%n]-g;
            a[i%n] = g;
        }
        else if(a[i%n] < g) {
            int d = min(acc, g-a[i%n]); 
            acc -= d;
            a[i%n] += d;
        }
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    fori(i,0,n) cin >> a[i], s += a[i];
    g = s / n;
    vi b = a;
    ll ans = cal(b);
    reverse(all(b));
    ans = min(ans, cal(b));
    cout << ans << endl;
    return 0; 
}