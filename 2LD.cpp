//Andrejs Petersons
#include <iostream>
#include <string>
#include <typeinfo>
#define SIZE 3
using namespace std;


class Settlement {
protected:
	string name;
	long population;
	short t_code;
public:
	virtual void Print()const;
	//Setter
	void SetName(string);
	void SetCount(long);
	void SetCode(short);
	//Getter
	string GetName()const;
	long GetCount()const;
	short GetCode()const;
	Settlement(string, long, short);
	Settlement();
	virtual ~Settlement() {
		cout << "Objekts " << typeid(Settlement).name() << " iznicinats"<<endl;
	}
};

Settlement::Settlement() :name("Default"), population(0), t_code(0) {
	cout << "Objekts " << name << " successfully created" << endl;
}

Settlement::Settlement(string n, long pop, short c) {
	name = n;
	population = pop;
	t_code = c;
	cout << "Objekts " << name << " successfully created"<<endl;
}

inline string Settlement::GetName()const {
	return name;
}

inline long Settlement::GetCount()const {
	return population;
}

inline short Settlement::GetCode()const {
	return t_code;
}

inline void Settlement::SetName(string n) {
	name = n;
}

inline void Settlement::SetCount(long pop) {
	population = pop; //cilveku skaits
}

inline void Settlement::SetCode(short c) {
	t_code=c;
}

inline void Settlement::Print()const {
	cout << "Name:"<<name <<endl<<"Population:"<<population << endl<< "Territorijas kods:"<<t_code << endl;
}

class City:public Settlement{
protected:
	short district_count;//rajonu daudzums
public:
	City();
	City(string,long,short,short);
	short GetDCount()const;
	void  SetDCount(short);
	virtual ~City() {
		cout << "Objekts " << typeid(City).name() << " destroyed successfully" << endl;
	}
	virtual void Print()const;
};

City::City() :Settlement(), district_count(0) {
	
}

inline short City::GetDCount()const {
	return district_count;
}

inline void City::SetDCount(short d_count) {
	this->district_count = d_count;
}

City::City(string n,long pop,short c,short d_count) : Settlement(n, pop, c) {
	district_count = d_count;

}

inline void City::Print()const {
	Settlement::Print();
	cout << "District count:" << district_count << endl;
}

int main() {

	Settlement* Array[SIZE]{
		new City(),
		new Settlement("Ventspils",100000,99),
		new City("Riga",666666,99,5)
	};

	((City*)Array[0])->SetDCount(45);
	((City*)Array[0])->SetName("Ogre");
	((City*)Array[0])->SetCount(20000);

	cout << endl;

	for (int i = 0; i < SIZE; i++) {
		cout << (i+1) << ".";
		Array[i]->Print();
		cout << endl;
	}
	

	for (int i = 0; i < SIZE; i++) {
		delete Array[i];
	}
	
	
}

