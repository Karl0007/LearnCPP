#include<iostream>

namespace My{

	class MyString{
	public:
		enum class input_mode {LINE , WORD};
	
	private:
		char * m_str;
		int m_len;
		static int m_cnt_num;
		static int m_max_input_num;
		static input_mode m_input_mode;


	public:
		explicit MyString();
		MyString(const char * _s); //new

		MyString(const MyString &); //copy
		MyString(MyString &&);	//move

		~MyString(); //delete

		MyString & operator= (const MyString &); //copy
		MyString & operator= (MyString &&); // move

		int size() const;

		static void set_max_input(int);
		static void set_input_mode(input_mode);

		char & operator[](int); 
		const char & operator[](int) const; 

		MyString & operator+= (const MyString &);
		friend MyString operator+ (const MyString &,const MyString &);

		friend bool operator< (const MyString &,const MyString &);
		friend bool operator> (const MyString &,const MyString &);
		friend bool operator== (const MyString &,const MyString &);

		friend std::ostream & operator << (std::ostream &,const MyString &);
		friend std::istream & operator >> (std::istream &,MyString &);
	};

}