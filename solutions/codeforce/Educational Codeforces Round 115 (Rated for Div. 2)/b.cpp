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

const int Mxn = 1010;
int a[Mxn][5];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) 
            fori(j,0,5) cin >> a[i][j];
        bool ok = 0;
        fori(l,0,5) {
            fori(r,l+1,5) {
                int g1 = 0, g2 = 0, b = 0;
                fori(i,0,n) {
                    if(a[i][l] && a[i][r]) b++;
                    else if(a[i][l]) g1++;
                    else if(a[i][r]) g2++;
                }
                int mn = min(b, max(0,n/2 - g1));
                g1 += mn;
                b -= mn;
                mn = min(b, max(0, n/2 - g2));
                g2 += mn;
                b -= mn;
                if(g1 == g2 && g1 == n/2 && b == 0) {
                    ok = 1;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0; 
}