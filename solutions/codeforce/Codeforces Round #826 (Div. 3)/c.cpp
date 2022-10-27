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

const int N = 2010;
int a[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> a[i];
        int mn = 1e9;
        fore(l,1,n) {
            int s = 0;
            fori(j,0,l) s += a[j];
            int x = 0, t = 0, mxt = 0;
            fori(j,0,n) {
                x += a[j];
                t++;
                if(x == s) {
                    mxt = max(mxt, t);
                    t = x = 0;
                }
            }
            if(x == 0) {
                mn = min(mn, mxt);
            }
        }
        cout << mn << endl;
    }
    return 0; 
}