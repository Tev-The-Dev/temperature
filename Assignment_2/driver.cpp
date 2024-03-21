/////////////////////////////////////////////////////////
// Bob Myers
//
// sample.cpp -- sample test program starter for Temperature class
/////////////////////////////////////////////////////////

#include <iostream>
#include "temperature.h"

using namespace std;

int main()
{
   Temperature t1;		// should default to 0 Celsius
   Temperature t2(34.5, 'F');  // should init to 34.5 Fahrenheit 
	
   // display dates to the screen
   cout << "\nTemperature t1 is: ";
   t1.Show();			
   cout << "\nTemperature t2 is: ";
   t2.Show();
   t1.Input();			// Allow user to enter a temperature for t1
   cout << "\nTemperature t1 is: ";
   t1.Show();			
   
   t1.SetFormat('L');		// change format of t1 to "Long" format
   cout << "\nTemperature t1 is: ";
   t1.Show();
	
	//Beginning of my test cases			
	t1.SetFormat('P');
	cout << "\nTemperature t1 is: ";
	t1.Show();
	cout << "Converting to Farenheit" << endl;
	t1.Convert('F');
	t1.Show();
   // and so on.  Add your own tests to fully test the class' 
   //   functionality.
	cout << "Converting to Celcius" << endl;
	t1.Convert('C');
	t1.Show();
	cout << "Converting to Kelvin" << endl;
	t1.Convert('K');
	t1.Show();
	cout << "Let's compre t1 and t2: -1 if t1 is smaller, 0 if they are the same, 1 if t2 is smaller" << endl;
	t1.Compare(t2);
	
}
