#include <cstdlib>
// Person class 

class Person{
	public:
		Person(int);
		int get();
		void set(int);

		// tillägg
		int fib() {
			return fib_calc(age);
		}


	private:
		int age;

		//tilägg
		int fib_calc(int n) {

			if (n<= 1) {
				return n;
			} else {
				return fib_calc(n-1) + fib_calc(n-2);
			}
		}

	};
 
Person::Person(int n){
	age = n;
	}
 
int Person::get(){
	return age;
	}
 
void Person::set(int n){
	age = n;
	}


extern "C"{
	Person* Person_new(int n) {return new Person(n);}
	int Person_get(Person* person) {return person->get();}
	void Person_set(Person* person, int n) {person->set(n);}
	int Person_fib(Person*person) {return person ->fib();} // bryggkoden
	void Person_delete(Person* person){
		if (person){
			delete person;
			person = nullptr;
			}
		}
	}