#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a, b) for (int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

// typedef __int128_t i128; only for extreme cases
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int p[35][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, l;
        cin >> n >> l;
        memset(p, 0, sizeof p);
        fori(i,0,n) {
            int x;
            cin >> x;
            fori(j,0,l) {
                p[j][(x >> j) & 1]++;
            }
        }
        int ans = 0;
        fori(i,0,l) {
            if (p[i][0] < p[i][1])
                ans |= (1 << i); 
        }
        cout << ans << endl;
    }
    return 0;
}