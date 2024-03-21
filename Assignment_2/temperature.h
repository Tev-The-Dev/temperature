/*
Tevyn Payne
COP 3330 Section 7 
Assignment 2

This assignment is meant to give further practice with the creation of classes. This time
we will be implementing the keyword const wherever it is needed.
*/

class Temperature
{
	public:
	Temperature();
	Temperature(double, char);
	
	void Input();
	void Show()const;
	
	bool Set(double deg, char s);
	
	double GetDegrees()const;
	char GetScale()const;

	bool SetFormat(char f);

	bool Convert(char sc);
	
	int Compare(const Temperature& d);

	private:
	void Check(int , char);

	double degrees;
	char scale, format;
};
