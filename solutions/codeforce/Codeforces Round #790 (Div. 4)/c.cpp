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

string a[55];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        fori(i,0,n) cin >> a[i];
        int ans = 1e9;
        fori(i,0,n) {
            fori(j,i+1,n) {
                int tmp = 0;
                fori(k,0,m) {
                    char x = a[i][k];
                    char y = a[j][k];
                    if(x > y) swap(x, y);
                    tmp += (y-'a') - (x-'a');
                }
                ans = min(ans, tmp);
            }
        }
        cout << ans << endl;
    }
    return 0; 
}