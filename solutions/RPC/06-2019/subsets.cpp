#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int const nmax = 1e6 + 5;
int a[nmax];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    while(q--){
        int s;
        cin >> s;
        long long ans = 0;
        long long l = 0, r = n-1;
        while(l < r){
            while(r > l && a[l] + a[r] > s)r--;
            if(a[l] + a[r] <= s)
                ans += (r - l);
            l++;
        }
        cout << ans << endl;
    }
    return 0;
}