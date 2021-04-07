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

const int Mxn = 303;
vi g[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int x = 1, d = 1;
    fore(i,1,n*n) {
        if(x == n+1 || x == 0) {
            d *= -1;
            x += d;
        }
        g[x].eb(i);
        x += d;
    }
    fore(i,1,n) {
        fori(j,0,n) cout << g[i][j] << ' ';
        cout << endl;
    }
    return 0; 
}