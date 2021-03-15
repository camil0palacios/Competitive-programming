#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
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

const int Mxn = 9;
string a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fori(i,0,8) {
        cin >> a[i];
    }
    bool ok = 1;
    fori(i,0,8) {
        bool c1 = 0, c2 = 1, can1 = 1, can2 = 1;
        fori(j,0,8) {
            bool c = a[i][j] == 'W' ? 1 : 0;
            if(c != c1) can1 = 0;
            if(c != c2) can2 = 0;
            c1 ^= 1;
            c2 ^= 1;
        }
        ok &= (can1 | can2);
    }
    cout << (ok ? "YES" : "NO") << endl;
    return 0; 
}