#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	string name;
	string id; // 주민 번호 :
	// 123456 1234567
	unsigned char age; // 나이
	unsigned char gender; // 성별
	unsigned char height; // 키
public:
	Person();
	Person(const string& name, const string& id, unsigned char age, unsigned char gender, unsigned char height);
	Person& operator= (const Person& p);
	~Person();
	void ShowInfo();
	static int person_count;
	
	int money;
	static int sharedMoney;
	void addMoney(int n) {
		money += n;
	}
	void addShared(int n) {
		sharedMoney += n;
	}
};

int Person::person_count = 0;
int Person::sharedMoney = 0;

Person::Person()
{
	name = "", id = "";
	age = 0; gender = 0; height = 0;
	person_count++;
	cout << "current person count : " << person_count << endl;
}

Person::Person(const string& name, const string& id, unsigned char age, unsigned char gender, unsigned char height)
{
	this->name = name; this->id = id;
	this->age = age; this->gender = gender;
	this->height = height;
	person_count++;
	cout << "current person count : " << person_count << endl;
}
Person& Person::operator=(const Person& p)
{
	name = p.name; id = p.id;
	age = p.age; gender = p.gender;
	height = p.height;
	return *this;
}
Person::~Person()
{
	person_count--;
	cout << "current person count : " << person_count << endl;

}

void Person::ShowInfo()
{
	cout << "이름 : " << name << ", 주민번호 : " <<
		id << endl;
}

int main() {
	Person han;
	han.money = 100;
	han.sharedMoney = 200;
	Person lee;
	lee.money = 150;
	lee.addMoney(200);
	lee.addShared(200);
	cout << han.money << ' ' << lee.money << endl;
	cout << han.sharedMoney << ' ' << lee.sharedMoney << endl;
}