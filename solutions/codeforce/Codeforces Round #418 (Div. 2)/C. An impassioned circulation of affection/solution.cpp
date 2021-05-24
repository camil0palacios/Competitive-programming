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

const int Mxn = 1500;
int p[Mxn][26], mx[Mxn][26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    fori(i,0,n) {
        fori(j,0,26) p[i+1][j] = p[i][j];
        p[i+1][s[i]-'a']++;
    }
    fori(c,0,26) {
        fore(l,1,n) {
            fore(i,1,n-l+1) {
                int x = l - (p[i+l-1][c] - p[i-1][c]);
                mx[x][c] = max(mx[x][c], l);
            }
        }
    }
    fore(i,1,n) fori(c,0,26) {
        mx[i][c] = max(mx[i][c], mx[i-1][c]); 
    }
    int q;
    cin >> q;
    while(q--) {
        int m; char c;
        cin >> m >> c;
        cout << mx[m][c-'a'] << endl;
    }
    return 0; 
}