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
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a[6], b[6];
    fori(i,0,6) cin >> a[i];
    fori(i,0,6) cin >> b[i];
    int w = 0;
    fori(i,0,6) fori(j,0,6) 
        w += a[i] > b[j];
    int p = 36;
    int g = __gcd(w, p);
    w /= g, p /= g;
    cout << w << '/' << p << endl;
    return 0; 
}