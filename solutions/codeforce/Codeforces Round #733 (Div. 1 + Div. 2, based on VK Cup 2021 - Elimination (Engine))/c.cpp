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
int a[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,1,n) cin >> a[i];
        fore(i,1,n) cin >> b[i];
        sort(a+1, a+n+1);
        sort(b+1, b+n+1);
        fore(i,1,n) a[i] += a[i-1], b[i] += b[i-1];
        int add = 0;
        fore(i,0,2*n) {
            int x = 100*i + a[n] - a[(n+i)/4];
            int y = b[n] - b[max(0, (n+i)/4 - i)];
            if(x < y) continue;
            add = i;
            break;
        }
        cout << add << endl;
    }
    return 0; 
}