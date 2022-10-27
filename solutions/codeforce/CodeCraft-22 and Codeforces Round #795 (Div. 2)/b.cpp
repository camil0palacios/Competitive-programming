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
int a[N], p[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,1,n) cin >> a[i], p[i] = i;
        bool ok = 1;
        fore(i,1,n) {
            int r = i;
            while(r <= n && a[i] == a[r]) r++;
            r--;
            if(i == r) ok = 0;
            else rotate(p+i, p+i+1, p+r+1);
            i = r;
        }
        if(ok) {
            fore(i,1,n) cout << p[i] << ' ';
            cout << endl;
        } else cout << -1 << endl;
    }
    return 0; 
}