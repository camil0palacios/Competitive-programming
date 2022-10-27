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
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        vi o;
        int ones = 0; 
        fori(i,0,n) {
            if(s[i] == '1') o.eb(i), ones++;
        }
        int ans = 0;
        if(ones > 0 && k >= (n - o.back() - 1)) {
            k -= (n - o.back() - 1);
            ans += 1;
            ones--;
        }
        if(ones > 0 && k >= o[0]) {
            k -= o[0];
            ans += 10;
            ones--;
        }
        cout << 11*ones + ans << endl;
    }
    return 0; 
}