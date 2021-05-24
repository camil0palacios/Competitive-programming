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
int a[Mxn], l[Mxn], r[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fore(i,1,n) cin >> a[i];
    a[n+1] = 1e9;
    fore(i,1,n) l[i] = r[i] = 1;
    forr(i,n-1,1) {
        if(a[i] < a[i+1]) r[i] += r[i+1];
    }
    fore(i,2,n) {
        if(a[i-1] < a[i]) l[i] += l[i-1];
    }
    int ans = 0;
    fore(i,1,n) ans = max(ans, l[i]);
    if(ans < n) ans++;
    fore(i,1,n) {
        if(a[i-1]+1 < a[i+1])
            ans = max(ans, l[i-1]+r[i+1]+1);
    }
    cout << ans << endl;
    return 0; 
}   