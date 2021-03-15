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
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1e5 + 5;
const double pi = acos(-1);
double a[Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    fori(i,0,n) {
        int x, y;
        cin >> x >> y;
        int d = 0;
        a[i] = 180.0*atan2(y,x)/pi;
    }
    sort(a, a+n);
    double ans = a[n-1] - a[0];
    fori(i,0,n-1) {
        ans = min(ans, 360.0 - a[(i+1)%n] + a[i]);
    }    
    cout << ans << endl;
    return 0; 
}