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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        fori(i,0,n) cin >> a[i];
        sort(a, a+n, greater<int>());
        fori(i,1,n) a[i] += a[i-1];
        fori(i,0,q) {
            int x; cin >> x;
            int it = lower_bound(a, a+n, x) - a;
            if(it == n) cout << -1 << endl;
            else cout << it+1 << endl;
        }
    }
    return 0; 
}