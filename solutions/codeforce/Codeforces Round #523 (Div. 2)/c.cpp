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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int mod = 1e9 + 7;
const int Mxn = 1e5 + 5;
const int Mxa = 1e6 + 5;
int a[Mxn], cnt[Mxa], tmp[Mxa];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    cnt[0] = 1;
    fori(i,0,n) {
        for(int j = 1; j*j <= a[i]; j++) {
            if(a[i] % j == 0) {
                tmp[j] = cnt[j-1];
                int x = a[i]/j;
                if(x != j) tmp[x] = cnt[x-1];
            }
        }
        for(int j = 1; j*j <= a[i]; j++) {
            if(a[i] % j == 0) {
                cnt[j] = (cnt[j] + tmp[j]) % mod;
                int x = a[i]/j;
                if(x != j) cnt[x] = (cnt[x] + tmp[x]) % mod;
            }
        }
    }
    ll ans = 0;
    fori(i,1,Mxa) ans = (ans + cnt[i]) % mod;
    cout << ans << endl;
    return 0; 
}