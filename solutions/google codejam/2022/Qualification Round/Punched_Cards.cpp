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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    fore(t,1,T) {
        int n, m;
        cin >> n >> m;
        char a[2*n+1][2*m+1];
        fori(i,0,2*n+1) {
            fori(j,0,2*m+1) {
                if(i & 1) a[i][j] = (j & 1) ? '.' : '|';
                else a[i][j] = (j & 1) ? '-' : '+';
            }
            
        }
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = '.';
        cout << "Case #" << t << ": " << endl;
        fori(i,0,2*n+1) {
            fori(j,0,2*m+1) cout << a[i][j];
            cout << endl;
        }
    }
    return 0; 
}