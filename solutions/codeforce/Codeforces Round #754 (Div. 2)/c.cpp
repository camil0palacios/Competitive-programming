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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1e6 + 5;
int p[Mxn][3];
int nxt[4] = {1, 2, 3, 6};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        fore(i,0,n) fori(j,0,3) p[i][j] = 0;
        fori(i,0,n) {
            int c = s[i]-'a';
            fori(j,0,3) p[i+1][j] += p[i][j];
            p[i+1][c]++;
        }
        int ans = 1e9;
        fori(i,1,n) {
            fori(j,0,4) {
                int x = i + nxt[j];
                if(x <= n && 
                    p[x][0] - p[i-1][0] > p[x][1] - p[i-1][1] &&
                    p[x][0] - p[i-1][0] > p[x][2] - p[i-1][2]) {
                    ans = min(ans, x-i+1);
                }
            }
        }
        cout << (ans != 1e9 ? ans : -1) << endl;
    }
    return 0; 
}