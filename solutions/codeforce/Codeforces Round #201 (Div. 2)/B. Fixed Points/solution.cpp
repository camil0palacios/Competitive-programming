#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    fori(i,0,n) cin >> a[i];
    int ans = 0;
    fori(i,0,n) {
        ans += a[i] == i;
    }
    int mx = 0;
    fori(i,0,n) {
        if(a[i] != i) {
            int tmp = 1;
            int j = a[i];
            if(a[j] == i) tmp++;
            mx = max(mx, tmp);
        } 
    }
    cout << ans + mx << endl; 
    return 0; 
}