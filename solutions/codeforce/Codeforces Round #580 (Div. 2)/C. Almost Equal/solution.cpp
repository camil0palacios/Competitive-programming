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
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int x = 1, j = 0;
    if(n & 1) {
        a[0] = 1;
        fori(i,0,n) {
            if(x == 2*n) break;
            j = (j + n) % (2*n);
            a[j] = ++x;
            if(x == 2*n) break;
            j = (j + 1) % (2*n);
            a[j] = ++x;
        }
        cout << "YES" << endl;
        fori(i,0,2*n) {
            cout << a[i] << ' ';
        }
        cout << endl;
    } else cout << "NO" << endl;
    return 0; 
}