// """
// Solutions to module MA4
// Student: Jonas Flensburg
// Mail: jonas.flensburg@gmail.com
// Reviewed by: Roman Iakymchuk
// Reviewed date: 2023-10-12
// """

#include <cstdlib>
// Person class 

class Person{
	public:
		Person(unsigned int); // ändrade alla 'int' till 'unsigned int' så fib(47) skulle funka för c++
		unsigned int get();
		void set(unsigned int);

		// tillägg
		unsigned int fib() {
			return fib_calc(age);
		}


	private:
		unsigned int age;

		//tilägg
		unsigned int fib_calc(unsigned int n) {

			if (n<= 1) {
				return n;
			} else {
				return fib_calc(n-1) + fib_calc(n-2);
			}
		}

	};
 
Person::Person(unsigned int n){
	age = n;
	}
 
unsigned int Person::get(){
	return age;
	}
 
void Person::set(unsigned int n){
	age = n;
	}


extern "C"{
	Person* Person_new(unsigned int n) {return new Person(n);}
	unsigned int Person_get(Person* person) {return person->get();}
	void Person_set(Person* person, unsigned int n) {person->set(n);}
	unsigned int Person_fib(Person*person) {return person ->fib();} // bryggkoden
	void Person_delete(Person* person){
		if (person){
			delete person;
			person = nullptr;
			}
		}
	}
