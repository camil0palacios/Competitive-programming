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

double dif;
ll x, y, n;
ll a = 1, b = 1;

void check(ll a0, ll b0) {
    if(fabs((double)x/y - (double)a0/b0) < dif) {
        dif = fabs((double)x/y - (double)a0/b0);
        a = a0, b = b0;
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> x >> y >> n;
    dif = 1e18;
    fori(i,1,n+1) {
        check(x*i/y, i);
        check(x*i/y+1, i);
    }
    cout << a << "/" << b << endl;
    return 0; 
}