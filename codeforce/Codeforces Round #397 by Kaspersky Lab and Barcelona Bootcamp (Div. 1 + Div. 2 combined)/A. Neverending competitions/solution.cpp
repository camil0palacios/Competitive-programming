#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string home, aux;
    cin >> n >> home;
    for(int i = 0; i < n; i++){
        cin >> aux;
    }
    if(n % 2 == 0){
        cout << "home" << endl;
    }else{
        cout << "contest" << endl;
    }
    return 0;
}