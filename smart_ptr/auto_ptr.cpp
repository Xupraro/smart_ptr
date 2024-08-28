#include<iostream>
#include<string>
using namespace std;

int class_count;

class Test
{
public:
	Test() { cout << "Test Create!" << this->count << endl; }
	~Test() { cout << "Test Delete!" << this->count << endl; }
	string getNum() { return "Test" + to_string(this->count); }

private:
	int count = class_count++;
};

int main()
{
	auto_ptr<Test> test(new Test);
	cout << test.get()->getNum() << endl;   //get()
	cout << "--------------------" << endl;
	test.reset(test.release());             //release()
	cout << "--------------------" << endl;
	test.reset(new Test);                   //reset()
	cout << "--------------------" << endl;
	return 0;
}