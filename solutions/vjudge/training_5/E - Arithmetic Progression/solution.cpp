#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int mmin = 1e9;
    for(int i = 1; i < n; i++){
        mmin = min(mmin, a[i] - a[i-1]);
    }
    vector<int> ans;
    if(a[0] == a[n-1] && n >= 2){
        ans.emplace_back(a[0]);
    }
    else if(n == 1){
        cout << -1 << endl;
        return 0;
    }
    else if(n == 2){
        if((a[0] + a[1]) % 2 == 0){
            ans.emplace_back((a[0] + a[1])/2);
        }
        ans.emplace_back(a[0] - mmin);
        ans.emplace_back(a[1] + mmin);
    }
    else{
        bool y = 1;
        int cnt = 0;
        for(int i = 1; i < n; i++){
            if((a[i] - a[i-1]) != mmin){
                cnt++;
            }
        }
        if(a[1] != a[n-1] && a[0] != a[n-2] && cnt <= 1){
            for(int i = 1; i < n; i++){
                if((a[i] - a[i-1] != mmin) && (a[i] - mmin) == (a[i-1] + mmin)){
                    y = 0;
                    ans.emplace_back(a[i-1] + mmin);
                    break;
                }
            }
            if(y && !cnt){
                ans.emplace_back(a[n-1] + mmin);
                ans.emplace_back(a[0] - mmin);
            }
        }else{
            cout << 0 << endl;
            return 0;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto & i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}