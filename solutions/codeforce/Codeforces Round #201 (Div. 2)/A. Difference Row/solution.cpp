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
    sort(all(a));
    cout << a[sz(a)-1] << ' ';
    fori(i,1,n-1) cout << a[i] << ' ';
    cout << a[0] << endl;
    return 0; 
}