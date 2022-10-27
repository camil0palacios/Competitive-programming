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

const int Mxn = 2e5 + 5;
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> a[i];
        a[n] = 0;
        int x = 0, y = -1;
        int lst = 0, mx2 = 0;
        fore(i,0,n) {
            if(a[i] == 0) {
                int cnt = 0, pr = 0;
                fori(j,lst,i) {
                    cnt += abs(a[j]) == 2;
                    pr ^= a[j] < 1;
                    if(mx2 < cnt && !pr) {
                        mx2 = cnt;
                        x = lst, y = j;
                    }
                }
                cnt = 0, pr = 0;
                forr(j,i-1,lst) {
                    cnt += abs(a[j]) == 2;
                    pr ^= a[j] < 1;
                    if(mx2 < cnt && !pr) {
                        mx2 = cnt;
                        x = j, y = i-1;
                    }
                }
                lst = i+1;
            }
        }
        cout << x << ' ' << (n-y-1) << endl;
    }
    return 0; 
}