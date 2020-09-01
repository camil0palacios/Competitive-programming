#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN];

void sol() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == k) {
            i++;
            while(i < n && a[i - 1] == a[i] + 1) {
                i++;
            }
            i--;
            ans += a[i] == 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol(); 
    }       
    return 0;
}