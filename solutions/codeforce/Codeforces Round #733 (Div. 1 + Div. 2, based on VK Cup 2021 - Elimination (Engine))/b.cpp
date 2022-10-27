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

int n, m;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int a[22][22];

bool check(int i, int j) {
    fori(k,0,8) {
        int mx = i + dx[k];
        int my = j + dy[k];
        if(mx >= 0 && mx < n && my >= 0 && my < m && a[mx][my]) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(a, 0, sizeof a);
        fori(j,0,m) {
            if(check(0, j)) a[0][j] = 1;
        }
        fori(i,0,n) {
            if(check(i, m-1)) a[i][m-1] = 1;
        }
        forr(j,m-1,0) {
            if(check(n-1, j)) a[n-1][j] = 1;
        }
        forr(i,n-1,0) {
            if(check(i, 0)) a[i][0] = 1;
        }
        fori(i,0,n) {
            fori(j,0,m) cout << a[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0; 
}