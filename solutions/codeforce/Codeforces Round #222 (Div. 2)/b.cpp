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
int a[N], b[N];
int ans[2][N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<ar<int, 3>> v;
    fori(i,0,n) {
        cin >> a[i] >> b[i];
        v.push_back({a[i], 0, i});
        v.push_back({b[i], 1, i});
    }
    sort(all(v));
    fori(i,0,n) ans[v[i][1]][v[i][2]] = 1;
    fori(i,0,n/2) {
        ans[0][i] = 1;
        ans[1][i] = 1;
    }
    fori(i,0,2) {
        fori(j,0,n) cout << ans[i][j];
        cout << endl;
    }
    return 0; 
}