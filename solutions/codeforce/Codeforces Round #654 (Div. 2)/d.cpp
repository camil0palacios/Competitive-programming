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

const int Mxn = 305;
int a[Mxn][Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        fori(i,0,n) fori(j,0,n) a[i][j] = 0;
        if(k % n == 0) cout << 0 << endl;
        else cout << "2" << endl;
        int i = 0, j = 0;
        fori(x,0,k) {
            a[i][j] = 1;
            i++, j = (j + 1) % n;
            if(i == n) i = 0, j = (j + 1) % n;
        }
        fori(i,0,n) {
            fori(j,0,n) cout << a[i][j];
            cout << endl;
        }
    } 
    return 0; 
}