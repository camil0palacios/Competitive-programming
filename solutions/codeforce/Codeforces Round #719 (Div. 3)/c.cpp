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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
const int Mxn = 105;
int a[Mxn][Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi v;
        fori(i,0,n) fori(j,0,n) a[i][j] = 0;
        fore(i,1,n*n) v.eb(i);
        int x = 0, y = n*n-1;
        fori(i,0,n) fori(j,0,n) {
            if((i+j)&1) a[i][j] = v[x++];
            else a[i][j] = v[y--];
        }
        swap(a[0][0], a[n-1][n-1]);
        bool ok = 1;
        fori(i,0,n) fori(j,0,n) {
            fori(k,0,4) {
                int mx = i + dx[k];
                int my = j + dy[k];
                if(mx >= 0 && mx < n && my >= 0 && my < n) {
                    ok &= abs(a[i][j] - a[mx][my]) != 1;
                }
            }
        }
        if(ok) {
            fori(i,0,n) {
                fori(j,0,n) cout << a[i][j] << ' ';
                cout << endl;
            }
        } else cout << -1 << endl;
    }
    return 0; 
}