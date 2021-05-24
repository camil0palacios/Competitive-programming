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

const int Mxn = 404;
char a[Mxn][Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vii pos;
        fori(i,0,n) {
            fori(j,0,n) {
                cin >> a[i][j];
                if(a[i][j] == '*') {
                    pos.eb(i, j);
                }
            }
        }
        sort(all(pos));
        int x1 = pos[0].ft, y1 = pos[0].sd;
        int x2 = pos[1].ft, y2 = pos[1].sd;
        if(x1 == x2) {
            if(x1+1 < n) {
                a[x1+1][y1] = '*';
                a[x2+1][y2] = '*';
            } else {
                a[x1-1][y1] = '*';
                a[x2-1][y2] = '*';
            }
        }
        else if(y1 == y2) {
            if(y1+1 < n) {
                a[x1][y1+1] = '*';
                a[x2][y2+1] = '*';
            } else {
                a[x1][y1-1] = '*';
                a[x2][y2-1] = '*';
            }
        } else {
            a[x1][y2] = '*';
            a[x2][y1] = '*'; 
        }
        fori(i,0,n) {
            fori(j,0,n) cout << a[i][j];
            cout << endl;
        } 
    }
    return 0; 
}