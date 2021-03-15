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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n+1), b(n+1);
    fore(i,1,n) cin >> a[i] >> b[i];
    vb open(n+1);
    fore(i,1,n) {
        fore(j,1,n) {
            if(i != j && a[j] == b[i]) {
                open[j] = 1;
            }
        }
    }
    int ans = accumulate(all(open), 0);
    cout << n - ans << endl;
    return 0; 
}