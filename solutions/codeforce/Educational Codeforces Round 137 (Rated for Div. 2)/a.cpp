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
        int n;
        cin >> n;
        int s[10];
        fore(i,0,9) s[i] = 0;
        fori(i,0,n) {
            int a; cin >> a;
            s[a] = 1;
        }
        int ans = 0;
        fore(i,0,9) {
            fore(j,0,9)
            fore(k,0,9)
            fore(x,0,9)
                if(!s[i] && !s[j] && !s[k] && !s[x] && (
                    (i == j && i != k && k == x) ||
                    (i == k && i != j && j == x) || 
                    (i == x && i != j && j == k)
                )) ans++;
        }
        cout << ans << endl;
    }
    return 0; 
}