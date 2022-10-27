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

const int N = 33;
ll c[N][N];

void calc() {
    c[0][0] = 1;
    fori(i,1,N) {
        fore(j,0,i) {
            c[i][j] = c[i-1][j] + (j ? c[i-1][j-1] : 0);
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    calc();
    int n, m, t;
    cin >> n >> m >> t;
    ll ans = 0;
    fore(i,4,n) {
        fore(j,1,m) {
            if(i + j != t) continue;
            ans += c[n][i]*c[m][j];
        }
    }
    cout << ans << endl;
    return 0; 
}