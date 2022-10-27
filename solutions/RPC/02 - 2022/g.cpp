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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const double pi = 3.14159265358979;

double area(double x, double r) {
    return (1.0/2)*(x*sqrt(r*r - x*x) + r*r*atan(x/sqrt(r*r - x*x)));
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(2);
    int t;
    cin >> t;
    while(t--) {
        int s, r;
        cin >> s >> r;
        if(2*r*r >= s*s) cout << 1.0*s*s << endl;
        else if(2*r <= s) cout << 1.0*pi*r*r << endl;
        else {
            double x1 = sqrt(1.0*r*r - (s/2.0)*(s/2.0));
            double x2 = s/2.0;
            double ans = (s/2.0)*x1 + (area(x2, r) - area(x1, r));
            cout << ans*4 << endl;
        }
    }
    return 0; 
}