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
int bit[Mxn][Mxn];

void upd(int x, int y, int v) {
    for(; x < Mxn; x += x & -x) {
        for(int j = y; j < Mxn; j += j & -j) {
            bit[x][j] += v;
        }
    }
}
int sum(int x, int y) {
    int ans = 0;
    for(; x; x -= x & -x) {
        for(int j = y; j; j -= j & -j) {
            ans += bit[x][j];
        }
    }
    return ans;
}
int qry(int x1, int y1, int x2, int y2) {
    return sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1);
}

bool a[Mxn][Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    fore(i,1,n) {
        fore(j,1,n) {
            char c; cin >> c;
            if(c == '*') {
                a[i][j] = 1;
                upd(i, j, 1);
            }
        }
    }
    fori(i,0,q) {
        int t; cin >> t;
        if(t == 1) {
            int x, y;
            cin >> x >> y;
            if(a[x][y]) upd(x, y, -1);
            else upd(x, y, 1);
            a[x][y] ^= 1;
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << qry(x1, y1, x2, y2) << endl;
        }
    }
    return 0; 
}