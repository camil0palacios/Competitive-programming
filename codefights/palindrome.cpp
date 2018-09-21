#include<iostream>
#include<string>

bool checkPalindrome(std::string inputString) {
    int begin=0, end=inputString.length()-1;
    while(begin <= end ){
        if(inputString[begin] != inputString[end])
            return false;
        begin++;
        end--;
    }
    return true;
}

int main(){
    std:: string str;
    std::cin>>str;
    std::cout<<checkPalindrome(str);
}

