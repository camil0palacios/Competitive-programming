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
typedef pair<ll,int> lli;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<lli> vlli;

const int Mxn = 2e5 + 5;
ll a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    ll s = 0, j = 0;
    fore(i,1,n) {
        cin >> a[i];
        // cout << s - j*(n-i)*a[i] << endl;
        if(s - j*(n-i)*a[i] < k) {
            cout << i << endl;
        } else { 
            s += a[i]*j;
            j++;
        }   
    }
    return 0; 
}