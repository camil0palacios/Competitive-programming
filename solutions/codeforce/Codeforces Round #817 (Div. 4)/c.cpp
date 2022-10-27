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

const int N = 1e5 + 5;
string a[3][N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<string> s[3];
        fori(i,0,3) {
            fori(j,0,n) {
                cin >> a[i][j];
                s[i].insert(a[i][j]);
            }
        }
        fori(i,0,3) {
            int ans = 0;
            fori(j,0,n) {
                int cnt = 0;
                fori(k,0,3) {
                    if(s[k].count(a[i][j])) cnt++;
                }
                if(cnt == 1) ans += 3;
                if(cnt == 2) ans++;
            }
            cout << ans << ' ';
        }
        cout << endl;
    }
    return 0; 
}