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

const int N = 1010;
char a[N][N];
int p[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    fori(i,0,n) fori(j,0,m) cin >> a[i][j];
    int cnt = 0;
    fori(j,0,m) {
        fori(i,0,n) {
            if(a[i][j] == '*') {
                p[j]++;
                cnt++;
            }
        }
    }
    fori(r,0,q) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if(a[x][y] == '.') a[x][y] = '*', p[y]++, cnt++;
        else a[x][y] = '.', p[y]--, cnt--;
        int need = 0, tmp = 0, ans = 0;
        fori(j,0,m) {
            need += n;
            tmp += n - p[j];
            if(need >= cnt) {
                need -= n;
                tmp -= n - p[j];
                ans += tmp;
                fori(i,0,cnt-need) {
                    if(a[i][j] == '.') ans++;
                }
                break;
            }
        }
        cout << ans << endl;
    }
    return 0; 
}