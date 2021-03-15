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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(16);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi x, y;
        fori(i,0,2*n) {
            int tx, ty; 
            cin >> tx >> ty;
            if(tx == 0) y.eb(abs(ty));
            else x.eb(abs(tx));
        }
        sort(all(y));
        sort(all(x));
        double ans = 0;
        fori(i,0,n) ans += sqrt(1.0*x[i]*x[i] + 1.0*y[i]*y[i]);
        cout << ans << endl;
    }
    return 0; 
}