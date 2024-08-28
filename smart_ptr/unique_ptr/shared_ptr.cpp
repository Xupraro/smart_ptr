#include<iostream>
#include<string>
using namespace std;

int class_count;

class Test
{
public:
	Test() { cout << "Test Create!" << this->count << endl; }
	~Test() { cout << "Test Delete!" << this->count << endl; }
	string getNum() const { return "Test" + to_string(this->count); }

private:
	int count = class_count++;
};

int main()
{

	return 0;
}