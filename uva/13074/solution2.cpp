#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int gcd(int a, int b){ // O(logn)
    if(b > a)swap(a,b);
    int tmp;
    while(a%b){
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}

int mcm(int x, int y){
    return (x*y)/gcd(x,y);
}

int dfs(int n, const vector<int>& v, vector<bool>& used){ //o(n + m)
    int comp = 0;
    while(!used[n]){
        used[n] = true;
        n = v[n];
        comp++;
    }
    return comp;
}

int solution(const vector<int>& v){
    vector<int> mini;
    vector<bool> used(v.size(),0);
    for(int i = 0; i < v.size(); i++){
        if(!used[i]){
            mini.emplace_back(dfs(i, v, used));
        }
    }
    int ans = 0;
    if(mini.size() > 1){
        for(int i = 0; i < mini.size() - 1; i++){ //O(n*log(n))
            ans = mcm(mini[i], mini[i+1]);
            mini[i+1] = ans;
        }
        ans = mini[mini.size()-1];
    }else{
        ans = mini[0];
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n && n){
        vector<int> v(n);
        for(auto &i : v)cin >> i, i--;
        cout << solution(v) << endl;
    }
    return 0;
}