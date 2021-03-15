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

int query(int l, int r) {
    if(l == r) return -1;
    cout << "? " << l << ' ' << r << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

int main() { 
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    int x = query(1, n);
    if(query(1, x) == x) {
        int l = 1, r = x-1;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(query(m, x) == x) ans = m, l = m+1;
            else r = m-1;
        }
    } else {
        int l = x+1, r = n;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(query(x, m) == x) ans = m, r = m-1;
            else l = m+1;
        }
    }
    cout << "!" << ' ' << ans << endl;
    return 0; 
}