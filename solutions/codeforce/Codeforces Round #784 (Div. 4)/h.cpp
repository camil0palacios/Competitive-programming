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
int a[N];
int cnt[30];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        fore(i,0,30) cnt[i] = 0;
        fori(i,0,n) cin >> a[i];
        fori(i,0,n) {
            fore(j,0,30) cnt[j] += (a[i] >> j) & 1;
        }
        int mx = 0;
        forr(i,30,0) {
            if((n - cnt[i]) <= k) {
                mx |= (1 << i);
                k -= (n - cnt[i]);
            }
        }
        cout << mx << endl;
    }
    return 0; 
}