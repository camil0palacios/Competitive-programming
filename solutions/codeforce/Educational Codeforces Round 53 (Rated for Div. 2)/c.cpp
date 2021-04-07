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

const int Mxn = 2e5 + 5;
int n, x, y;
int p[Mxn][4];

bool can(int px, int py, int t) {
    int d = abs(px - x) + abs(py - y);
    if(d % 2 != t % 2) return 0;
    return t >= d;
}

bool check(int t) {
    fore(i,t,n) {
        int px = p[n][2] - (p[i][2] - p[i-t][2]);
        px -= p[n][3] - (p[i][3] - p[i-t][3]);
        int py = p[n][0] - (p[i][0] - p[i-t][0]);
        py -= p[n][1] - (p[i][1] - p[i-t][1]);
        if(can(px, py, t)) return 1;
    }
    return 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> n >> s;
    fori(i,0,n) {
        fori(j,0,4) p[i+1][j] = p[i][j];
        if(s[i] == 'U') p[i+1][0]++;
        if(s[i] == 'D') p[i+1][1]++;
        if(s[i] == 'R') p[i+1][2]++;
        if(s[i] == 'L') p[i+1][3]++;
    }
    cin >> x >> y;
    int ans = -1;
    int l = 0, r = n;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(check(m)) ans = m, r = m-1;
        else l = m+1;
    }
    cout << ans << endl;
    return 0;
}