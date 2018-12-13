#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    long long total = 0;
    map<int,vector<int>> s;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        total += v[i];
        s[v[i]].push_back(i);
    }
    set<int> ans;
    for(int i = 0; i < n; i++){
        long long a = total - (2*v[i]);
        if(a <= 1e6 && s.count(a))
            for(int j: s[a])
                if(j != i)ans.insert(j);   
    }
    if(ans.size()){
        cout << ans.size() << endl;
        bool flag = true;
        for(auto i : ans){
            if(flag)flag=false;
            else cout << " ";
            cout << i + 1;
        }
        cout << endl;
    }else cout << 0 << endl;
    return 0;   
}