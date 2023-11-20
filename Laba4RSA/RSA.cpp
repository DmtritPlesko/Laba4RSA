#include "RSA.h"

void RSA::Coderovka()
{
	for (size_t i = 0; i < text.size(); i++)
	{
		for (size_t j = 0; j < 32; j++)
		{
			if (text[i] == alf[j])
			{
				this->conteiner.push_back(j);
			}
		}
	}
}

void RSA::shifr()
{
	
	int c=0;
	int ost;

	for (size_t i = 0; i < text.size(); i++)
	{
		/*c = pow(this->conteiner[i], this->d);
		c = fmod(c, n);*/
		c = conteiner[i];
		ost = c;
		for (int i = 0; i < d - 1; i++)
		{
			ost = (ost * c) % n;
		}
		this->C1.push_back(ost);
	}
}

void RSA::deShifr()
{
	int cc=1;
	int ost;

	for (size_t i = 0; i < this->C1.size(); i++)
	{
		cc = C1[i];
		ost = cc;

		for (int i = 0; i < e - 1; i++)
		{
			ost = (ost * cc) % n;
		}
		this->M1.push_back(ost);
		
	}

}

void RSA::info()
{
	std::cout << "Шифруемое сообщение: " << text << std::endl
		<< "Кодировка: ";
	for (size_t i = 0; i < this->conteiner.size(); i++)
	{
		std::cout << this->conteiner[i] << " ";
	}
	std::cout << std::endl << "Зашифрованная фраза: ";
	for (size_t i = 0; i < this->C1.size(); i++)
	{
		std::cout << this->C1[i] << " ";
	}
	std::cout<<std::endl << "Расшифрованная: ";
	for (size_t i = 0; i < this->M1.size(); i++)
	{
		std::cout << this->M1[i] << " ";
	}
}

void RSA::info_parm()
{
	std::cout << std::endl << this->d << "- D" << std::endl
		<< this->e << "- E" << std::endl
		<< this->n << "- N" << std::endl
		<< this->p << "- P" << std::endl
		<< this->q << "- Q" << std::endl
		<< "P*Q-1   " << (p - 1) * (q - 1)<<std::endl;

	
}



