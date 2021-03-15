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

const int oo = 1e9 + 7;
int c[26][26];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s, t;
    cin >> s >> t >> n;
    fori(i,0,26) fori(j,0,26) c[i][j] = oo; 
    fori(i,0,n) {
        char a, b; int x;
        cin >> a >> b >> x;
        c[a-'a'][b-'a'] = min(c[a-'a'][b-'a'], x);
    }
    if(sz(s) != sz(t)) {
        cout << -1 << endl;
        return 0;
    }
    fori(i,0,26) c[i][i] = 0;
    fori(k,0,26) fori(i,0,26) fori(j,0,26) {
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
    }
    int ans = 0;
    string r;
    fori(i,0,sz(s)) {
        if(s[i] != t[i]) {
            int x = s[i]-'a', y = t[i]-'a';
            bool ok = 0;
            int mn = oo, l = 0;
            fori(j,0,26) {
                if(c[x][j] != oo && c[y][j] != oo) {
                    if(c[x][j] + c[y][j] < mn) {
                        mn = c[x][j] + c[y][j];
                        l = j;
                    }
                    ok = 1;
                }
            }
            if(!ok) {
                cout << -1 << endl;
                return 0;
            }
            ans += mn;
            r += char(l + 'a');
        } else r += s[i];
    }
    cout << ans << endl << r << endl;
    return 0; 
}