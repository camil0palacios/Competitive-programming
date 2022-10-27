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

const int oo = 1e9;
const int Mxn = 5050;
int p[Mxn][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = sz(s);
    fori(i,0,n) {
        p[i+1][0] = p[i][0] + (s[i] == 'a');
        p[i+1][1] = p[i][1] + (s[i] == 'b');
    }
    int ans = 0;
    fore(i,0,n) {
        fore(j,i,n) {
            ans = max(ans, p[i][0] + (p[j][1] - p[i][1]) + (p[n][0] - p[j][0]));
        }
    }
    cout << ans << endl;
    return 0;
}