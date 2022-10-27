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

const int N = 5050;
int a[N];
int p[N][N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,0,n+2) fore(j,0,n+2) p[i][j] = 0;
        fore(i,1,n) cin >> a[i];
        fore(i,1,n) {
            int acc = 0;
            forr(j,n,i+1) {
                p[i][j] = acc;
                acc += a[i] > a[j];
            }
        }
        ll ans = 0;
        fore(i,2,n-1) {
            ll acc = 0, s = 0;
            forr(j,i-1,1) {
                if(j+1 < i && a[j] < a[i]) {
                    acc += s;
                } 
                s += p[j][i];
            }
            ans += acc;
        }
        cout << ans << endl;
    }
    return 0; 
}