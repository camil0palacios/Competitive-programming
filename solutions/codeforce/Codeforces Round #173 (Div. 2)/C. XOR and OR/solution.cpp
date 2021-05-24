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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    if(sz(a) != sz(b)) {
        cout << "NO" << endl;
        return 0;
    }
    if(a == b) {
        cout << "YES" << endl;
        return 0;
    }
    int x = 0, y = 0;
    fori(i,0,sz(a)) x |= a[i] == '1', y |= b[i] == '1';
    if(x && y) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0; 
}