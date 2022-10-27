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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = (1 << 17) + 5;
int a[Mxn];
int ord[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n >> n; n++;
        fori(i,0,n) cin >> a[i], ord[i] = i;
        int x = 0;
        fori(b,0,17) {
            int cnt1 = 0, cnt2 = 0;
            fori(i,0,n) {
                cnt1 += (a[i] >> b) & 1;
                cnt2 += (ord[i] >> b) & 1;
            }
            if(cnt1 > cnt2) x |= (1 << b);
        }
        cout << x << endl;
    } 
    return 0; 
}