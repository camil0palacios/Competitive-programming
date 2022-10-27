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

int lcm(int x, int y) { return x / __gcd(x, y) * y;}

const int Mxn = 1e5 + 5;
int a[Mxn], p[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> a[i];
        int str = 0;
        if(n % 2 != 0) {
            if(a[0] + a[1] != 0) cout << -a[2] << ' ' << -a[2] << ' ' << a[0]+a[1] << ' ';
            else if(a[0] + a[2] != 0) cout << -a[1] << ' ' << a[0]+a[2] << ' ' << -a[1] << ' ';
            else cout << a[1]+a[2] << ' ' << -a[0] << ' ' << -a[0] << ' ';
            str = 3;
        }
        for(int i = str; i < n; i += 2) {
            cout << a[i+1] << ' ';
            cout << -a[i] << ' ';
        }
        cout << endl;
    }
    return 0; 
}