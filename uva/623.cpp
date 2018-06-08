#include <iostream>
#include <vector>

using namespace std;

#define MAX_FACTORIAL 1001

#define MAX_DIGIT 1000

struct BigNum
{
public:
// private:
	char d[MAX_DIGIT];
	int digit;

	void initDigit()
	{
		for(int i = 0; i < MAX_DIGIT; i++)
			d[i] = 0;
	}

public:
	BigNum()
	{
		digit = 0;
		initDigit();
	}
	BigNum(int n)
	{
		initDigit();
		digit = 0;

		int i = 0;
		while(n > 9)
		{
			d[i++] = n % 10;
			n /= 10;
			digit++;
		}
		d[i++] = n;
		digit++;
	}
	BigNum(BigNum &b)
	{
		digit = b.digit;
		initDigit();

		for(int i = 0; i < digit; i++)
		{
			d[i] = b.d[i];
		}
	}
	BigNum(const char num[])
	{
		digit = strlen(num);
		initDigit();

		int l = strlen(num);
		for(int i = l-1; i >= 0; i--)
		{
			d[l-1 - i] = num[i] - '0';
		}
	}

	// relation operators
	friend bool operator!=(const BigNum& lhs, const BigNum& rhs);
	friend bool operator==(const BigNum& lhs, const BigNum& rhs);

	// arithmetic operators
	//
	// Addition
	BigNum& operator+=(const BigNum& rhs)
	{
		int dSize = digit, rhsSize = rhs.digit;
		const char *up = dSize > rhsSize ? d : rhs.d;
		const char *down = dSize > rhsSize ? rhs.d : d;
		int upLength = max(dSize, rhsSize), downLength = min(dSize, rhsSize);

		digit = upLength;
		for(int i = 0; i < upLength; i++)
		{
			int tmp = 0;

			// addition
			if(i < downLength)
			{
				tmp += up[i] + down[i];
			}
			else
			{
				tmp += up[i];
			}

			// carry
			if(tmp > 9)
			{
				tmp -= 10;
				d[i+1]++;
				d[i] = tmp;

				if(i == upLength - 1)
					digit++;
			}

			// cout << (char)(d[i] + '0') << ' ';
		}
		// cout << "d: " << digit << endl;

		return *this;
	}
	// friend BigNum operator+(const BigNum& lhs, const BigNum& rhs);

	// Multiplication
	BigNum& operator*=(const BigNum& rhs)
	{
		// This may have some performance problem
		BigNum end(0);
		BigNum step(1);

		while(rhs != end)
		{
			(*this) += rhs;
			end += step;
		}

		return *this;
	}

	BigNum& operator*=(const int n)
	{
		BigNum tmp(n);

		(*this) += tmp;
		return *this;
	}

	void printNumber()
	{
		for(int i = digit-1; i >= 0; i--)
		{
			putchar(d[i] + '0');
		}
	}
};

// BigNum operator+(const BigNum& lhs, const BigNum& rhs)
// {
// 	BigNum tmp(0);
// 	tmp += lhs;
// 	tmp += rhs;
// 	return tmp;
// }

bool operator!=(const BigNum& lhs, const BigNum& rhs)
{
	if(lhs.digit == rhs.digit)
	{
		int tmp = 0;
		for(int i = 0; i < lhs.digit; i++)
		{
			if(lhs.d[i] == rhs.d[i])
				tmp++;
		}

		if(tmp == lhs.digit)
			return false;
		else
			return true;
	}
	else
	{
		return true;
	}
}

bool operator==(const BigNum& lhs, const BigNum& rhs)
{
	return !(lhs != rhs);
}

// int factorialProduct(const int n)
// {
// 	if(!factorial[n])
// 	{
// 		for(int i = 2; i <= n; i++)
// 		{
// 			factorial[i] = factorial[i-1] * (long long int)i;
// 		}
// 	}
// 	return factorial[n];
// }

int main()
{
	#ifndef ONLINE_JUDGE
	// freopen("./testdata/623.in", "r", stdin);
	// freopen("./testdata/623.out", "w", stdout);
	#endif
	BigNum a("111"), b(111);
	BigNum c = b;

	// cout << c.digit << endl;
	// cout << "c.printNumber: "; c.printNumber(); putchar('\n');
	// cout << a.digit << endl;
	// cout << "a.printNumber: "; a.printNumber(); putchar('\n');

	cout << endl;

	c += a;
	cout << c.digit << endl;
	cout << "c.printNumber: "; c.printNumber(); putchar('\n');

	if(a == c)
		cout << "a = b" << endl;
	else
	{
		cout << "a != b" << endl;
	}
	// int num;
	// BigNum sum(1);

	// while(scanf("%d", &num) != EOF)
	// {
	// 	BigNum tmp(num);
	// 	// tmp.printNumber();
	// 	// sum += tmp;
	// 	sum *= tmp;
	// 	sum.printNumber();
	// 	putchar('\n');
	// 	// printf("%d!\n", num);
	// 	// printf("%d\n", factorialProduct(num));
	// }
	// BigNum a(10), b(20), c(10);

	// if(a == c)
	// {
	// 	printf("a === b\n");
	// }
	// else
	// {
	// 	printf("a != b\n");
	// }

	return 0;
}