#include <iostream>
#include <cstdlib>
#define _MYRATIONAL_H_
using namespace std;
class myRational
{
public:
	// Constructors
	myRational(long num = 0, long den = 1);

	myRational(const myRational& rat);
	// Accessor Functions
	long getNumerator() const;
	long getDenominator() const;
	// Member Functions
	myRational reciprocal() const;

	// friend Overloaded Operators
	friend ostream& operator <<(ostream& outStream, const myRational& r);
	friend istream& operator >>(istream& inStream, myRational& r);
	friend myRational operator + (int value, const myRational& rat);
	friend myRational operator - (int value, const myRational& rat);
	friend myRational operator * (int value, const myRational& rat);
	friend myRational operator / (int value, const myRational& rat);
	// Overloaded Operators
	myRational operator + (const myRational& rat);
	myRational operator + (const int num);
	myRational operator - (const myRational& rat);
	myRational operator - (const int num);
	myRational operator * (const myRational& rat);
	myRational operator * (const int num);
	myRational operator / (const myRational& rat);
	myRational operator / (const int num);
	myRational& operator+=(const myRational& rat);
	myRational& operator+=(const int num);
	myRational& operator-=(const myRational& rat);
	myRational& operator-=(const int num);
	myRational& operator*=(const myRational& rat);
	myRational& operator*=(const int num);
	myRational& operator/=(const myRational& rat);
	myRational& operator/=(const int num);
	// Overloaded Compare Operators
	bool operator == (const myRational& rat);
	bool operator != (const myRational& rat);
	bool operator <= (const myRational& rat);
	bool operator < (const myRational& rat);
	bool operator >= (const myRational& rat);
	bool operator > (const myRational& rat);
	// Prefix Increment/Decrement Operators
	myRational& operator++();       // 전위 증가 연산자 ++
	myRational& operator--();       // 전위 감소 연산자 --

	// Postfix Increment/Decrement Operators
	myRational operator++(int);     // 후위 증가 연산자 ++
	myRational operator--(int);     // 후위 감소 연산자 --
	myRational operator-() const;



private:
	// 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다. long _num; // numerator
	long _num;
	long _den; // denominator
	long gcd(long m, long n) const; // 최대공약수
	void reduce();
};

// Constructors
myRational::myRational(long num, long den)
{
	this->_num = num;
	this->_den = den;
	reduce();
}


myRational::myRational(const myRational& rat)
{
	_num = rat._num;
	_den = rat._den;
}
// Accessor Funtions
long myRational::getNumerator() const
{
	return _num;
}
long myRational::getDenominator() const
{
	return _den;
}
// Member Functions 기약분수를 리턴
myRational myRational::reciprocal() const
{
	return myRational(_den, _num);
}

// friend Overloaded Operators
ostream& operator <<(ostream& outStream, const myRational& r)
{
	if (r._num == 0)
		outStream << 0;
	else if (r._den == 1)
		outStream << r._num;
	else
		outStream << r._num << "/" << r._den;
	return outStream;
}
istream& operator >>(istream& inStream, myRational& r)
{
	inStream >> r._num >> r._den;
	if (r._den == 0)
	{
		r._num = 0;
		r._den = 1;
	}
	r.reduce();
	return inStream;
}
myRational operator + (int value, const myRational& rat)
{
	return myRational(rat.getNumerator(), rat.getDenominator()) + value;
}
myRational operator - (int value, const myRational& rat)
{
	return myRational(value,1) - rat;
}
myRational operator * (int value, const myRational& rat)
{
	return myRational(rat.getNumerator(), rat.getDenominator()) * value;
}
myRational operator / (int value, const myRational& rat)
{
	return myRational(value,1) / rat;
}
// Overloaded Operators
myRational myRational::operator + (const myRational& rat)
{
	long gcdi = gcd(_den, rat.getDenominator());
	long n1 = rat.getDenominator() / gcdi;
	long n2 = _den / gcdi;
	long new_den = gcdi * n1 * n2;
	long new_num = _num * new_den / _den + rat.getNumerator() * new_den / rat.getDenominator();

	return myRational(new_num, new_den);
}
myRational myRational::operator + (const int num)
{
	long new_num = _num + _den * num;
	return myRational(new_num, _den);
}

myRational myRational::operator - (const myRational& rat)
{
	int new_num = _num * rat._den - _den * rat._num;
	int new_den = _den * rat._den;
	return myRational(new_num, new_den);
}
myRational myRational::operator - (const int num)
{
	long new_num = _num - _den * num;
	return myRational(new_num, _den);
}

myRational myRational::operator * (const myRational& rat)
{
	long new_num = _num * rat.getNumerator();
	long new_den = _den * rat.getDenominator();

	return myRational(new_num, new_den);
}
myRational myRational::operator * (const int num)
{
	long new_num = _num * num;

	return myRational(new_num, _den);
}

myRational myRational::operator / (const myRational& rat)
{
	return myRational(_num, _den) * rat.reciprocal();
}

myRational myRational::operator / (const int num)
{
	return myRational(_num, _den) / myRational(num);
}

bool myRational::operator==(const myRational& rat)
{
	return _num == rat._num && _den == rat._den;
}

bool myRational::operator!=(const myRational& rat)
{
	return !(*this == rat);
}
bool myRational::operator<=(const myRational& rat)
{
	// num1 / den1 <= num2 / den2
	// => num1 * den2 <= num2 * den1
	return _num * rat._den <= rat._num * _den;
}

bool myRational::operator<(const myRational& rat)
{
	// num1 / den1 < num2 / den2
	// => num1 * den2 < num2 * den1
	return _num * rat._den < rat._num* _den;
}

bool myRational::operator>=(const myRational& rat)
{
	// num1 / den1 >= num2 / den2
	// => num1 * den2 >= num2 * den1
	return _num * rat._den >= rat._num * _den;
}

bool myRational::operator>(const myRational& rat)
{
	// num1 / den1 > num2 / den2
	// => num1 * den2 > num2 * den1
	return _num * rat._den > rat._num * _den;
}

myRational& myRational::operator+=(const myRational& rat)
{
	long gcdi = gcd(_den, rat._den);
	long n1 = rat._den / gcdi;
	long n2 = _den / gcdi;
	long new_den = gcdi * n1 * n2;
	long new_num = _num * new_den / _den + rat._num * new_den / rat._den;
	_num = new_num;
	_den = new_den;
	reduce();
	return *this;
}

myRational& myRational::operator+=(const int num)
{
	_num += _den * num;
	reduce();
	return *this;
}

myRational& myRational::operator-=(const myRational& rat)
{
	long gcdi = gcd(_den, rat._den);
	long n1 = rat._den / gcdi;
	long n2 = _den / gcdi;
	long new_den = gcdi * n1 * n2;
	long new_num = _num * new_den / _den - rat._num * new_den / rat._den;
	_num = new_num;
	_den = new_den;
	reduce();
	return *this;
}

myRational& myRational::operator-=(const int num)
{
	_num -= _den * num;
	reduce();
	return *this;
}

myRational& myRational::operator*=(const myRational& rat)
{
	_num *= rat._num;
	_den *= rat._den;
	reduce();
	return *this;
}

myRational& myRational::operator*=(const int num)
{
	_num *= num;
	reduce();
	return *this;
}

myRational& myRational::operator/=(const myRational& rat)
{
	*this *= rat.reciprocal();
	reduce();
	return *this;
}

myRational& myRational::operator/=(const int num)
{
	*this /= myRational(num);
	reduce();
	return *this;
}

// 후위 증가 연산자 ++
myRational myRational::operator++(int)
{
	myRational temp(*this);
	++(*this);  // 전위 증가 연산자 호출
	return temp;
}

// 후위 감소 연산자 --
myRational myRational::operator--(int)
{
	myRational temp(*this);
	--(*this);  // 전위 감소 연산자 호출
	return temp;
}

// 전위 증가 연산자 ++
myRational& myRational::operator++()
{
	// 1을 분자에 더하고 기약분수로 간소화
	_num += _den;
	reduce();
	return *this;
}

// 전위 감소 연산자 --
myRational& myRational::operator--()
{
	// 1을 분자에서 빼고 기약분수로 간소화
	_num -= _den;
	reduce();
	return *this;
}

myRational myRational::operator-() const
{
	return myRational(-_num, _den);
}

long myRational::gcd(long m, long n) const
{
	while (m != n)
	{
		if (m < n)
			n -= m;
		else
			m -= n;
	}
	return n;
}
void myRational::reduce()
{
	if (_num == 0 || _den == 0)
	{
		_num = 0;
		_den = 1;
		return;
	}
	if (_den < 0)
	{
		_den *= -1;
		_num *= -1;
	}
	if (_num == 1)
		return;
	int sgn = (_num < 0 ? -1 : 1);
	long g = gcd(sgn * _num, _den);
	_num /= g;
	_den /= g;
}


void testSimpleCase();
void testDataFromFile();

int main()
{
	testSimpleCase();
	testDataFromFile();
	return 0;
}

void testSimpleCase()
{
	myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
	cout << frac1 << " " << frac2 << " " << frac3 << " "
		<< frac4 << " " << frac5 << endl;
	cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;
	// Check arithmetic operators
	cout << frac1 * frac2 << " "
		<< frac1 + frac3 << " "
		<< frac2 - frac1 << " "
		<< frac3 / frac2 << endl;
	// Check comparison operators
	
		cout << ((frac1 < frac2) ? 1 : 0) << " "
		<< ((frac1 <= frac2) ? 1 : 0) << " "
		<< ((frac1 > frac2) ? 1 : 0) << " "
		<< ((frac1 >= frac2) ? 1 : 0) << " "
		<< ((frac1 == frac2) ? 1 : 0) << " "
		<< ((frac1 != frac2) ? 1 : 0) << " "
		<< ((frac2 < frac3) ? 1 : 0) << " "
		<< ((frac2 <= frac3) ? 1 : 0) << " "
		<< ((frac2 > frac3) ? 1 : 0) << " "
		<< ((frac2 >= frac3) ? 1 : 0) << " "
		<< ((frac2 == frac3) ? 1 : 0) << " "
		<< ((frac2 != frac3) ? 1 : 0) << endl;
	cout << (frac6 = frac3) << " ";
	cout << (frac6 += frac3) << " ";
	cout << (frac6 -= frac3) << " ";
	cout << (frac6 *= frac3) << " ";
	cout << (frac6 /= frac3) << endl;
	cout << -frac6 << endl;
	frac6 = (++frac4) + 2;
	frac7 = 2 + (frac4++);
	cout << frac4 << " " << frac6 << " " << frac7 << endl;
	frac6 = (--frac4) - 2;

	frac7 = 2 - (frac4--);
	cout << frac4 << " " << frac6 << " " << frac7 << endl;
	cout << 2 * frac3 << " " << frac3 * 2 << " "
		<< 2 / frac3 << " " << frac3 / 2 << endl;
}
void testDataFromFile()
{
	int T;
	std::cin >> T;

	while (T--)
	{
		myRational arr[100]{};

		int N;
		std::cin >> N;

		for (int i = 0; i < N; i++)
		{
			int num, den;
			std::cin >> num >> den;
			myRational rat = myRational(num, den);
			arr[i] = rat;
		}

		for (int i = 1; i < N; i++)
		{
			for (int j = i; j > 0; j--)
			{
				if (arr[j - 1] > arr[j])
				{
					myRational temp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = temp;
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			std::cout << arr[i] << " ";
		}

		std::cout << "\n";
	}
}