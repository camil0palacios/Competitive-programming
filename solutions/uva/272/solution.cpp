#include <bits/stdc++.h>
using namespace std;

int main(){

  string s;
  bool flag = false;
  while(getline(cin,s)){
    for(char to: s){
      if(to == '\"'){
        if(!flag){
          cout << "``";
        }
        else{
          cout << "\'\'";
        }
        flag = !flag;
      }
      else cout <<  to;
    }
    cout << endl;
  }
  return 0;
}
