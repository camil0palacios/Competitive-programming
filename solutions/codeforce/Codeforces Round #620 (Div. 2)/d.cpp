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
bool vis[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        int x = n;
        fore(i,0,n) vis[i] = 0;
        fori(i,0,n-1) {
            if(s[i] == '>') {
                while(vis[x]) x--;
                cout << x << ' ';
                vis[x] = 1;
                while(vis[x]) x--;
            } else {
                int r = i;
                while(r < n-1 && s[r] == '<') r++;
                int k = r - i;
                int nx = x - k;
                fori(j,0,k) {
                    cout << nx << ' ';
                    vis[nx++] = 1;
                }
                i = r-1;
            }
        }
        cout << x << endl;
        x = n; 
        int y = 1;
        fore(i,0,n) vis[i] = 0;
        fori(i,0,n-1) {
            if(s[i] == '>') {
                while(vis[x]) x--;
                cout << x << ' ';
                vis[x] = 1;
                while(vis[x]) x--;
            } else {
                int r = i;
                while(r < n-1 && s[r] == '<') r++;
                int k = r - i;
                fori(j,0,k) {
                    cout << y << ' ';
                    vis[y++] = 1;
                }
                i = r-1;
            }
        }
        cout << x << endl;
    }
    return 0; 
}