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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    int f[105];
    while(cin >> n) {
        memset(f, 0, sizeof f);
        fori(i,0,n) {
            int l, r;
            cin >> l >> r;
            fore(j,l,r) {
                f[j]++;
            }
        }
        int num; 
        cin >> num;
        int idx = 0;
        fore(i,1,num-1) {
            idx += f[i];
        }
        cout << num << ' ';
        if(!f[num]) cout << "not found"; 
        else cout << "found from " << idx << " to " << idx + f[num] - 1;
        cout << endl;
    }
    return 0; 
}