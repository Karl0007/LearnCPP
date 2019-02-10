#include"MyString.h"
#include<cstring>

namespace My{
	using namespace std;
	int MyString::m_cnt_num = 0;
	int MyString::m_max_input_num = 100;
	MyString::input_mode MyString::m_input_mode = MyString::input_mode::LINE;
	MyString::MyString(const char * _s){
		m_len = strlen(_s);
		m_str = new char [m_len + 1];
		strcpy(m_str,_s);
		m_cnt_num++;
		// cout << "new string " << _s << endl;
	}

	MyString::MyString() : MyString("") {}

	MyString::~MyString(){
		// cout << "delete " << (m_str == nullptr ? "" : m_str )<< " ";
		delete[] m_str;
		m_cnt_num--;
		// cout << m_cnt_num << endl;
	}

	MyString::MyString(const MyString & _s){
		// cout << "copy " << _s << endl;
		m_cnt_num++;
		m_len = _s.m_len;
		m_str = new char [m_len+1];
		strcpy(m_str,_s.m_str);
	}

	MyString::MyString(MyString && _s){
		// cout << "move " << _s << endl;
		m_cnt_num++;
		m_len = _s.m_len;
		m_str = _s.m_str;
		_s.m_len=0;
		_s.m_str=nullptr;
	}

	MyString & MyString::operator= (const MyString & _s){
		// cout << "copy equal " << _s<<endl;
		if (this == &_s) 
			return *this;
		delete [] m_str;
		m_str = new char [_s.m_len + 1];
		m_len = _s.m_len;
		strcpy(m_str,_s.m_str);
		return *this;
	}

	MyString & MyString::operator= (MyString && _s){
		// cout << "move equal " << _s << endl;
		if (this == &_s) 
			return *this;
		delete [] m_str;
		m_str = _s.m_str;
		m_len = _s.m_len;
		_s.m_str=nullptr;
		_s.m_len=0;
		return *this;
	}

	int MyString::size() const{
		return m_len;
	}

	void MyString::set_max_input(int _x){
		m_max_input_num = _x;
	}

	void MyString::set_input_mode(MyString::input_mode _mode){
		m_input_mode = _mode;
		cout << int (_mode) << endl;
	}

	char & MyString::operator[] (int _pos){
		if (_pos >= m_len) _pos = m_len -1;
		if (_pos < 0) _pos = 0;
		return m_str[_pos];
	}

	const char & MyString::operator[] (int _pos) const{
		if (_pos >= m_len) _pos = m_len -1;
		if (_pos < 0) _pos = 0;
		return m_str[_pos];
	}

	MyString & MyString::operator+=(const MyString & _s){
		return *this = *this + _s;
	}

	bool operator < (const MyString & _left , const MyString & _right){
		return strcmp(_left.m_str,_right.m_str) < 0;
	}

	bool operator > (const MyString & _left , const MyString & _right){
		return strcmp(_left.m_str,_right.m_str) > 0;
	}

	bool operator == (const MyString & _left , const MyString & _right){
		return strcmp(_left.m_str,_right.m_str) == 0;
	}
	
	MyString operator+ (const MyString & _left, const MyString & _right){
		int _len = _left.size() + _right.size();
		char * _tmp = new char[_len + 1];
		strcpy(_tmp,_left.m_str);
		strcpy(_tmp + _left.size(),_right.m_str);
		MyString _ans = MyString(_tmp);
		delete[] _tmp;
		return _ans;
	}

	std::ostream & operator<< (std::ostream & _os ,const MyString & _s){
		if (_s.m_str != nullptr)
			_os << _s.m_str;
		return _os;
	}

	std::istream & operator>>(std::istream & _is,MyString & _s){
		char * _tmp = new char [MyString::m_max_input_num];
		if (MyString::m_input_mode == MyString::input_mode::LINE)
			_is.getline(_tmp,MyString::m_max_input_num);
		else
			_is.getline(_tmp,MyString::m_max_input_num,' ');
		_s = _tmp;
		return _is;
	}
}