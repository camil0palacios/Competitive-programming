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

const int Mxa = 3e6 + 5;
const int Mxn = 2e5 + 5;
int x[Mxa], a[Mxa];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) {
        cin >> x[i];
        a[x[i]] = 1;
    }
    sort(x, x+n);
    n = distance(x, unique(x, x + n));
    int lst = 0;
    fori(i,1,Mxa) {
        int tmp = a[i];
        a[i] = lst; 
        if(tmp) lst = i;
    }
    int ans = 0;
    fori(i,0,n) {
        for(int j = 2; j*x[i] < Mxa; j++) {
            ans = max(ans, a[j*x[i]] % x[i]);
        }
    }
    cout << ans << endl;
    return 0;
}