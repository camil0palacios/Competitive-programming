#include <bits/stdc++.h>
using namespace std;

int to_int(string &s){
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z')sum += s[i] - 'a' + 1;
        if(s[i] >= 'A' && s[i] <= 'Z')sum += s[i] - 'A' + 1;
    }
    while(sum > 9){
        int aux = 0;
        while(sum > 0){
            aux += sum%10;
            sum /= 10;
        }
        sum = aux;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string x, y;
    while(getline(cin,x)){
        getline(cin,y);
        int a = to_int(x), b = to_int(y);
        if(a > b)swap(a, b);
        cout << setprecision(2) << fixed << a*100.0/b << " %" << endl;    
    }
    return 0;
}