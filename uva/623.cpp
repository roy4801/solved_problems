#include <iostream>
#include <vector>

using namespace std;

#define MAX_FACTORIAL 1001

struct BigNum
{
	vector<char> d;

	BigNum() {}
	BigNum(int n)
	{
		while(n > 9)
		{
			d.push_back(n % 10);
			n /= 10;
		}
		d.push_back(n);
	}
	BigNum(BigNum &b)
	{
		d = b.d;
	}

	// relation operators
	friend bool operator!=(const BigNum& lhs, const BigNum& rhs);
	friend bool operator==(const BigNum& lhs, const BigNum& rhs);

	// arithmetic operators
	BigNum& operator+=(const BigNum& rhs)
	{
		int dSize = d.size(), rhsSize = rhs.d.size();
		const vector<char> up = dSize > rhsSize ? d : rhs.d;
		const vector<char> down = dSize > rhsSize ? rhs.d : d;
		int upLength = max(dSize, rhsSize), downLength = min(dSize, rhsSize);

		// putchar('\n');
		// putchar('\n');
		// cout << dSize << ' ' << rhsSize << endl;
		// cout << "U:" << upLength << ' ' << "D:" << downLength << endl;
		// for(auto i = up.rbegin(); i != up.rend(); i++)
		// {
		// 	putchar(*i + '0');
		// }
		// putchar('\n');
		// putchar('\n');

		for(int i = 0; i < upLength; i++)
		{
			// addition
			if(i < downLength)
			{
				d[i] = up[i] + down[i];
			}
			else
			{
				d.push_back(up[i]);
			}

			// carry
			if(d[i] > 9)
			{
				d[i] -= 10;

				// last digit
				if(i == upLength - 1)
				{
					d.push_back(1);
				}
				else
				{
					d[i+1]++;
				}
			}
		}

		return *this;
	}
	friend BigNum operator+(const BigNum& lhs, const BigNum& rhs);

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

	void printNumber()
	{
		for(int i = d.size()-1; i >= 0; i--)
		{
			putchar(d[i] + '0');
		}
	}
};

BigNum operator+(const BigNum& lhs, const BigNum& rhs)
{
	BigNum tmp(0);
	tmp += lhs;
	tmp += rhs;
	return tmp;
}

bool operator!=(const BigNum& lhs, const BigNum& rhs)
{
	if(lhs.d.size() == rhs.d.size())
	{
		int tmp = 0;
		for(int i = 0; i < lhs.d.size(); i++)
		{
			if(lhs.d[i] == rhs.d[i])
				tmp++;
		}

		if(tmp == lhs.d.size())
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
	freopen("./testdata/623.in", "r", stdin);
	// freopen("./testdata/623.out", "w", stdout);
	#endif
	int num;
	BigNum sum(1);

	while(scanf("%d", &num) != EOF)
	{
		BigNum tmp(num);
		// tmp.printNumber();
		// sum += tmp;
		sum *= tmp;
		sum.printNumber();
		putchar('\n');
		// printf("%d!\n", num);
		// printf("%d\n", factorialProduct(num));
	}

	return 0;
}