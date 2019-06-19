#include <bits/stdc++.h>
using namespace std;

bool done[(1 << 18) + 5];

int main(){
    int n, x;
    cin >> n >> x;
    done[x] = 1;
    vector<int> ans({0});
    for(int i = 1; i < (1 << n); i++){
        if(done[i])continue;
        ans.push_back(i);
        done[i^x] = 1;
    }
    cout << ans.size()-1 << endl;
    for(int i = 1; i < ans.size(); i++){
        cout << (ans[i]^ans[i-1]) << " ";
    }
    return 0;
}