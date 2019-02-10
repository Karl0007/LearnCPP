#include "MyString.h"
using My::MyString;

void fun(MyString ss){
    std::cout <<"fun" << ss;
}

int main(){
    MyString s1 = "abc";//MyString("abcabc");
    MyString s2 = "123";
    //MyString s3 = "23333";
    MyString s4 = (s1 + s2);
    MyString s3;
    s3=s4+s4;
    s3+=s4;
    s3=s1;
    fun(s3);
    std::cout << (s1 < s2) << (s3 == s1);
    //std::cin >> s2[3];
    //std::cout << s2 << s1 << s3;
    //std::cout << std::endl << s2+s3+s1;
    MyString::set_input_mode(MyString::input_mode::WORD);
    MyString::set_max_input(4);
    std::cin >> s1;
    std::cout << s1+" "+s1;
    return 0;    
}