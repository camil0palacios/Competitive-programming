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

const int Mxn = 1000;

int check(int x, int y) {
    int acc = 0;
    while(x || y) {
        acc += (x % 10) != (y % 10);
        x /= 10;
        y /= 10;
    }
    return acc;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vi sev;
    for(int i = 1; i*7 < Mxn; i++) sev.eb(i*7);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int szn = sz(to_string(n));
        int acc = 1e9, num = n;
        for(int i : sev) {
            int p = check(i, n);
            int szi = sz(to_string(i));
            if(szn == szi && p < acc) {
                acc = p;
                num = i;
            }
        }
        cout << num << endl;
    }
    return 0; 
}