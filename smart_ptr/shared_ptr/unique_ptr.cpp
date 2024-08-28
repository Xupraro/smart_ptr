#include<iostream>
#include<string>
using namespace std;

int class_count;

class Test
{
public:
	Test() { cout << "Test Create!" << this->count << endl; }
	~Test() { cout << "Test Delete!" << this->count << endl; }
	Test(int i) :num(i) {};
	void showNum() const { cout << num << endl; }
	string getNum() const { return "Test" + to_string(this->count); }

private:
	int count = class_count++;
	int num;
};

int main()
{
	unique_ptr<Test[]> test(new Test[5]{ Test(1),Test(11) ,Test(111) ,Test(1111) ,Test(11111) });
	for (int i = 0; i < 5; ++i)
	{
		(test.get() + i)->showNum();
	}
	return 0;
}