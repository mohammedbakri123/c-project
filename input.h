#pragma once
#include<iostream>
#include <string>
#include<cctype>
using namespace std;
namespace input
{

	int read_int_number(string message, int higher = 1000000000, int lower = -1000000000)
	{
		int x;
		cout << message;
		cin >> x;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
			cout << "         Invalid number, please enter an integer : ";
			cin >> x;
		}
		while (x > higher || x < lower)
		{
			cout << "         Please enter number between " << lower << " and " << higher << ": ";
			cin >> x;
		}
		return x;
	}
	int read_marks(string message)
	{
		int x;
		cout << message;
		cin >> x;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
			cout << "         Invalid number, please enter an imteger : ";
			cin >> x;
		}
		while (x > 100 || x < 0)
		{
			cout << "         Please enter number between 0 and 100 : ";
			cin >> x;
		}
		return x;
	}
	int read_positive_numbers()
	{
		int number = 0;
		do
		{
			string message = "please entre a positive number : ";
			cout << message << endl;
			cin >> number;

		} while (number <= 0);
		return number;
	}

	char read_character(string massege)
	{
		char cha;
		cout << massege;
		cin >> cha;
		return cha;
	}
	string read_names(string message)
	{
		cout << message;
		string text;
	name:
		cin >> text;
		
		for (int i = 0; i < text.size(); i++)
		{
			if(isalpha(text[i]))
			{
				if (i == 0)
					text[i] = toupper(text[i]);
				else
					text[i] = tolower(text[i]);
			}
			else
			{
				cout << "        =================================" << endl;
				cout << "        invaild name" << endl;
				cout << "        please reenter the name :";
				goto name;
			}
		}
		return text;
	}
	void read_array_of_int(int arr[100], int& lengtharr)
	{


		for (int i = 0; i <= lengtharr - 1; i++)
		{
			cout << "Element [ " << i + 1 << " ] : "; cin >> arr[i];

		}
		cout << endl;
	}
	void fell_array_from_1_to_n(int arr[100], int& arrlength)
	{
		arrlength = read_int_number("please enter the lenght of the array and it will be felled according to the length resbectivly : ");
		for (int i = 0; i < arrlength; i++)
		{
			arr[i] = i + 1;
		}

	}
}
