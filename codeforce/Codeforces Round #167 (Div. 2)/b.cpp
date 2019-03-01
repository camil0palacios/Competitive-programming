#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        int ans = 0, sum = 0;
        for(int i = 0; i < n; i++){
            int tmp; cin >> tmp;
            sum += tmp;
        }
        for(int i = 0; i < 5; i++){
            if((sum + i + 1) % (n+1) != 1)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}