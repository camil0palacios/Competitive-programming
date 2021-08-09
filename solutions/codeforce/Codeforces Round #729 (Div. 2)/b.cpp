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
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if(a == 1) {
            if((n-1) % b == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            ll t = 1;
            bool ok = 0;
            while(t <= n) {
                if(t%b == n%b) {
                    ok = 1;
                    break;
                }
                t *= a;
            }
            cout << (ok ? "Yes" : "No") << endl;
        }
    }
    return 0; 
}