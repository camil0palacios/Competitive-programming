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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll a, b;
    cin >> a >> b;
    int d[3] = {2, 3, 5};
    int x[3], y[3];
    fori(i,0,3) x[i] = y[i] = 0;
    fori(i,0,3) {
        while(a % d[i] == 0) a /= d[i], x[i]++;
    }
    fori(i,0,3) {
        while(b % d[i] == 0) b /= d[i], y[i]++;
    }
    int s = 0;
    fori(i,0,3) s += abs(x[i] - y[i]);
    cout << (a == b ? s : -1) << endl;
    return 0; 
}