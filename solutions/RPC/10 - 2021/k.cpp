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

int count_div(int n) {
    int cnt = 2;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            cnt++;
            if(n / i != i) cnt++;
        }
    }
    return cnt;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 1, cnt = 1;
        fore(i,2,n) {
            int pos = count_div(i);
            if(cnt < pos) {
                ans = i;
                cnt = pos;
            }
        }
        cout << ans << endl;
    }
    return 0; 
}