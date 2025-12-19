#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double init_loan, rate, ppy, next;
	cout << "Enter initial loan: ";
	cin >> init_loan;
	cout << "Enter interest rate per year (%): ";
	cin >> rate;
	rate = rate * 0.01;
	cout << "Enter amount you can pay per year: ";
	cin >> ppy;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	double year = 1;
	
	while(init_loan > 0){
		next = init_loan * (1 + rate) - ppy;
		if(next < 0) {
			ppy += next;
			next = 0;
		}

		cout << fixed << setprecision(0); 
		cout << setw(13) << left << year;
		cout << fixed << setprecision(2); 
		cout << setw(13) << left << init_loan;
		cout << setw(13) << left << init_loan * rate;
		cout << setw(13) << left << init_loan * (1 + rate);
		cout << setw(13) << left << ppy;
		cout << setw(13) << left << next;
		cout << "\n";	

		year++;
		init_loan = next;

	}

	return 0;
}
