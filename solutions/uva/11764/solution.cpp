#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int len, cur, high = 0, low = 0;
        cin >> len >> cur;
        for(int j = 0; j < len - 1; j++){
            int tmp; cin >> tmp;
            if(cur < tmp)high++;
            else if(cur > tmp)low++;
            cur = tmp;
        }
        cout << "Case " << i + 1 << ": " << high << " " << low << endl;
    }
    return 0;
}