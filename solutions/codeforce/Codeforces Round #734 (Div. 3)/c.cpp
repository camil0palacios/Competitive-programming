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

const int Mxn = 2e5 + 5;
string a[Mxn];

int cnt_let(string & s, int x) {
    int ans = 0;
    fori(i,0,sz(s)) ans += (s[i]-'a') == x;
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        fori(i,0,n) cin >> a[i];
        int ans = 0;
        fori(c,0,5) {
            sort(a, a+n, [&](string s, string t) {
                int c1 = cnt_let(s, c);
                int c2 = cnt_let(t, c);
                int d1 = sz(s) - c1, d2 = sz(t) - c2; 
                // return c1 - d1 > c2 - d2; 
                return 2*c1 - sz(s) > 2*c2 - sz(t);
            });
            int cnt = 0, r = 0;
            fori(i,0,n) {
                int x = cnt_let(a[i], c); 
                cnt += x;
                r += sz(a[i]) - x;
                if(r < cnt) {
                    ans = max(ans, i+1);
                }
            }
        }
        cout << ans << endl;
    }
    return 0; 
}