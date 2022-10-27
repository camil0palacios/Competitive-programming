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

int to_int(char c) { return c-'0'; }

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = sz(s);
        int idx = 0;
        fori(i,1,n-1) {
            int p = (s[i]-'0')+(s[i+1]-'0');
            if(p >= 10) {
                idx = i;
            }
        }
        string ans = s.substr(0, idx);
        ans += to_string((s[idx]-'0') + (s[idx+1]-'0'));
        ans += s.substr(idx+2);
        cout << ans << endl;
    }
    return 0; 
}