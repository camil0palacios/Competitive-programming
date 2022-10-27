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

const int Mxn = 55;
int a[Mxn][Mxn];

void solve() {
    int n, m, A, B;
    cin >> n >> m >> A >> B;
    int x = n + m - 2;
    if(A - x <= 0 || B - x <= 0) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        fori(i,0,n) fori(j,0,m) {
            a[i][j] = 1;
        }
        a[n-1][m-1] = A - x;
        a[n-1][0] = B - x;
        fori(i,0,n) {
            fori(j,0,m) cout << a[i][j] << ' ';
            cout << endl;
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}