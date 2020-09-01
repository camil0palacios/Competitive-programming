#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(cin >> n){
        vector<long long> v(n); 
        long long even = 0, odd = 0;
        for(int i = 1; i <= n; i++){
            cin >> v[i-1];
            even += (i%2 == 0 ? v[i-1]: 0);
            odd += (i%2 != 0 ? v[i-1]: 0);
        }
        int cnt = 0;
        long long e = 0, o = 0;
        for(int i = 1; i <= n; i++){
            if(i%2 == 0 && o + even - v[i-1] == e + odd)cnt++;
            else if(i%2 != 0 && e + odd - v[i-1] == o + even)cnt++;
            if(i%2 == 0){
                even -= v[i-1];
                e += v[i-1];
            }else{
                odd -= v[i-1];
                o += v[i-1]; 
            }
        }
        cout << cnt << endl;
    }
    return 0;
}