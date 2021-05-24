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

string a, b;
int n;
int tot, pos, t;

void rec(int i, int x) {
    if(i == sz(a)) {
        if(x == t) pos++;
        tot++;
        return;
    }
    if(b[i] != '?') rec(i+1, x + (b[i] == '+' ? 1 : -1));
    else {
        rec(i+1, x+1);
        rec(i+1, x-1);
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    cin >> a >> b;
    n = sz(a);
    fori(i,0,n) t += a[i] == '+' ? 1 : -1;
    rec(0, 0);
    cout << 1.0*pos/tot << endl;
    return 0; 
}