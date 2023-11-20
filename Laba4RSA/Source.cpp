#include<iostream>
#include"RSA.h"
int main()
{
	setlocale(LC_ALL, "Ru");

	RSA tt("САВ", 3,11);
	tt.Coderovka();

	tt.shifr();

	tt.deShifr();

	tt.info();

	tt.info_parm();
}