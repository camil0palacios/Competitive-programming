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

const int N = 2020;
char c[N][N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int cnt = 0;
        fori(i,0,n) fori(j,0,n) cin >> c[i][j], cnt += c[i][j] == '1';
        int ans = 1e9;
        fori(p,0,n) {
            int tmp = 0;
            int i = 0, j = p;
            fori(q,0,n) {
                tmp += c[i][j] == '1';
                i = (i+1) % n;
                j = (j+1) % n;
            }
            ans = min(ans, (cnt - tmp) + (n - tmp));
        }
        cout << ans << endl;
    }
    return 0; 
}