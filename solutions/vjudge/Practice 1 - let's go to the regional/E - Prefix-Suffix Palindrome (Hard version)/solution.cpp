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

string solve(string & s) {
    string t = s;
    reverse(all(t));
    t = s + "#" + t;
    int n = sz(t), p[n+1], j = 0;
    memset(p, 0, sizeof p);
    fori(i,1,n) {
        while(j > 0 && t[i] != t[j]) j = p[j-1];
        if(t[i] == t[j]) j++;
        p[i] = j;
    }
    return s.substr(0, j);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        string s, t;
        cin >> s;
        int n = sz(s), idx = 0;
        fori(i,0,n/2) {
            if(s[i] != s[n-i-1]) break;
            idx++;
        }
        if(idx > 0) cout << s.substr(0, idx);
        if(sz(s) > 2*idx) {
            string t = s.substr(idx, n-2*idx);
            string r = t;
            reverse(all(r));
            string a = solve(t);
            string b = solve(r);
            if(sz(a) < sz(b)) swap(a, b);
            cout << a;
        }
        if(idx > 0) cout << s.substr(sz(s) - idx, idx);
        cout << endl;
    }
    return 0; 
}