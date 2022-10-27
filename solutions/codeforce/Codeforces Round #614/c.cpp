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

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

const int Mxn = 1e5 + 5;
int a[3][Mxn];

ii ord(int x1, int y1, int x2, int y2) {
    ii p;
    if(x1 == 1) p = {y1, y2};
    else p = {y2, y1};
    return p;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    set<ii> s;
    fori(i,0,q) {
        int x, y;
        cin >> x >> y;
        fori(j,0,8) {
            int mx = x + dx[j];
            int my = y + dy[j];
            if(mx < 1 || mx > 2 || my < 1 || my > n || x == mx) continue;
            if(a[x][y] && a[mx][my]) s.erase(ord(x, y, mx, my));
            if(!a[x][y] && a[mx][my]) s.insert(ord(x, y, mx, my));
        }
        if(sz(s)) cout << "No" << endl;
        else cout << "Yes" << endl; 
        a[x][y] ^= 1;
    }
    return 0; 
}