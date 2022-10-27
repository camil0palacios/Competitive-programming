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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int getSq(int x) {
    int i = 0;
    for(; i*i < x; i++) {}
    return i*i;
}

void solve() {
    int n;
    cin >> n;
    int p[n], r = n-1;
    while(r >= 0) {
        int x = getSq(r);
        if(x - r > r) {
            cout << -1 << endl;
            return;
        } 
        fore(i,x-r,r) p[i] = x - i;
        r = (x - r) - 1;
    }
    fori(i,0,n) cout << p[i] << ' ';
    cout << endl;

}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}