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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int d1 = b - a, d2 = c - b, d3 = c - a;
        if((b + d1 == c) || 
          (b + d1 > 0 && (b + d1) % c == 0) || 
          (b - d2 > 0 && (b - d2) % a == 0) || 
          (d3 % 2 == 0 && a + d3/2 > 0 && (a + d3/2) % b == 0)) {
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
    return 0; 
}