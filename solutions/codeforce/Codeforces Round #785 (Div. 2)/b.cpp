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

int n;
int cnt[26];

bool equal(string & s) {
    bool ok = 1;
    fori(i,1,n) ok &= s[i] == s[i-1];
    return ok;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = sz(s);
        int x = 0;
        set<int> c;
        fori(i,0,n) {
            if(c.count(s[i])) break;
            c.insert(s[i]);
            x++;
        }
        bool ok = 1;
        fori(i,x,n) {
            ok &= s[i] == s[i-x];
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0; 
}