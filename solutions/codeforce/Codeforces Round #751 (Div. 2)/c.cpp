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

const int Mxn = 2e5 + 5;
int a[Mxn], bit[30];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> a[i];
        fori(i,0,30) bit[i] = 0;
        fori(i,0,n) {
            fori(j,0,30) {
                if((a[i] >> j) & 1) bit[j]++;
            }
        }
        vi ans;
        fore(i,1,n) {
            int ok = 1;
            fori(j,0,30) ok &= bit[j] % i == 0;
            if(ok) ans.eb(i);
        }
        for(auto & i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0; 
}