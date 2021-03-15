#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int a[3][3];

bool check() {
    int s1 = 0, s2 = 0;
    fori(i,0,3) s1 += a[i][0], s2 += a[0][i]; 
    if(s1 != s2) return 0;
    int x = s1 - a[1][0] - a[1][2];
    int y = s1 - a[0][1] - a[2][1];
    if(x != y || x <= 0) return 0;
    a[1][1] = x;
    x = s1 - a[2][0] - a[2][1];
    y = s1 - a[0][2] - a[1][2];
    if(x != y || x <= 0) return 0;
    a[2][2] = x;
    x = y = 0;
    fori(i,0,3) x += a[i][i];
    for(int i = 0, j = 2; i < 3; i++, j--) y += a[i][j];
    return x == y;
}   

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fori(i,0,3) fori(j,0,3) cin >> a[i][j];
    for(int i = 1; i <= 1e5; i++) {
        a[0][0] = i;
        if(check()) break;
    }
    fori(i,0,3) {
        fori(j,0,3) cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0; 
}