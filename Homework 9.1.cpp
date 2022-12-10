#include <iostream>

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
	bool operator==(const Fraction& f) {
		int n1 = numerator_, d1 = denominator_, n2 = f.numerator_, d2 = f.denominator_;
		if (d1 != d2) {
			n1 = n1 * d2;
			n2 = n2 * d1;
			d1 = d1 * d2;
			d2 = d1;
		}
		if (n1 == n2) {
			return true;
		}
		else return false;
	}
	bool operator!=(const Fraction& f) {
		return !(*this == f);
	}

	bool operator<(const Fraction& f) {
		int n1 = numerator_, d1 = denominator_, n2 = f.numerator_, d2 = f.denominator_;
		if (d1 != d2) {
			n1 = n1 * d2;
			n2 = n2 * d1;
			d1 = d1 * d2;
			d2 = d1;
		}
		if (n1 < n2) {
			return true;
		}
		else return false;
	}

	bool operator>(const Fraction& f) {
		int n1 = numerator_, d1 = denominator_, n2 = f.numerator_, d2 = f.denominator_;
		if (d1 != d2) {
			n1 = n1 * d2;
			n2 = n2 * d1;
			d1 = d1 * d2;
			d2 = d1;
		}
		if (n1 > n2) {
			return true;
		}
		else return false;
	}

	bool operator<=(const Fraction& f) {
		return !(*this > f);
	}

	bool operator>=(const Fraction& f) {
		return !(*this < f);
	}
};

class Auto
{
private:
	int numerator_;
	int denominator_;

public:
	Auto(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	auto operator<=>(const Auto&) const = default;
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	std::cout << std::endl;

	Auto A1(4, 3);
	Auto A2(6, 11);

	std::cout << "A1" << ((A1 == A2) ? " == " : " not == ") << "A2" << '\n';
	std::cout << "A1" << ((A1 != A2) ? " != " : " not != ") << "A2" << '\n';
	std::cout << "A1" << ((A1 < A2) ? " < " : " not < ") << "A2" << '\n';
	std::cout << "A1" << ((A1 > A2) ? " > " : " not > ") << "A2" << '\n';
	std::cout << "A1" << ((A1 <= A2) ? " <= " : " not <= ") << "A2" << '\n';
	std::cout << "A1" << ((A1 >= A2) ? " >= " : " not >= ") << "A2" << '\n';
	return 0;
}
