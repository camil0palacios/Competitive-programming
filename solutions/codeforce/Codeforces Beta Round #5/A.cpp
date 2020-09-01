#include <bits/stdc++.h>
using namespace std;

int main(){

  set<string> chat;
  string s;
  int ans = 0;
  while(getline(cin,s)){
    if(s[0] == '+')chat.insert(s.substr(1,s.size()-1));
    else if(s[0] == '-')chat.erase(s.substr(1,s.size()-1));
    else{
      int i;
      for(i = 0; s[i] != ':' ; i++){}
      string s1 = s.substr(i+1,s.size()-1);
      ans += (s1.size()*chat.size());
    }
  }
  cout << ans << endl;
  return 0;
}
