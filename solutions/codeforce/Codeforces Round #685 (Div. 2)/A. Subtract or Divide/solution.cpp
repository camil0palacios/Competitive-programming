#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 0;
        if(n == 1) ans = 0;
        else if(n == 2) ans = 1;
        else {
            if(n & 1) n--, ans++;
            if(n > 2) ans += 2;
            else ans++;
        }
        cout << ans << endl;
    }
    return 0; 
}