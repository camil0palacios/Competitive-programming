#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n), b(n);
    fori(i,0,n) cin >> a[i], b[i] = a[i];
    sort(all(b));
    int acc = 0;
    fori(i,0,n) {
        if(a[i] != b[i]) acc++;
    }
    cout << (acc == 0 || acc == 2 ? "YES" : "NO") << endl;
    return 0; 
}