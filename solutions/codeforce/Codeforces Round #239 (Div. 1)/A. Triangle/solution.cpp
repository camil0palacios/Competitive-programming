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
typedef vector<ll> vl;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    fori(x,1,a) {
        double ty = sqrt(1.0*a*a - x*x);
        if(ty - (int)ty != 0) continue;
        int y = (int) ty;
        if(x*x + y*y == a*a) {
            int x1 = -y, y1 = x;
            int g = __gcd(abs(x1), abs(y1));
            x1 /= g, y1 /= g;
            int k = sqrt(x1*x1 + y1*y1);
            if(b % k == 0) {
                x1 = x1*b/k, y1 = y1*b/k;
                if((x != 0 || y != 0) && (x1 != 0 || y1 != 0) && (x != x1 && y != y1)) {
                    cout << "YES" << endl;
                    cout << "0 0" << endl;
                    cout << x << ' ' << y << endl;
                    cout << x1 << ' ' << y1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0; 
}