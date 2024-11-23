#include "SService.h"

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// �������
// 
// * � ������ ���� �� ���������� �����, �� ������ �� � ���?
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void SService::FSETSTRING_NameService(const std::string& VARIABLE_strNameService)			{ this->strNameService = VARIABLE_strNameService; }
void SService::FSETSTRING_TimeUnit(const std::string& VARIABLE_strTimeUnit)					{ this->strTimeUnit = VARIABLE_strTimeUnit; }
void SService::FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile)					{ this->strPathFile = VARIABLE_strPathFile; }
void SService::FSETUINT64T_ServiceCode(const std::uint64_t& VARIABLE_uint64tServiceCode)	{ this->uint64tServiceCode = VARIABLE_uint64tServiceCode; }
void SService::FSETDOUBLE_Tariff(double VARIABLE_doubleTariff)								{ this->doubleTariff = VARIABLE_doubleTariff; }







//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// �������
// 
//  * � ������ ���� �� ���������� �����, �� ������ �� � ���?
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
std::string SService::FGETSTRING_NameService()		const { return this->strNameService;		}
std::string SService::FGETSTRING_TimeUnit()			const { return this->strTimeUnit;			}
std::string SService::FGETSTRING_PathFile()			const { return this->strPathFile;			}
std::uint64_t SService::FGETUINT64T_ServiceCode()	const { return this->uint64tServiceCode;	}
double SService::FGETDOUBLE_Tariff()				const { return this->doubleTariff;			}








//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// ������ � ����
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void SService::FWriteToFile(std::ofstream& objectClass)
{
	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// ��������� ���� � ��������� ��������� ������.
	// � ������ ������� ������ ����������.
	// 
	// ���������� [0]: �������� �� <try catch>
	//
	objectClass.open(this->strPathFile, std::ofstream::app);
	if (!objectClass.is_open()) // ���������
	{
		throw std::runtime_error("Failed to open file: " + this->strPathFile);
	}
	//
	/////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// ���������� ������������� ����������
	// 
	SetConsoleCP(1251);	// ������ ��������� ������� ��� ���������� ������ ��������� � ����
	std::cout << "~$ Enter full name: ";								std::getline(std::cin, this->strNameService);		std::cout << "-------------------" << std::endl; // ���������� getline, ����� �������� ������� � ��������� � std::cin
	std::cout << "~$ Enter phone number: ";								std::getline(std::cin, this->strTimeUnit);			std::cout << "-------------------" << std::endl; // ���������� getline, ����� �������� ������� � ��������� � std::cin
	std::cout << "~$ Enter the amount of debt ";						std::cin >> this->uint64tServiceCode;				std::cout << "-------------------" << std::endl;
	std::cout << "~$ Enter acceptable credit ";							std::cin >> this->doubleTariff;						std::cout << "-------------------" << std::endl;
	SetConsoleCP(866);	// ���������� ��������
	//
	/////////////////////////////////////////////////////////////////////////////////////////





	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// ������ � ����
	//
	objectClass << this->strNameService << ", "
		<< this->strTimeUnit << ", "
		<< this->uint64tServiceCode << ", "
		<< this->doubleTariff << '\n';
	//
	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// �������� �� ������ ������
	// 
	// ���������� [0]: �������� �� <try catch>
	//
	if (objectClass.fail())
	{
		throw std::runtime_error("Failed to write to file: " + strPathFile);
	}
	//
	/////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// �������� �����
	// ���� ����� �������� �� ���
	//
	objectClass.close();
	//
	/////////////////////////////////////////////////////////////////////////////////////////
}







//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// ������ �� �����
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void SService::FReadFileSymbolically(std::ifstream& objectClass)
{
	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// �������� � ��������� ����� ��� ������
	//
	objectClass.open(this->strPathFile);
	if (!objectClass.is_open()) // ���������
	{
		throw std::runtime_error("Failed to open file: " + this->strPathFile);
	}
	//
	/////////////////////////////////////////////////////////////////////////////////////////






	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// ������ �������� ����
	//
	std::cout << std::endl << "----------File-contents----------" << std::endl;	// ��� ��������� ����������� � �������
	char charGetSymbolFromFile;													// ����������, ��� ������������ ������ �� �����
	while (objectClass.get(charGetSymbolFromFile))								// �������� �������
	{
		std::cout << charGetSymbolFromFile;										// ������� �� �����
	}
	std::cout << std::endl << "---------------------------------" << std::endl;	// ��� ��������� ����������� � �������
	//
	/////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// �������� �����
	// ���� ����� �������� �� ���
	//
	objectClass.close();
	//
	/////////////////////////////////////////////////////////////////////////////////////////
}
