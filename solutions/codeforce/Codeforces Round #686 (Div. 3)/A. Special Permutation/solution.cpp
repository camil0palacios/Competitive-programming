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
        vector<int> ans(n + 1);
        for(int i = 1; i <= n; i++) {
            ans[i] = n - i + 1;
        } 
        if(n & 1) swap(ans[n/2], ans[n/2 + 1]);
        for(int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        } cout << endl; 
    }
    return 0; 
}