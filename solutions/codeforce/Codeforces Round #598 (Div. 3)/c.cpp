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

const int Mxn = 1e5;
int c[Mxn];
int ans[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, d;
    cin >> n >> m >> d;
    int s = 0;
    fori(i,0,m) cin >> c[i], s += c[i];
    fore(i,1,n) ans[i] = 0;
    int p = 0, j = 0;
    while(p < n+1) {
        bool ok = 0;
        if(j < m) {
            forr(i,p+d,p+1) {
                int x = i + c[j] - 1;
                if(n - x >= s - c[j]) {
                    p = x;
                    fore(k,i,x) ans[k] = j+1;
                    s -= c[j++];
                    ok = 1;
                    break;
                }
            }
        } 
        else if(p + d >= n+1) {
            ok = 1;
            p += d;
        }
        if(!ok) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    fore(i,1,n) cout << ans[i] << ' ';
    cout << endl;
    return 0; 
}