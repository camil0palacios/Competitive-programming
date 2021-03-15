#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vi c(n);
        set<int> s;
        int col = 0, mx = 0;
        fori(i,0,n) {
            cin >> c[i];
            s.insert(c[i]);
        }
        int ans = 1e9;
        for(auto & col : s) { 
            int i = 0, tmp = 0;
            while(i < n) {
                if(c[i] != col) {
                    i = min(n, i + k);
                    tmp++;
                }
                else i++;
            }
            ans = min(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0; 
}