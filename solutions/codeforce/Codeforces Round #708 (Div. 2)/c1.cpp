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

const int lim = 1e6 + 5;

int lcm(int a, int b) { return a*b/__gcd(a, b); }

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(n & 1) {
            int x = (n-1) / 2;
            cout << 1 << ' ' << x << ' ' << x << endl;
        } else {
            int x = n/2;
            if(x & 1) cout << 2 << ' ' << x-1 << ' ' << x-1 << endl;
            else cout << x << ' ' << x/2 << ' ' << x/2 << endl;
        }
    }
    return 0; 
}