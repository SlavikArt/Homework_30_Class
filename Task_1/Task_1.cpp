#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denumerator;

	int gcd(int a, int b);
	int lcm(int a, int b);
	void reduce();
public:
	Fraction();
	Fraction(int num, int denum);

	void Print();
	void Init();

	void Sum(int num);
	void Sum(Fraction num);

	void Subtraction(int num);
	void Subtraction(Fraction num);

	void Multiplication(int num);
	void Multiplication(Fraction num);

	void Division(int num);
	void Division(Fraction num);

	void Randomize(int k, bool redce = false);

	int getNumerator();
	int getDenumerator();
};

int Fraction::gcd(int a, int b)
{
	while (b > 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int Fraction::lcm(int a, int b)
{
	return gcd(a, b) * a * b;
}
void Fraction::reduce()
{
	int tmp = gcd(numerator, denumerator);
	numerator /= tmp;
	denumerator /= tmp;
}

Fraction::Fraction()
{
	numerator = 1;
	denumerator = 1;
}
Fraction::Fraction(int num, int denum)
{
	numerator = num;
	denumerator = denum;
}
void Fraction::Print()
{
	cout << numerator << "/" << denumerator << "\n";
}
void Fraction::Init()
{
	cout << "Enter numerator denumerator (2 3 -> 2/3): ";
	cin >> numerator >> denumerator;
}
void Fraction::Sum(int num)
{
	numerator += num * denumerator;
	reduce();
}
void Fraction::Sum(Fraction num)
{
	numerator = (lcm(denumerator, num.denumerator) / denumerator * numerator) + lcm(denumerator, num.denumerator) / num.denumerator * num.numerator;
	denumerator = lcm(denumerator, num.denumerator);
	reduce();
}
void Fraction::Subtraction(int num)
{
	numerator -= num * denumerator;
	reduce();
}
void Fraction::Subtraction(Fraction num)
{
	numerator = (gcd(denumerator, num.denumerator) / denumerator * numerator) - gcd(denumerator, num.denumerator) / num.denumerator * num.numerator;
	denumerator = gcd(denumerator, num.denumerator);
	reduce();
}
void Fraction::Multiplication(int num)
{
	numerator *= num;
	reduce();
}
void Fraction::Multiplication(Fraction num)
{
	numerator *= num.numerator;
	denumerator *= num.denumerator;
	reduce();
}
void Fraction::Division(int num)
{
	denumerator *= num;
	reduce();
}
void Fraction::Division(Fraction num)
{
	numerator *= num.denumerator;
	denumerator *= num.numerator;
	reduce();
}
void Fraction::Randomize(int k, bool redce)
{
	numerator = rand() % k + 1;
	denumerator = rand() % k + 1;
	if (redce)
	{
		reduce();
	}
}
int Fraction::getNumerator()
{
	return numerator;
}
int Fraction::getDenumerator()
{
	return denumerator;
}

int main()
{
	srand(time(0));

	Fraction obj1;

	obj1.Init();
	cout << "Sum of " << obj1.getNumerator() << "/" << obj1.getDenumerator() << " and 1/6 is: ";
	obj1.Sum(Fraction(1, 6));
	obj1.Print();

	cout << "\n";

	obj1.Init();
	cout << "Sum of " << obj1.getNumerator() << "/" << obj1.getDenumerator() << " and 4 is: ";
	obj1.Sum(4);
	obj1.Print();

	cout << "\n";

	obj1.Init();
	cout << "Subtraction of " << obj1.getNumerator() << "/" << obj1.getDenumerator() << " and 1/5 is: ";
	obj1.Subtraction(Fraction(1, 5));
	obj1.Print();

	cout << "\n";

	obj1.Init();
	cout << "Subtraction of " << obj1.getNumerator() << "/" << obj1.getDenumerator() << " and 2 is: ";
	obj1.Subtraction(2);
	obj1.Print();

	cout << "\n";

	obj1.Init();
	cout << "Multiplication of " << obj1.getNumerator() << "/" << obj1.getDenumerator() << " and 4/5 is: ";
	obj1.Multiplication(Fraction(4, 5));
	obj1.Print();

	cout << "\n";

	obj1.Init();
	cout << "Multiplication of " << obj1.getNumerator() << "/" << obj1.getDenumerator() << " and 5 is: ";
	obj1.Multiplication(5);
	obj1.Print();

	cout << "\n";

	obj1.Init();
	cout << "Division of " << obj1.getNumerator() << "/" << obj1.getDenumerator() << " and 2/3 is: ";
	obj1.Division(Fraction(2, 3));
	obj1.Print();

	cout << "\n";

	obj1.Init();
	cout << "Division of " << obj1.getNumerator() << "/" << obj1.getDenumerator() << " and 3 is: ";
	obj1.Division(3);
	obj1.Print();

	cout << "\n";
	
	cout << "Random fraction reduced is: ";
	obj1.Randomize(100, true);
	obj1.Print();

	cout << "Random fraction not reduced is: ";
	obj1.Randomize(100, false);
	obj1.Print();
}