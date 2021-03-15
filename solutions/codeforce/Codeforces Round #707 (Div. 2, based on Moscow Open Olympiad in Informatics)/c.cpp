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

const int Mxn = 2e5 + 5;
ii a[Mxn];
int x[5000005], y[5000005];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fore(i,1,n) {
        cin >> a[i].ft;
        a[i].sd = i; 
    }
    sort(a+1, a+n+1);
    fore(i,1,n) {
        fore(j,i+1,n) {
            int s = a[i].ft + a[j].ft;
            if(x[s] && y[s] && x[s] != a[i].sd && y[s] != a[j].sd) {
                cout << "YES" << endl;
                cout << x[s] << ' ' << y[s] << ' ' << a[i].sd << ' ' << a[j].sd << endl; 
                return 0;
            }
            x[s] = a[i].sd, y[s] = a[j].sd;
        }
    }
    cout << "NO" << endl;
    return 0; 
}