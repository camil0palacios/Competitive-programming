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

int to_int(char c) { return c >= 'a' && c <= 'z' ? c - 'a' : c - 'A' + 26; }

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) { 
        string s;
        cin >> s;
        int n = sz(s);
        vi f[55];
        fori(i,0,n) f[to_int(s[i])].eb(i);
        int q;
        cin >> q;
        while(q--) {
            string t;
            cin >> t;
            int m = sz(t), j = -1;
            bool ok = 1;
            fori(i,0,m) {
                int c = to_int(t[i]);
                if(!sz(f[c])) { ok = 0; break; }
                int l = 0, r = sz(f[c])-1;
                while(l <= r) {
                    int m = (l + r) >> 1;
                    if(f[c][m] > j) r = m-1;
                    else l = m+1;
                }
                if(r+1 >= sz(f[c]) || f[c][r+1] < j) { ok = 0; break; }
                j = f[c][r+1];
            }
            cout << (ok ? "Yes" : "No") << endl;
        }
    }
    return 0; 
}