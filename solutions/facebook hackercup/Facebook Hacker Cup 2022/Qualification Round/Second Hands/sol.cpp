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

const int N = 110;
int S[N], cnt[N];

void solve() {
    int n, k;
    cin >> n >> k;
    fori(i,0,N) cnt[i] = 0; 
    fori(i,0,n) {
        int s; cin >> s;
        cnt[s]++;
    }
    int one = 0, two = 0;
    fore(i,1,N) {
        if(cnt[i] == 1) one++;
        if(cnt[i] == 2) two++;
        if(cnt[i] >= 3) {
            cout << "NO" << endl;
            return;
        }
    }
    if((one+1)/2 + two > k) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}