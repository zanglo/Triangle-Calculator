#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Triangle
{
protected: 
	string name;
	double a, b, c;
	
public: 
	virtual void calculate() const = 0;
};

class SAS : public Triangle  // solves for missing side only for now
{
public:
	SAS()
	{
		name = "ASA";
		a = 0;
		b = 0;
		c = 0;
	}
	SAS(string myName, double x, double y, double z)
	{
		name = myName;
		a = x;
		b = y;
		c = z;
	}
	virtual void calculate() const // d^2 (missing side) = a^2 + c^2 - 2ac cosb
	{
		// b needs to be in Radians
		// f and e need to be converted to degrees
		double bR;
		double d; // missing side
		double d2; // missing side squared
		double e; // missing angle
		double eD;
		double f; // missing angle
		double fD;

		bR = b * 3.14 / 180;
		d2 = (a * a) + (c * c) - 2 * a * c * cos(bR);
		d = sqrt(d2);
		e = acos(((a * a) - (c * c) - (d * d)) / (-2 * c * d));
		eD = e * 180 / 3.14;
		f = acos(((c * c) - (a * a) - (d * d)) / (-2 * a * d));
		fD = f * 180 / 3.14;
		cout << "Triangle: " << name << endl;
		cout << "The missing side is: " << d << " units long." << endl;
		cout << "The first missing angle is " << eD << " degrees." << endl;
		cout << "The second missing angle is " << fD << " degrees." << endl;
		cout << "---------------------------" << endl;	
	}
};
class ASA : public Triangle  // solves for missing angle and sides
{
public:
	ASA()
	{
		name = "ASA";
		a = 0;
		b = 0;
		c = 0;
	}
	ASA(string myName, double x, double y, double z)
	{
		name = myName;
		a = x;
		b = y;
		c = z;
	}
	virtual void calculate() const // 180 - a - c = d
	{
		// a, c, and d need to be converted to radians.
		double aR;
		double cR;
		double dR;
		double d; // missing angle
		double e; //missing side
		double f; //missing side
		d = 180 - a - c;
		aR = a * 3.14 / 180;
		cR = c * 3.14 / 180;
		dR = d * 3.14 / 180;
		e = (b / sin(dR)) * sin(aR);
		f = (b / sin(dR)) * sin(cR);
		cout << "Triangle: " << name << endl;
		cout << "The missing angle is: " << d << " degrees." << endl;
		cout << "The first missing side is: " << e << " units long." << endl;
		cout << "The second missing side is: " << f << " units long." << endl;
		cout << "---------------------------" << endl;
	}
};
void triangleTrig(Triangle* p);
void showMenu();
char getMenuChoice();

void triangleTrig(Triangle* p)
{
	p->calculate();
}
void showMenu()
{
	cout << "------ Triangle Trig Calculator ------" << endl;
	cout << "A. Add SAS triangle" << endl;
	cout << "B. Add ASA triangle" << endl;
	cout << "C. Calculate all triangles" << endl;
	cout << "D. Quit" << endl;
	cout << "Enter Selection: ";
}
char getMenuChoice()
{
	char choice;
	cin >> choice;
	return choice;
}

int main()
{
	char choice;
	vector <Triangle*> v;
	do
	{
		showMenu();
		choice = toupper(getMenuChoice());
		switch (choice)
		{
		case 'A':
		{
			double x;
			double y;
			double z;
			string myName;
			cout << "--- New SAS Triangle ---" << endl;
			cout << "New Triangle Name: ";
			cin >> myName;
			cout << "Enter First Side: ";
			cin >> x;
			cout << "Enter Angle: ";
			cin >> y;
			cout << "Enter Second Side: ";
			cin >> z;
			SAS newSAS(myName, x, y, z);
			Triangle* t1;
			t1 = &newSAS;
			v.push_back(t1);
		}
			break;
		case 'B':
		{
			double x;
			double y;
			double z;
			string myName;
			cout << "------- New ASA Triangle ---------" << endl;
			cout << "Name New Triangle: ";
			cin >> myName;
			cout << "Enter First Angle: ";
			cin >> x;
			cout << "Enter Side: ";
			cin >> y;
			cout << "Enter Second Angle: ";
			cin >> z;
			ASA newASA(myName, x, y, z);
			Triangle* t1;
			t1 = &newASA;
			v.push_back(t1);
		}
			break;
		case 'C':
			for (int x = 0; x < v.size(); x++)
			{
				v[x]->calculate();
			}
			break;

		}

	} while (choice != 'd' && choice != 'D');

	cout << "Goodbye . . . " << endl;
	return 0;
}
