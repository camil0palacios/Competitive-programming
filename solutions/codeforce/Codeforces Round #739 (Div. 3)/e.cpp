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

const int Mxn = 5e5 + 5;
vector<char> ord;
int p[Mxn][26];

string del_char(string & s, char c) {
    string t;
    fori(i,0,sz(s)) if(s[i] != c) t += s[i];
    return t;
}

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    ord.clear();
    fore(i,0,n+1) fori(j,0,26) p[i][j] = 0;
    fori(i,0,n) {
        fori(j,0,26) p[i+1][j] = p[i][j];
        p[i+1][s[i]-'a']++;
    }
    set<char> st;
    forr(i,n-1,0) {
        if(!st.count(s[i])) {
            ord.eb(s[i]);
            st.insert(s[i]);
        }
    }
    reverse(all(ord));
    // for(auto c : ord) cout << c << endl;
    fori(i,0,n) {
        bool ok = 1;
        fori(l,0,sz(ord)) {
            char c = ord[l] - 'a';
            ok &= p[i+1][c]*l == p[n][c] - p[i+1][c];
        }
        if(ok) {
            string p = s.substr(0, i+1);
            string tmp = p;
            for(auto & c : ord) {
                p = del_char(p, c);
                tmp += p;
            }
            if(tmp != s) {
                cout << -1 << endl;
                return;
            }
            cout << s.substr(0, i+1) << ' ';
            for(auto & c : ord) cout << c;
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}