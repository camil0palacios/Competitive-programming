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
ll p[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        fore(i,1,n) cin >> a[i];
        n++;
        a[n] = 2e9;
        fore(i,1,n) {
            p[i] = a[i] + p[i-1];
            a[i] = max(a[i], a[i-1]);
        }
        fori(i,0,q) {
            int k; cin >> k;
            int j = upper_bound(a, a+n, k) - a;
            cout << p[j-1] << ' ';
        }
        cout << endl;
    }
    return 0; 
}