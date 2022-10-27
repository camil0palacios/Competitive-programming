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

const int Mxn = 1e5 + 5;
map<string, bool> to;

void sol() {
    int n;
    cin >> n;
    to.clear();
    bool ok = 0;
    fori(i,0,n) {
        string s;
        cin >> s;
        int m = sz(s);
        if(s[0] == s[m-1]) ok = 1;
        to[s] = 1;
        reverse(all(s));
        if(to[s] || (m == 3 && to[s.substr(0, 2)])) ok = 1;
        fori(i,0,26) {
            if(to[s+char(i+'a')]) ok = 1;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) sol();
    return 0; 
}