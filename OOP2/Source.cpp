#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>


using namespace std;

class Worker;

class Observer {
public:

	void getInfo(Worker& copy);

};

class Worker {
private:
	string m_name;
	string m_position;
	int m_age;
	int m_salary;
	friend void Observer::getInfo(Worker& copy);
public:
	Worker() {
		m_name = "null";
		m_position = "null";
		m_age = 0;
		m_salary = 0;
	}
	void setParams(string name, string position, int age, int salary) {
		this->m_name = name;
		this->m_position = position;
		this->m_age = age;
		this->m_salary = salary;
	}
	Worker(const Worker& copy) {
		this->m_name = copy.m_name;
		this->m_position = copy.m_position;
		this->m_age = copy.m_age;
		this->m_salary = copy.m_salary;
	}
	int getage() {
		return m_age;
	}
	void setage(int age) {
		this->m_age = age;
	}
	int getsalary() {
		return m_salary;
	}
	void setsalary(int salary) {
		this->m_salary = salary;
	}
	string getposition() {
		return m_position;
	}
	void setposition(string position) {
		this->m_position = position;
	}
	string getname() {
		return m_name;
	}
	void setname(string name) {
		this->m_name = name;
	}
	~Worker() {
		cout << "Destuct";
	}
};

int main() {

	int lenght;
	string name;
	string position;
	int age;
	int salary;
	string pos;
	cout << "How match person" << endl;
	cin >> lenght;
	cout << endl;
	Worker* arr = new Worker[lenght];
	int n, num, n_n;
	do {

		cout << "1)Fill in the array\n2)Edit\n3)Complete tasks\n4)Viewing" << endl;
		cout << "Enter number of menu -> " << " ";
		cin >> num;
		system("cls");
		switch (num)
		{
		case(1):
			for (int i = 0; i < lenght; i++) {

				cout << "Enter first and last name -> " << " ";
				cin >> name;
				cout << "Enter position -> " << " ";
				cin >> position;
				cout << "Enter age of the position -> " << " ";
				cin >> age;
				cout << "Enter salary -> " << " ";
				cin >> salary;
				arr[i].setParams(name, position, age, salary);
				cout << endl;
			}
			break;
		case(2):
			cout << "Employee number -> " << endl;
			cin >> n;
			n--;
			cout << "What should I change?" << endl;
			cout << "1)First and last name\n2)Position\n3)Age of the position\n4)Salary" << endl;
			cin >> n_n;
			switch (n_n)
			{
			case(1):
				cout << "Enter first and last name -> " << " ";
				cin >> name;
				arr[n].setname(name);
				break;
			case(2):
				cout << "Enter position -> " << " ";
				cin >> position;
				arr[n].setposition(position);
				break;
			case(3):
				cout << "Enter age of the position -> " << " ";
				cin >> age;
				arr[n].setage(age);
				break;
			case(4):
				cout << "Enter salary -> " << " ";
				cin >> salary;
				arr[n].setsalary(salary);
				break;
			}
			break;
		case(3):
			cout << endl;
			cout << "Task A" << endl;
			int ag;
			cout << "Enter age of the position for sort -> " << " ";
			cin >> ag;

			for (int i = 0; i < lenght; i++) {
				if (arr[i].getage() > ag) {
					cout << arr[i].getname() << endl;
				}
			}

			// Задание Б
			cout << endl;
			cout << "Task B" << endl;
			int sal;
			cout << "Enter salary for sort -> " << " ";
			cin >> sal;

			for (int i = 0; i < lenght; i++) {
				if (arr[i].getsalary() > sal) {
					cout << arr[i].getname() << endl;
				}
			}

			// Задание В
			cout << endl;
			cout << "Task C" << endl;
			//string pos;
			cout << "Enter position for sort -> " << " ";
			cin >> pos;

			for (int i = 0; i < lenght; i++) {
				if (arr[i].getposition() == pos) {
					cout << arr[i].getname() << endl;
				}
			}
			break;
		case(4):
			for (int i = 0; i < lenght; i++) {
				Observer obs;
				obs.getInfo(arr[i]);
			}
			break;
		case(5):
			exit(NULL);
		}
	} while (num != 5);



	delete[] arr;
}

void Observer::getInfo(Worker& copy)
{
	cout << copy.m_age << "\n" << copy.m_name << "\n" << copy.m_position << "\n" << copy.m_salary << endl;
}
