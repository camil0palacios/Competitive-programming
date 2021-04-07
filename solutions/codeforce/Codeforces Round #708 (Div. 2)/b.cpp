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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1e5 + 5;
int a[Mxn];
int cnt[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        fore(i,0,m) cnt[i] = 0;
        int ans = 0;
        fori(i,0,n) cin >> a[i];
        fori(i,0,n) a[i] %= m, cnt[a[i] % m]++;
        fori(i,1,m) {
            if(i < m-i && cnt[i]+cnt[m-i] > 0) {
                if(cnt[i] == cnt[m-i]) ans++;
                else ans += max(cnt[i], cnt[m-i]) - min(cnt[i], cnt[m-i]);
            }
        }
        if(cnt[0]) ans++;
        if(m%2 == 0 && cnt[m/2]) ans++;
        cout << ans << endl;
    }
    return 0; 
}