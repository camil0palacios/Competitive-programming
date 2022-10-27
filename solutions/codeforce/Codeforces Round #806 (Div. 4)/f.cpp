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
ii a[N];
int s[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,0,n) s[i] = 0;
        fori(i,0,n) {
            cin >> a[i].ft;
            a[i].sd = i+1;
        }
        sort(a, a+n);
        ll ans = 0;
        forr(i,n-1,0) {
            if(a[i].ft < a[i].sd) {
                int idx = lower_bound(a, a+n, mp(a[i].sd+1, 0)) - a;
                if(idx != n) ans += s[idx];
                s[i]++;
            }
            s[i] += s[i+1];
        }
        cout << ans << endl;
    }
    return 0; 
}