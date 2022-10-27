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
        int n, s, k;
        cin >> n >> s >> k;
        set<int> b;
        fori(i,0,k) {
            int a; cin >> a;
            b.insert(a);
        }
        int ans = 1e9;
        fore(i,max(1, s-k-1),s) {
            if(!b.count(i)) ans = min(ans, s-i);
        }
        fore(i,s,min(s+k+1,n)) {
            if(!b.count(i)) ans = min(ans, i-s);
        }
        cout << ans << endl;
    }
    return 0; 
}