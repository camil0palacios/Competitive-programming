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

int n, m;
char a[5][5];

int count(int x, int y) {
    int cnt = 0;
    fori(i,x,n) fori(j,y,m) cnt += a[i][j] == 'R';
    return cnt;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        int r = 0;
        fori(i,0,n) fori(j,0,m) cin >> a[i][j], r += a[i][j] == 'R';
        bool ok = 0;
        fori(i,0,n) {
            fori(j,0,m) {
                if(a[i][j] == 'R' && count(i, j) == r) ok = 1;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0; 
}