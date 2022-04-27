#include <iostream>

using namespace std;

// this class serve as a contract and only have 1 rule and whoever
// decide to sign the contract. The class will need to provide
// implementation for a method called "ask for a promotion".
class AbstractEmployee {
	virtual void AskForPromotion() = 0;
	
	};

// Parent class or super class or base class
// created a class name Employee
// if I want to implement the contract to class employee {} must add class Employee;
// employee is inherting from our abstract class just like in java our inheritance and interface
class Employee:AbstractEmployee {

// access modifier
private:
	// These 3 properties are encapsulated(private and hidden in the Employee class)
	string Name;
	string Company;
	
	
protected: 
	int Age;
// access modifer 
public:
	// use a Setter method 
	void setName(string name) {
		Name = name;
	}
	// use a Getter 
	string getName() { 
		return Name;
	}
	
	void setCompany(string company) { // setter
		Company = company;
		
	}
	string getCompany() { // Getter
		return Company;
		
	}
	void setAge(int age){ // Setter
		if(age >= 18)
			cout << " Congratulation you're qualify to apply at the company " << endl;
		else 
			cout << " Too young and try to apply at age 18 " << endl;
				
		Age = age;
	}
	int getAge() { // Getter
		return Age;
	}
	
	
	
	// Create a function CandidatesIntroduceYourself()
	// return type is void
	void CandidatesIntroduceYourself() {
		cout << " Name: " << Name << endl;
		cout << " Company: " << Company << endl;
		cout << " Age: " << Age << endl;
		
		
	}
	
		// 3 rules using constructor,1 constructor does not have a return type
		// 2. constructor have the same name as the class which is Employee
		// 3. The construct must be public but not necessarily public always
		// there are certain situations, when you would want to make your 
		// constructor private
		Employee(string name, string company, int age) {
			Name = name;
			Company = company;
			Age = age;
		}
		void AskForPromotion() { // implementing our abstract contract
			if (Age > 34)
				cout << Name << " received a promotion! " << endl;
			else 
				cout << Name << " Sorry no promotion at this time! " << endl;
			}
			
			// Implementing polymorphism
		virtual void work() {
			cout <<  Name << " will be checking email, performing calls back, task backlog...." << endl;
			
			}
};

// child class that inherited from parent class/base class Employee
class Developer:public Employee {
	public:
	string FavoriteProgrammingLanguage;
	
	Developer(string name, string company, int age, string favoriteProgrammingLanguage)
		:Employee(name, company, age)
	
	{
		FavoriteProgrammingLanguage =  favoriteProgrammingLanguage;
		
		}
		
		void FixBug() {
			
			// may use int age because moved down to protected 
			// must use getter getName to inherited from Employee and not name because of private
			cout <<getName() << " is " << Age << " years old " << "and fixed bug using " << FavoriteProgrammingLanguage << endl;
			
			}
			void work() {
			cout <<  getName() << " is writing " << FavoriteProgrammingLanguage << " code " << endl;
			
			}
			
			
};

class Professor:public Employee {
	public:
	string Subject;
	
	void PrepareLesson() {
		cout << getName() << " is preparing " << Subject << " lesson " << endl;
	}
	
	Professor(string name, string company, int age,string subject) 
	:Employee(name, company, age)
	
	{
		Subject = subject;
	}
	
	void work() {
			cout <<  getName() << " is not teaching " << Subject  << " this year " << endl;
			
			}
};

int main() { 
		
	  // construct the line of objects passing 3 parameters
	  Employee employee1 = Employee("Phong", " Omnivision", 35);
	  employee1.CandidatesIntroduceYourself();	// Created an object employee1 in employee class
	 
	  Employee employee2("Christine", "Tesla", 31);
	  employee2.CandidatesIntroduceYourself();
	  
	  Employee employee3("Johnson","Nvidia", 27);
	  employee3.CandidatesIntroduceYourself();
	  
	  employee3.setAge(25);
	  employee3.setCompany("Amazon");
	  cout << employee3.getName() << " works at " << employee3.getCompany() << " and " << employee3.getAge() << " years old " << endl;
	
	  employee1.AskForPromotion();
	  employee2.AskForPromotion();
	  employee3.AskForPromotion(); 
	  
	  Developer d=Developer(" Phong ", " Omnivision ",35, " C++ ");
	  d.FixBug();
	  d.AskForPromotion();
	
	
	  Professor p = Professor(" James ", " Cal State East Bay ", 45, " Computer Science ");
	  p.PrepareLesson();
	  p.AskForPromotion();
	  
	  
	  
	  p.work();
	  d.work();
	  
	  
	  // The most common use of polymorphism is when a parent class
	  // reference is use to refer to a child class object
	  
	  // Point of base class to reference to Developer which is  child class
	  // must go to work and implement virtual void work() to implement the pointer
	  Employee* e1 = &d;
	  Employee* e2 = &p;
	  
	e1->work();
	e2->work();
}
