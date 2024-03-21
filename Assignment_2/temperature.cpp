/*
Tevyn Payne
COP 3330 Section 7
Assignment 2

This assignment is meant to give further practice with the creation of classes. This time
we will be implementing the keyword const wherever it is needed.
*/

#include <iomanip>
#include <iostream>
#include <cctype>
#include "temperature.h"

using namespace std;
Temperature::Temperature()
{
	degrees = 0;
	scale = 'C';
}

Temperature::Temperature(double deg, char s)
{	
	s = toupper(s);
	Set(deg,s);
}

void Temperature::Input()
{	
	double deg;
	char s;
	do{
	cout << "Enter in a temperature and the scale" << endl;
	cin >> deg >> s;
	s = toupper(s);
	Set(deg, s);
	}while(Set(deg, s) == false);
}
void Temperature::Show() const
{	
	int oldprecision = cout.precision();	
	if(format == 'D')
	{
		cout << degrees << " " << scale << endl;
	}
	else if(format == 'P')
	{
		cout << fixed << setprecision(1) << degrees << " " <<scale << endl;
	}
	else if(format == 'L')
	{
		cout << degrees;
		if(scale == 'C' || scale == 'c')
		cout << " Celcius" << endl;
		else if(scale == 'F' || scale == 'f')
		{
		cout << " Farenheit" << endl;
		}
		else if(scale == 'K' || scale == 'k')
		{
		cout << " Kelvin" << endl;
		}

	}
	else 
	cout << degrees << " " << scale << endl;
	cout.precision(oldprecision);	// restore old precision setting
}


bool Temperature::Set(double deg, char s)
{
	s = toupper(s);
	if(s == 'C' || s == 'c')
        {	
		if(deg < -273.15)
		return false;
                else if(deg >= -273.15)
                degrees = deg;
		scale = s;
        	return true;
	}
        else if(s == 'F' || s == 'f')
        {
		if(deg < -459.67)
		return false;
                else if(deg >= -459.67)
                degrees = deg;
		scale = s;
	 	return true;
	}
        else if(s == 'K' || s == 'k')
        {	
		if(deg < 0)
		{
		return false;
		}
                else if(deg >= 0)
                degrees = deg;
		scale = s;
		return true;
	}
	else
	return false;
}

double Temperature::GetDegrees() const
{

return degrees;
}
char Temperature::GetScale() const
{
return scale;
}

bool Temperature::SetFormat(char f)
{
	
	toupper(f);
	if(f == 'D')
	{
	format = f;
	return true;
	}
	else if(f == 'P')
	{
	format = f;
	return true;
	}
	else if(f == 'L')
	{
	format = f;
	return true;
	}
	else
	return false;		//returns 0 if not able to be set
}
bool Temperature::Convert(char sc)
{
	sc = toupper(sc);
	if( sc == 'F')
	{
		if(sc == scale)
		return false;
		else if(scale == 'C')
		{
		//converstion from Celcius to Farenheit
		degrees = (degrees*1.8)+32;
		scale = 'F';
		return true;
		}
		else if(scale == 'K')
		{
		//conversion from Kelvin to Farenheit
		degrees = (degrees -273.15)*1.8+32;
		scale = 'F';
		return true;
		}
	}
	else if(sc == 'C')
	{
		if(sc == scale)
 		return false;
		else if(scale == 'F')
		{
		//conversion from Farenheit to Celcius
		degrees = (degrees -32);
		degrees = 0.5555555555555*degrees;
 		scale = 'C';
		return true;
		}
		else if(scale == 'K')
		{
		//conversion from Kelvin to Celcius
		degrees = degrees - 273.15;
		scale = 'C';
		return true;
		}
	}
	else if(sc == 'K')
	{
		if(sc == scale)
		return false;
		else if(scale == 'C')
		{
		//conversion from Celcius to Kelvin
		degrees = degrees + 273.15;
		scale = 'K';
		return true;
		}
		else if(scale == 'F')
		{
		//conversion from Farenheit to Kelvin
		degrees = (degrees -32)*(5/9) + 273.15;
		scale = 'K';
		return true;
		}
	}	
	
}
int Temperature::Compare(const Temperature& d)
{
	if(d.scale != scale)
	{
		Convert(scale);
		if(d.degrees == degrees)
		{
		cout << "0"<< endl;
		return 0;
		}
		else if(d.degrees > degrees)
		{
		cout << "-1" << endl;
			return -1;
		}
		else
		{	
		cout << "1" << endl;
		return 1;
		}
	}
	else
		if(d.degrees == degrees)
		cout << "0" << endl;
		else if (d.degrees > degrees)
		cout << "-1" << endl;
		else
		cout << "1" << endl;	

return 1;
}
