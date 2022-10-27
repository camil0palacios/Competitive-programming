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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; string s;
        cin >> n >> s;
        int ans = 0;
        fori(i,0,n) {
            int x = 0, y = 0;
            int c = 0, p = 0;
            fori(j,i,n) {
                if(s[j] == '+') y++, c = 0;
                if(s[j] == '-') {
                    c++, p++;
                    if(c % 2 == 0) x += 2;
                } 
                int r = p - x;
                int k = (r + x - y) / 3;
                if(r + x - 2*k == y + k && k >= 0) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0; 
}