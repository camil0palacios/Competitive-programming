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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> a(n);
        fori(i,0,n) cin >> a[i];
        vector<pair<ii, int>> pos;
        fori(i,0,n) {
            fori(j,0,m) {
                if(a[i][j] == '*') {
                    int x = i-1, y = j-1;
                    int cnt1 = 0, cnt2 = 0;
                    while(x >= 0 && y >= 0 && a[x][y] == '*') x--, y--, cnt1++;
                    x = i-1, y = j+1;
                    while(x >= 0 && y < m && a[x][y] == '*') x--, y++, cnt2++;
                    if(min(cnt1, cnt2) >= k) {
                        pos.eb(mp(i, j), min(cnt1, cnt2));
                    }
                }
            }
        }
        vector<string> b(n, string(m, '.'));
        for(auto & p : pos) {
            int i = p.ft.ft, j = p.ft.sd, d = p.sd;
            b[i][j] = '*';
            int x = i-1, y = j-1;
            fori(i,0,d) b[x--][y--] = '*';
            x = i-1, y = j+1;
            fori(i,0,d) b[x--][y++] = '*';
        }
        cout << (a == b ?  "YES" : "NO") << endl;
    }
    return 0; 
}