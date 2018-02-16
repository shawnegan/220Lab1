//============================================================================
// Group: Justin Schnee, Shawn Egan
// TA :
// Date :
// Lab: One
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x);
int sum(int x, int y);
int collatz();
void leapYear();
void star(int x);
void collatzCheck(int x, int y);

int main() {
	cout << "Problem 1" << endl;
	cout << "Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << "***********************************" << endl;

	cout << "Problem 2" << endl;
	cout << isPrime(1) << endl; // Expected: False (0 returned)
	cout << isPrime(2) << endl; // Expected: True (1)
	cout << isPrime(27) << endl; // Expected: False (0)
	cout << "***********************************" << endl;

	cout << "Problem 3" << endl;
	cout << sum(0,4) << endl; // Expected: 6
	cout << sum(9,7) << endl; // Expected: 15
	cout << sum(11,12) << endl; //Expected: 11
	cout << "***********************************" << endl;

	cout << "Problem 6" << endl;
	star(9); // Expected: X with leg length 8
	star(3); // Expected: X with leg length 2
	star(5); // Expected: X with leg length 4
	return 0;

}

/*
 * this function takes one integer as input and
 * returns a boolean; true (1) if the integer is
 * prime, and false (0) if the integer is
 * composite.
 */
bool isPrime(int x) {
	if(x == 1){
		return false;
	}
	int a = 2;
	bool b = false;
	while(a <= sqrt(x)){
		if(x%a == 0){
			return b;
		}
		a++;
	}
	return !b;
}

/*
 * This function takes two integers as input and
 * returns an integer that is the sum of all
 * integers between the input integers.
 * The sum includes the smaller integer but not
 * the larger integer.
 */
int sum(int x, int y) {
	int sum = 0;
	if(x>=y){
		for(int a = y; a < x; a++) {
			sum = sum + a;
		}
		return sum;
	}else{
		for(int b = x; b < y; b++) {
			sum = sum + b;
		}
		return sum;
	}
}

/*
 * This function prompts the user to input a positive
 * natural number, and returns as an integer
 * the number of iterations of the Collatz Conjecture
 * for that input number.
 */
int collatz(){
	int n;
	cout << "Please enter a positive natural number: ";
	cin >> n;
	int count = 0;
	while(n != 1) {
		if(n%2 == 0){
			n = n/2;
		}else{
			n = 3*n +1;
		}
		count += 1;
	}
	return count;
}

/*
 * This function has no input, but prints out all years
 * between 2017 and 2417 that are leap years.
 */
void leapYear(){
	int year = 2017;
	while(year <= 2417){
		if (year%4 == 0){
			if (year%100 == 0){
				if(year%400 == 0){
					cout << year << endl;
					year += 1;
				}else{
					year += 1;
				}
			}else{
				cout << year << endl;
				year += 1;
			}
		}else{
			year += 1;
		}
	}
}

/*
 * This function takes an integer (n) as input
 * and prints an x out of asterisks with
 * each leg of the x composed of n-1 asterisks.
 */
void star(int x){
	if(x%2 == 0){
		x += 1;
	}
	int width = 2*x - 2;
	int count = 1;
	while(count < x+1){
		//this loop prints the top half of the x
		int spaceb4 = count*2 - 1;
		while(spaceb4 > 0){
			//prints spaces necessary before
			//first asterisk
			cout << " ";
			spaceb4--;
		}
		cout << "*";
		if(width == 0){
			//takes care of center asterisk
			cout << "";
		}else{
			//prints second asterisk if not
			//at center
			int spaces = width*2-1;
			while(spaces > 0){
				//prints necessary space
				//between the asterisks
				cout << " ";
				spaces--;
			}
			cout << "*" << endl;
		}

		width -= 2;
		count++;
	}
	cout << endl;
	int countbot = x-1;
	int widthbot = 1;
	while(countbot > 0){
		//this loop prints the bottom half of the loop
		int spaceb4 = countbot*2-1;
		while(spaceb4 > 0){
			//takes care of space before
			//first asterisk
			cout << " ";
			spaceb4--;
		}
		cout << "*";
		int spaces = 2*widthbot +1;
		while(spaces > 0){
			//takes care of spaces between
			//the two asterisks
			cout << " ";
			spaces--;
		}
		cout << "*" << endl;
		widthbot  +=2;
		countbot--;
	}
}

/*
 * This function takes two integers as
 * input, and checks that the Collatz Conjecture
 * holds for all integers, including the smaller,
 * between the two input integers. The output is
 * each integer in the interval, and the line
 * after each integer shows the Collatz Conjecture
 * works.
 */
void collatzCheck(int x, int y) {
	for(int a = x; a < y; a++){
		cout << a << endl;
		int n = a;
		while(n != 1) {
			if(n%2 == 0){
				n = n/2;
			}else{
				n = 3*n +1;
			}
		}
		cout << "Collatz Conjecture is still working." << endl;
	}
}
