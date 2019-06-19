#include <bits/stdc++.h>
using namespace std;

long long a[100005];
bool x[2];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(x[a[i]%2])continue;
        x[a[i]%2] = 1;
    }
    if(x[0] && x[1]){
        sort(a, a+n);
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}