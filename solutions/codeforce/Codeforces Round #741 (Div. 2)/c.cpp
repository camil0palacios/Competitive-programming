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

void solve() {
    int n;
    string s;
    cin >> n >> s;
    bool ok = 1;
    fori(i,0,n) ok &= s[i] == '1';
    if(ok) {
        cout << 1 << ' ' << n-1 << ' ';
        cout << 2 << ' ' << n << endl;
        return;
    }
    fori(i,0,n/2) {
        if(s[i] == '0') {
            cout << i+1 << ' ' << n << ' ';
            cout << i+2 << ' ' << n << endl;
            return;
        }
    }
    fori(i,n/2,n) {
        if(s[i] == '0') {
            cout << 1 << ' ' << i+1 << ' ';
            cout << 1 << ' ' << i << endl;
            return;
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}