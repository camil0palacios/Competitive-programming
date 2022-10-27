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
        string s;
        cin >> s;
        int n = sz(s);
        if((s[n-1]-'0') % 2 == 0) cout << 0 << endl;
        else if((s[0]-'0') % 2 == 0) cout << 1 << endl;
        else {
            bool ok = 0;
            fori(i,0,n) {
                ok |= (s[i]-'0') % 2 == 0;
            }
            cout << (ok ? 2 : -1) << endl;
        }
    }
    return 0; 
}