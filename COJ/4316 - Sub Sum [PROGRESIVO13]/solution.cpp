#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, s;
    while(cin >> n >> s){
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int i = 1, j = 1, sum = 0;
        while(j <= n){
            if(sum == s)break;
            if(sum < s){
                sum += a[j];
                j++;
            }else if(sum > s && i < j){
                sum -= a[i];
                i++;
            }
        }
        if(sum == s){
            cout << i << " " << j-1 << endl;
        }else{
            while(i <= j){
                sum -= a[i];
                if(sum == s)break;
            }
            if(s == sum)cout << i+1 << " " << j-1 << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}