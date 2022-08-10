#include <iostream>
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction& operator=(const Fraction& other)
	{
		numerator_ = other.numerator_;
		denominator_ = other.denominator_;
		return *this;
	}

	Fraction operator+(Fraction other)
	{
		return Fraction(numerator_ * other.denominator_ +  other.numerator_ * denominator_, denominator_ * other.denominator_);
	}
	Fraction operator-(Fraction other)
	{
		return Fraction(numerator_ * other.denominator_ - other.numerator_ * denominator_, denominator_ * other.denominator_);
	}	
	Fraction operator*(Fraction other)
	{
		return Fraction(numerator_ * other.numerator_ , denominator_ * other.denominator_);
	}
	Fraction operator/(Fraction other)
	{
		return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
	}

	Fraction& operator++() { numerator_ =  numerator_ + denominator_ ; return *this; }
	Fraction operator++(int)
	{
		Fraction temp = *this;
		++(*this);
		return temp;
	}

	Fraction& operator--() { numerator_ = numerator_ - denominator_; return *this; }
	Fraction operator--(int)
	{
		Fraction temp = *this;
		--(*this);
		return temp;
	}
	Fraction& operator-() { numerator_ = -numerator_ ; return *this; }


	bool operator==(Fraction other) { return calc() == other.calc(); }
	bool operator!=(Fraction other) { return !(*this == other); }
	bool operator>(Fraction other) { return calc() > other.calc(); }
	bool operator<(Fraction other) { return other > *this; }
	bool operator>=(Fraction other) { return !(*this < other); }
	bool operator<=(Fraction other) { return !(*this > other); }


	std::string get_value() { get_norm();  return std::to_string(numerator_) + "/" + std::to_string(denominator_); }

private:
	double calc() { return static_cast<double>(numerator_) / denominator_; }

	void get_norm() { int nod = calc_nod(numerator_, denominator_); numerator_ /= nod; denominator_ /= nod; }

	int calc_nod(int a, int b) {
		a = abs(a), b = abs(b);
		if (b == 0)return a;
		else return calc_nod (b, a % b);
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	int numerator1 = 0;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator1;
	int denominator1 = 0;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator1;

	int numerator2 = 0;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator2;
	int denominator2 = 0;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator2;

	Fraction f1(numerator1, denominator1);
	Fraction f2(numerator2, denominator2);

	Fraction res = f1 + f2;
	std::cout << f1.get_value() << " + " << f2.get_value() << " = " << res.get_value() << std::endl;

	res = f1 - f2;
	std::cout << f1.get_value() << " - " << f2.get_value() << " = " << res.get_value() << std::endl;

	res = f1 * f2;
	std::cout << f1.get_value() << " * " << f2.get_value() << " = " << res.get_value() << std::endl;

	res = f1 / f2;
	std::cout << f1.get_value() << " / " << f2.get_value() << " = " << res.get_value() << std::endl;

	std::cout << "++" << f1.get_value() << " * " << f2.get_value() << " = ";
	res = ++f1 * f2;
	std::cout << res.get_value() << std::endl;
	std::cout << "Значение дроби 1 = " << f1.get_value() << std::endl;

	res = f1-- * f2;
	std::cout << f1.get_value() << "-- * " << f2.get_value() << " = " << res.get_value() << std::endl;
	std::cout << "Значение дроби 1 = " << f1.get_value() << std::endl;

	return 0;
}
