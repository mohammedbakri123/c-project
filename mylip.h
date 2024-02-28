#pragma once
#include<iostream>
#include <string>
#include<cmath>
#include"input.h"
using namespace std;
using namespace input;
enum oddoreven { odd = 1, even = 2 };
namespace mylip
{
	bool check_prime_number(int num)
	{
		int counter;
		for (counter = 2; ;)
			if (num < 0)
			{
				return false;


			}
			else
			{
				if (num <= counter)
				{
					return true;
				}
				else
				{
				j:
					if (num % counter == 0)
					{
						return false;
					}
					else (num % counter != 0);
					{
						if (counter == num - 1)
						{
							return true;

						}
						else
							counter++;
						goto j;
					}
				}

			}


	}
	bool is_prime(int num)
	{
		int m = round(num / 2);
		for (int counter = 2; counter <= m; counter++)
		{
			if (num % counter == 0)
				return false;
		}
		return true;
	}
	void swap(int& a, int& b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}
	oddoreven check_odd_or_even(int number)
	{
		if (number % 2 == 0)
		{
			return oddoreven::even;
		}
		else
		{
			return oddoreven::odd;
		}


	}
	bool check_password(int password, int ask_pass)
	{

		if (password == ask_pass)
			return true;
		else
			return false;

	}

}
