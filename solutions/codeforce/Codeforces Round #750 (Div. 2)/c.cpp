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
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = 1e9;
        fori(i,0,26) {
            char c = char(i + 'a');
            int cnt = 0;
            int l = 0, r = sz(s)-1;
            while(l <= r) {
                if(s[l] == s[r]) l++, r--;
                else if(s[l] == c) cnt++, l++;
                else if(s[r] == c) cnt++, r--;
                else {
                    cnt = n+1;
                    break;
                }
            }
            ans = min(ans, cnt);
        }
        cout << (ans >= n ? -1 : ans) << endl;
    }
    return 0; 
}