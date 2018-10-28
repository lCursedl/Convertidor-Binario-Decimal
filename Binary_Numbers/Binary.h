#pragma once
class CBinary
{
public:
	CBinary();
	//Constructor especifico de la clase
	CBinary(int bin, int number);
	//Asignar digito binario
	void SetBin(int i);
	//Asignar potencia del digito
	void SetNumb(int i);
	//Obtener digito binario
	int GetBin();
	//Obtener potencia del digito
	int GetNumb();
	~CBinary();
private:
	//Digito binario
	unsigned int i_digit;
	//Potencia del digito
	unsigned int i_number;
};