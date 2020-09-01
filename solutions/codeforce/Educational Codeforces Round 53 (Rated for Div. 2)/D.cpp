#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long t;
    cin >> n >> t;
    list<long long> v;
    long long sum = 0;
    for(long long i = 0; i < n; i++){
        long long tmp;cin >> tmp;
        if(sum + tmp > t)continue;
        sum += tmp;
        v.push_back(tmp);
    }
    long long ans = 0;
    while(t && !v.empty()){
        long long ntam = t / sum;
        t = t % sum;
        ans += ntam * v.size();
        sum = 0;
        for(auto it = v.begin(); it != v.end();){
            if(sum + *it > t)it = v.erase(it);
            else{
                sum += *it;
                ++it;
            }
        }
    }
    cout << ans << endl;
    return 0;
}