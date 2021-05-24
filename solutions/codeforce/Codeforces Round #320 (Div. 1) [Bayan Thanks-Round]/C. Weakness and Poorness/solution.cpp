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
int n;
int a[Mxn];

double f(double x) {
    double ans = 0;
    double mn = 0, mx = 0;
    fori(i,0,n) {
        double r = 1.0*a[i]-x;
        mx = max(mx + r, r);
        mn = min(mn + r, r);
        ans = max(ans, max(-mn, mx));
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(15);
    cin >> n;
    fori(i,0,n) cin >> a[i];
    double l = -2e4, r = 2e4;
    fori(i,0,100) {
        double m1 = l + (r-l)/3.0;
        double m2 = r - (r-l)/3.0;
        if(f(m1) <= f(m2)) r = m2;
        else l = m1;
    }
    cout << min(f(l),f((l+r)/2)) << endl;
    return 0;
}