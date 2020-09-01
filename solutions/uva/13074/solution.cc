#include <bits/stdc++.h>
using namespace std;

//O(n!)
long long solution(const vector<int> &shuff,const vector<int> &v){
    vector<vector<int>> sol(2, vector<int> (v.size(), 0));
    sol[0] = v;
    long long ans = 0;
    bool alt = 0;
    do{
        bool tmp = alt^1;
        for(int i = 0; i < v.size(); i++){
            sol[tmp][shuff[i]] = sol[alt][i];
            sol[alt][i] = 0;
        }
        alt = tmp;
        ans++;
    } while(sol[0] != v && sol[1] != v);
    
    return ans;
}

int main(){
    int n;
    while(cin >> n && n){
        vector<int> shuff(n), v(n);
        for(auto &i : shuff)cin >> i, i--;
        for(int i = 0; i < n; i++)v[i] = i;
        cout << solution(shuff,v) << endl;
    }
    return 0;
}