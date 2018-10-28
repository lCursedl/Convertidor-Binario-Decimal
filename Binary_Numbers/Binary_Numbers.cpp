// Binary_Numbers.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Binary.h"

int ConvertStringtoInt()
{
	//Variable para entregar el numero convertido
	unsigned int MyNum;
	//String donde se recibe el numero
	std::string MyString;
	//String stream para convertir el string a int
	std::stringstream MySStream;
	std::getline(std::cin, MyString);
	MySStream.str(MyString);
	MySStream >> MyNum;
	return MyNum;
}

void DeleteVector(std::vector<CBinary*>MyVector)
{
	for (int i = 0; i < MyVector.size(); i++)
	{
		delete MyVector[i];
	}
}

void SelectOperation(unsigned int &numb)
{
	std::cout << "Escoja una operacion:\n1.-Convertir de binario a decimal.\n2.-Convertir de decimal a binario.\n\n";
	numb = ConvertStringtoInt();
	if (numb < 1 || numb > 2)
	{
		std::cout << "\nOpcion no valida, porfavor introduzca una opcion valida\n\n";
		SelectOperation(numb);
	}	
}

void DecConvertion()
{
	//String para guardar el numero binario
	std::string BinString;
	//Vector de punteros a CBinary
	std::vector<CBinary*>MyBin;
	//Potencia del digito
	int Pow = 1;
	//Numero resultado de la conversion
	int Result = 0;

	std::cout << "Introduzca el numero binario a convertir: ";
	std::getline(std::cin, BinString);
	//Tamaño del string donde se encuentra el numero binario
	int StringSize = BinString.size();
	//Ciclo para colocar los 0s y 1s en el vector de objetos CBinary
	for (int i = 0; i < StringSize; ++i)
	{
		MyBin.push_back(new CBinary(BinString[i] - '0', 0));
	}
	//Ciclo para asignar la potencia correspondiente de cada digito
	for (int i = MyBin.size() - 1; i > -1; i--)
	{
		MyBin[i]->SetNumb(Pow);
		Pow *= 2;
	}
	//Ciclo para obtener el numero resultante
	for (int i = 0; i < MyBin.size(); i++)
	{
		if (MyBin[i]->GetBin() == 1)
		{
			Result += MyBin[i]->GetNumb();
		}
	}
	std::cout << "\nEl numero es " << Result << ".\n";
	DeleteVector(MyBin);
}

void BinConvertion()
{
	//Variable entera para almacenar el numero de entrada
	unsigned int DecNumb;
	//Variable para almacenar el sobrante
	unsigned int bit;
	//Vector de punteros a CBinary
	std::vector<CBinary*>MyBin;

	std::cout << "Introduzca el numero decimal a convertir: ";
	DecNumb = ConvertStringtoInt();
	//Mientras el cosciente de la division / 2 no sea igual a 0 (incluyendo el ultimo digito)
	while ((DecNumb) != 0)
	{
		//Se obtiene el residuo
		bit = DecNumb % 2;
		//Se divide el numero original / 2
		DecNumb /= 2;
		//Se almacena el objeto tipo CBinary en un vector
		MyBin.push_back(new CBinary(bit, 0));
	}
	std::cout << "El numero es: ";
	for (int i = MyBin.size() - 1; i > -1; i--)
	{
		std::cout << MyBin[i]->GetBin();
	}
	DeleteVector(MyBin);
	std::cout << "\n";
}

int main()
{
	bool RunProgram = true;
	std::string CicleString;
	std::stringstream CicleStream;
	unsigned int Selection;
	while (RunProgram)
	{		
		SelectOperation(Selection);
		if (Selection == 1)
		{
			std::cout << "\nConversion decimal \n\n";
			DecConvertion();
		}
		else if (Selection == 2)
		{
			std::cout << "\nConversion binaria \n\n";
			BinConvertion();
		}
		std::cout << "\nDesea realizar otra operacion? Si: 1 / No: 0\n\n";
		RunProgram = ConvertStringtoInt();
		std::cout << "\n";
	}	
    return 0;
}