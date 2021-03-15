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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 2e5 + 5;
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    fori(i,0,n) cin >> a[i];
    map<int,int> s;
    ll ans = 0;
    int j = 0;
    fori(i,0,n) {
        while(j < n && (s.count(a[j]) || sz(s) < k)) s[a[j++]]++;
        ans += j - i;
        s[a[i]]--;
        if(!s[a[i]]) s.erase(a[i]);
    }
    cout << ans << endl;
    return 0; 
}