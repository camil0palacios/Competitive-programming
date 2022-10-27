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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string v[4] = {"00", "25", "50", "75"};
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = sz(s);
        int ans = 1e9;
        fori(p,0,4) {
            fori(i,0,n) {
                fori(j,i+1,n) {
                    if(s[i] == v[p][0] && s[j] == v[p][1]) {
                        ans = min(ans, j-i-1 + n-j-1);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0; 
}