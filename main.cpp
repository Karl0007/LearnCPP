#include "MyString.h"
using My::MyString;

void fun(MyString ss){
    std::cout <<"fun" << ss;
}

 MyString Max(const MyString & _s1, const MyString & _s2){
    if (_s1.size() > _s2.size())
        return _s1;
    else
        return _s2;
}

int main(){
    MyString s1 = "abcd";//MyString("abcabc");
    MyString s2 = "123";
    MyString mx;
    //MyString s3 = "23333";
    // MyString s4 = (s1 + s2);
    // MyString s3;
    // s3=s4+s4;
    // s3+=s4;
    // s3=s1;
    // fun(s3);
    // std::cout << (s1 < s2) << (s3 == s1);
    //std::cin >> s2[3];
    //std::cout << s2 << s1 << s3;
    //std::cout << std::endl << s2+s3+s1;
    MyString::set_input_mode(MyString::input_mode::WORD);
    MyString::set_max_input(40);
    std::cin >> s1 >> s2;
    mx = Max(s1,s2);
    mx += "233";
    std::cout << mx << (s1+s2).size() << " " << sizeof (std::string) << std::endl;
    std::cout << mx*2ll <<std::endl;
    return 0;    
}