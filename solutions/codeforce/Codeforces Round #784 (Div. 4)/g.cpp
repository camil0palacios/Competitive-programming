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

const int N = 55;
char a[N][N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        fori(i,0,n) fori(j,0,m) cin >> a[i][j];
        fori(i,0,m) a[n][i] = 'o';
        fori(j,0,m) {
            int cnt = 0;
            fore(i,0,n) {
                if(a[i][j] == '*') cnt++;
                if(a[i][j] == 'o') {
                    int k = i-1;
                    while(k >= 0 && a[k][j] != 'o') {
                        if(cnt) a[k][j] = '*', cnt--;
                        else a[k][j] = '.';
                        k--;
                    } 
                }
            }
        }
        fori(i,0,n) {
            fori(j,0,m) cout << a[i][j];
            cout << endl;
        }
    }
    return 0; 
}