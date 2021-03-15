#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

const int MXN = 2020;
int a[MXN];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int one = 0;
    fori(i, 0, n) {
        cin >> a[i];
        one += a[i] == 1;
    }
    if(one) { 
        cout << n - one << endl;
        return 0;
    }
    int x = a[0];
    fori(i, 1, n) x = __gcd(x, a[i]);
    if(x != 1) {
        cout << -1 << endl;
        return 0;
    }  
    int ans = 1e9;
    for(int i = 0; i < n; i++) {
        int p = a[i];
        for(int j = i+1; j < n; j++) {
            p = __gcd(p, a[j]);
            if(p == 1) {
                ans = min(ans, j - i);
            }
        }
    }
    cout << n - 1 + ans << endl;
    return 0; 
}