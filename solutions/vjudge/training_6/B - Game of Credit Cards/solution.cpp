#include <bits/stdc++.h>
using namespace std;

int x[1001], n;
map<int,int> m;

int solve2(){
    int ans = 0;
    map<int,int> frq = m;
    map<int,int>::iterator it = frq.begin();
    for(int i = 0; i < n; i++){
        it = frq.upper_bound(x[i]);
        if(it != frq.end()){
            it -> second--;
            if(it -> first > x[i])ans++;
            if(it -> second == 0){
                frq.erase(it);
            }
        }
    }
    return ans;
}

int solve1(){
    int ans = 0;
    map<int,int> frq = m;
    map<int,int>::iterator it = frq.begin();
    for(int i = 0; i < n; i++){
        it = frq.lower_bound(x[i]);
        if(it != frq.end()){
            it -> second--;
            if(it -> second == 0){
                frq.erase(it);
            }
        }else{
            ans++;
        }
    }
    return ans;
}

int main(){
    string a, b;
    cin >> n;
    cin >> a >> b;
    for(int i = 0; i < n; i++){
        x[i] = a[i] - '0';
    }
    for(int i = 0; i < n; i++){
        m[b[i]-'0']++;
    }
    int res_1 = solve1(), res_2 = solve2();
    cout << res_1 << endl << res_2 << endl;
    return 0;
}