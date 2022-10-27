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
int a[N];
int cnt[10];

void solve() {
     int n;
    cin >> n;
    memset(cnt, 0, sizeof cnt);
    fori(i,0,n) {
        cin >> a[i];
        cnt[a[i] % 10]++;
    }
    fori(i,0,10) fori(j,i,10) fori(k,j,10) {
        if((i + j + k) % 10 == 3) {
            bool ok = 0;
            if(i == j && j == k && cnt[i] >= 3) ok = 1;
            if(i == j && i != k && cnt[i] >= 2 && cnt[k]) ok = 1;
            if(j == k && i != j && cnt[j] >= 2 && cnt[i]) ok = 1;
            if(i != j && i != k && j != k && cnt[i] && cnt[j] && cnt[k]) ok = 1;
            if(ok) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}


int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}