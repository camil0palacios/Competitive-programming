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
char a[Mxn][Mxn];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) fori(j,0,n) cin >> a[i][j];
    fori(i,0,n) {
        fori(j,0,n) {
            if(a[i][j] == '#') {
                bool ok = 1;
                fori(k,0,4) {
                    int mx = i + dx[k];
                    int my = j + dy[k];
                    if(mx >= 0 && mx < n && my >= 0 && my < n) ok &= a[mx][my] == '#';
                }
                if(ok) {
                    a[i][j] = '.';
                    fori(k,0,4) {
                        int mx = i + dx[k];
                        int my = j + dy[k];
                        if(mx >= 0 && mx < n && my >= 0 && my < n) a[mx][my] = '.';
                    }
                }
            }
        }
    }
    bool ok = 1;
    fori(i,0,n) fori(j,0,n)
        ok &= a[i][j] == '.';
    cout << (ok ? "YES" : "NO") << endl;
    return 0; 
}