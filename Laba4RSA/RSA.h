#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include"B.h"
class RSA
{

private:
	long long  p;
	long long  q;
	long long  n;
	long long  d;
	long long  e;

	std::string text;
	std::vector<int> conteiner;
	std::vector<double> C1;
	std::vector<double>M1;



	char alf[32];
public:
	RSA(std::string _text , int _p, int _q)//констуркутор инициализации с параметрами 
	{
		this->p = _p;
		this->q = _q;

		this->n = p * q;

		

		this->text = _text;

		//все простые числа в промежутку(N)
	

		bool flag = true;
		short temp;
		//srand(time(NULL));

			temp = 1;
		while (flag)
		{
			if ((((p - 1) * (q - 1)) % temp != 0))
			{
				flag = false;
			}
			else
			{
				temp++;
				continue;
			}
		}
		this->e = temp;
		//this->d = d % 20;
		
		temp = 0;
		for (char i = 'А'; i < 'Я'; i++)
		{
			alf[temp] = i;
			temp++;
		}
		
		/*this->e = 10;
		for (int i = 2; i < n; i++)
		{
			if (((i * d) % ((p - 1) * (q - 1)) == 1))
			{
				e = i;
				break;
			}
		}*/
		temp = 1;
		while (true)
		{
			if (((temp * e) % ((p - 1) * (q - 1)) == 1))
			{
				break;
			}
			else
			{
				temp++;
			}
		}
		this->d = temp;
	}

	void Coderovka();//получения значений из алфавита 

	void shifr();

	void deShifr();

	void info();

	void info_parm();

};

