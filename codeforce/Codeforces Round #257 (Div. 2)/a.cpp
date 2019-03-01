#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m){
        deque<pair<int,int>> d(n);
        for(int i = 0; i < n; i++){
            int tmp; cin >> tmp;
            d[i] = {tmp,i};
        }
        while(d.size() > 1){
            if(d[0].first - m > 0){
                d[0].first -= m;
                d.emplace_back(d[0]);
            }
            d.pop_front();
        }
        cout << d[0].second + 1 << endl;
    }
    return 0;
}