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
    int n, k;
    cin >> n >> k;
    if(n == 1) {
        if(!k) cout << 1 << endl;
        else cout << -1 << endl;
        return 0;
    }
    if(k < n / 2) {
        cout << -1 << endl;
        return 0;
    }
    int x = k - (n - 2) / 2;
    cout << x << ' ' << x*2 << ' '; 
    n -= 2, x *= 2;
    while(n--) cout << ++x << ' ';
    cout << endl;
    return 0; 
}