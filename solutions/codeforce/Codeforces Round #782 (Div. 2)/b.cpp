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

const int N = 2e5 + 5;
int last[N];
int ans[N];

int toogle(char c) {
    return c == '1' ? '0' : '1';    
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        fori(i,0,n) ans[i] = 0;
        int tmp = k;
        for(int i = 0; i < n && tmp > 0; i++) {
            if(k%2 == s[i]-'0') {
                ans[i] = 1;
                tmp--;
            }
        }
        ans[n-1] += tmp;
        fori(i,0,n) {
            if((k - ans[i]) % 2 == 1) {
                s[i] = '1' - (s[i] - '0');
            }
        }
        cout << s << endl;
        fori(i,0,n) cout << ans[i] << ' ';
        cout << endl;
    }
    return 0; 
}