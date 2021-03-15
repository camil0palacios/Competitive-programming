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
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int d;
        cin >> d;
        vi p;
        for(int i = d + 1; ; i++) {
            bool ok = 1;
            for(int j = 2; j*j <= i; j++) {
                if(i % j == 0) { ok = 0; break; }
            }
            if(ok) { p.eb(i); break; }
        }
        for(int i = p.back() + d; ;i++) {
            bool ok = 1;
            for(int j = 2; j*j <= i; j++) {
                if(i % j == 0) { ok = 0; break; }
            }
            if(ok) { p.eb(i); break; }
        }
        cout << min(1ll*p[0]*p[1], 1ll*p[0]*p[0]*p[0]) << endl;
    }
    return 0; 
}