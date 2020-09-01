#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'x'){
            int j = i;
            while(j < n && s[i] == s[j]) {
                j++;
            }
            if(j - i >= 2) ans += (j - i - 2);
            i = j - 1;
        }
    }
    cout << ans << endl;
    return 0;
}