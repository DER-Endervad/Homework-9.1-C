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
		if (numerator_ == f.numerator_) {
			if (denominator_ == f.denominator_) {
				return true;
			}
		}
		return false;
	}
	bool operator!=(const Fraction& f) {
		return !(*this == f);
	}

	bool operator<(const Fraction& f) {
		if (numerator_ < f.numerator_) {
			if (denominator_ < f.denominator_) {
				return true;
			}
		}
		return false;
	}

	bool operator>(const Fraction& f) {
		if (numerator_ > f.numerator_) {
			if (denominator_ > f.denominator_) {
				return true;
			}
		}
		return false;
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

	Auto A1(6, 11);
	Auto A2(4, 3);

	std::cout << "A1" << ((A1 == A2) ? " == " : " not == ") << "A2" << '\n';
	std::cout << "A1" << ((A1 != A2) ? " != " : " not != ") << "A2" << '\n';
	std::cout << "A1" << ((A1 < A2) ? " < " : " not < ") << "A2" << '\n';
	std::cout << "A1" << ((A1 > A2) ? " > " : " not > ") << "A2" << '\n';
	std::cout << "A1" << ((A1 <= A2) ? " <= " : " not <= ") << "A2" << '\n';
	std::cout << "A1" << ((A1 >= A2) ? " >= " : " not >= ") << "A2" << '\n';
	return 0;
}
