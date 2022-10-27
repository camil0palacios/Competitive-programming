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

int t[26][26], r[26][26];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        fori(i,0,26) fori(j,0,26) t[i][j] = 0;
        ll ans = 0;
        fori(i,0,n) {
            string s;
            cin >> s;
            fori(l,0,26) {
                ans += l != s[1]-'a' ? t[s[0]-'a'][l] : 0;
            }
            fori(l,0,26) {
                ans += l != s[0]-'a' ? t[l][s[1]-'a'] : 0;
            }
            t[s[0]-'a'][s[1]-'a']++;
        }
        cout << ans << endl;
    }
    return 0; 
}