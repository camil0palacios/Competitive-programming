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
int a[Mxn];

bool check_max(int i) {
    return a[i] > a[i-1] && a[i] > a[i+1];
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> a[i];
        int ans = 0;
        fori(i,1,n-1) {
            if(check_max(i)) {
                if(i+2 < n) a[i+1] = max(a[i], a[i+2]);
                else a[i+1] = a[i];
                ans++;
            }
        }
        cout << ans << endl;
        fori(i,0,n) cout << a[i] << ' ';
        cout << endl;
    }
    return 0; 
}