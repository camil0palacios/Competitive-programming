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
int a[N], p[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        fori(i,0,n) cin >> a[i];
        fori(i,0,n) p[i+1] = p[i] + a[i];
        int ans = 1e9;
        fore(i,1,n) {
            int l = i, r = n, id = -1;
            while(l <= r) {
                int m = (l + r) >> 1;
                if(p[m] - p[i-1] <= s) id = m, l = m+1;
                else r = m-1;
            }
            if(id != -1 &&  p[id] - p[i-1] == s) {
                ans = min(ans, i-1 + n - id);
            }
        } 
        cout << (ans != 1e9 ? ans : -1) << endl;
    }
    return 0; 
}