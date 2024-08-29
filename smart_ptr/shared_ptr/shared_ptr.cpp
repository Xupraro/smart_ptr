#include<iostream>
#include<string>
using namespace std;

int class_count;

class Boy;
class Girl;

class Boy
{
public:
	Boy() { cout << "Boy Create!" << endl; }
	~Boy() { cout << "Boy Delete!" << endl; }
	void setGirlFriend(shared_ptr<Girl> _girlFriend) {
		this->girl = _girlFriend;
	}

private:
	shared_ptr<Girl> girl;
};

class Girl
{
public:
	Girl() { cout << "Girl Create!" << endl; }
	~Girl() { cout << "Girl Delete!" << endl; }
	void setBoyFriend(shared_ptr<Boy> _boyFriend) {
		this->boy = _boyFriend;
	}

private:
	shared_ptr<Boy> boy;
};

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
	shared_ptr<Test> tt1;
	shared_ptr<Test> tt2(new Test());
	cout << "tt1:" << tt1.use_count() << endl;
	cout << "tt2:" << tt2.use_count() << endl;
	cout << "--------------------" << endl;
	tt1 = tt2;
	cout << "tt1:" << tt1.use_count() << endl;
	cout << "tt2:" << tt2.use_count() << endl;
	cout << "--------------------" << endl;
	shared_ptr<Test> tt3(tt1);
	cout << "tt1:" << tt1.use_count() << endl;
	cout << "tt2:" << tt2.use_count() << endl;
	cout << "tt3:" << tt3.use_count() << endl;
	cout << "--------------------" << endl;
	tt1 = nullptr;
	Test* t = tt2.get();
	cout << t << endl;
	cout << tt2.get() << endl;
	tt1 = make_shared<Test>();
	cout << "tt1:" << tt1.use_count() << endl;
	cout << "tt2:" << tt2.use_count() << endl;
	cout << "tt3:" << tt3.use_count() << endl;
	cout << "--------------------" << endl;
	swap(tt1, tt2);
	cout << "tt1:" << tt1.use_count() << endl;
	cout << "tt2:" << tt2.use_count() << endl;
	cout << "tt3:" << tt3.use_count() << endl;
	cout << "--------------------" << endl;
	tt1.reset();
	cout << "tt1:" << tt1.use_count() << endl;
	cout << "tt2:" << tt2.use_count() << endl;
	cout << "tt3:" << tt3.use_count() << endl;
	cout << "--------------------" << endl;
	shared_ptr<Boy> spBoy = make_shared<Boy>();
	shared_ptr<Girl> spGirl = make_shared<Girl>();
	cout << "Boy:" << spBoy.use_count() << endl;
	cout << "Girl:" << spGirl.use_count() << endl;
	spBoy->setGirlFriend(spGirl);
	spGirl->setBoyFriend(spBoy);
	cout << "Boy:" << spBoy.use_count() << endl;
	cout << "Girl:" << spGirl.use_count() << endl;
	cout << "--------------------" << endl;
	return 0;
}