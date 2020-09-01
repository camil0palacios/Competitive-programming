#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        map<int, vector<int>> v;
        for(int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            v[--tmp].emplace_back(i);
        }
        vector<pair<int,int>> ans;
        for(auto & i : v){
            bool f = 1;
            int px = 0;
            if(i.second.size() > 1){
                px = (i.second[1] - i.second[0]);
                for(int j = 1; j < i.second.size(); j++){
                    if(px != i.second[j] - i.second[j-1]){
                        f = 0;
                        break;
                    }
                }
            }
            if(f)ans.emplace_back(i.first + 1, px);      
        }
        cout << ans.size() << endl;
        for(auto & i : ans){
            cout << i.first << " " << i.second << endl;
        }
    }
    return 0;
}