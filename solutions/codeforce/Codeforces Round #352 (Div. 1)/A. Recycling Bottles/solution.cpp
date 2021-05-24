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

const double oo = 1e18;
const int Mxn = 1e5 + 5;
struct pt { int x, y; pt(){} pt(int x, int y): x(x), y(y) {} };
pt pts[Mxn];
double dp[Mxn][2][2];

double dist(pt a, pt b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(15);
    int n;
    pt a, b, t;
    cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
    cin >> n;
    fori(i,0,n) cin >> pts[i].x >> pts[i].y;
    fori(x,0,2) fori(y,0,2) dp[n][x][y] = oo;
    dp[n][1][0] = dp[n][0][1] = dp[n][1][1] = 0;
    forr(i,n-1,0) {
        fori(x,0,2) {
            fori(y,0,2) {
                double & ans = dp[i][x][y];
                ans = dp[i+1][x][y] + 2*dist(t, pts[i]);
                if(!x) ans = min(ans, dp[i+1][1][y] + dist(a, pts[i]) + dist(pts[i], t));
                if(!y) ans = min(ans, dp[i+1][x][1] + dist(b, pts[i]) + dist(pts[i], t));
            }
        }
    }
    cout << dp[0][0][0] << endl;
    return 0; 
}