#include "SClient.h"

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// ������� ��� ��������� �������� ����� ������ SClient
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void SClient::FSETSTRING_ClientFullName(const std::string& VARIABLE_strClientFullName) { this->strClientFullName = VARIABLE_strClientFullName; }
void SClient::FSETSTRING_ClientPhoneNumber(const std::string& VARIABLE_strClientPhoneNumber) { this->strClientPhoneNumber = VARIABLE_strClientPhoneNumber; }
void SClient::FSETSTRING_DateConclusionContract(const std::string& VARIABLE_strDateConclusionContract) { this->strDateConclusionContract = VARIABLE_strDateConclusionContract; }
void SClient::FSETSTRING_DataExpirationContract(const std::string& VARIABLE_strDataExpirationContract) { this->strDataExpirationContract = VARIABLE_strDataExpirationContract; }
void SClient::FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile) { this->strPathFile = VARIABLE_strPathFile; }
void SClient::FSETDOUBLE_DebtAmount(const double& VARIABLE_doubleDebtAmount) { this->doubleDebtAmount = VARIABLE_doubleDebtAmount; }
void SClient::FSETDOUBLE_Credit�llowable(const double& VARIABLE_doubleCredit�llowable) { this->doubleCreditAllowable = VARIABLE_doubleCredit�llowable; }







//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// ������� ��� ��������� �������� ����� ������ SClient
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
std::string SClient::FGETSTRING_ClientFullName()			const { return this->strClientFullName; }
std::string SClient::FGETSTRING_ClientPhoneNumber()			const { return this->strClientPhoneNumber; }
std::string SClient::FGETSTRING_DateConclusionContract()	const { return this->strDateConclusionContract; }
std::string SClient::FGETSTRING_DataExpirationContract()	const { return this->strDataExpirationContract; }
std::string SClient::FGETSTRING_PathFile()					const { return this->strPathFile; }
double SClient::FGETDOUBLE_DebtAmount()						const { return this->doubleDebtAmount; }
double SClient::FGETDOUBLE_CreditAllowable()				const { return this->doubleCreditAllowable; }








//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// ������ � ����
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void SClient::FWriteToFile(std::ofstream& objectClass)
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
	std::cin.ignore();
	SetConsoleCP(1251);	// ������ ��������� ������� ��� ���������� ������ ��������� � ����
	std::cout << "~$ Enter full name: ";								std::getline(std::cin, this->strClientFullName);			std::cout << "\n-------------------" << std::endl; // ���������� getline, ����� �������� ������� � ��������� � std::cin
	std::cout << "~$ Enter phone number: ";								std::getline(std::cin, this->strClientPhoneNumber);			std::cout << "\n-------------------" << std::endl; // ���������� getline, ����� �������� ������� � ��������� � std::cin
	std::cout << "~$ Enter the date of conclusion of the contract: ";	std::getline(std::cin, this->strDateConclusionContract);	std::cout << "\n-------------------" << std::endl; // ���������� getline, ����� �������� ������� � ��������� � std::cin
	std::cout << "~$ Enter the end date of the contract: ";				std::getline(std::cin, this->strDataExpirationContract);	std::cout << "\n-------------------" << std::endl; // ���������� getline, ����� �������� ������� � ��������� � std::cin
	std::cout << "~$ Enter the amount of debt ";						std::cin >> this->doubleDebtAmount;							std::cin.ignore();					std::cout << "\n-------------------" << std::endl;
	std::cout << "~$ Enter acceptable credit ";							std::cin >> this->doubleCreditAllowable;					std::cin.ignore();					std::cout << "\n-------------------" << std::endl;
	SetConsoleCP(866);	// ���������� ��������
	//
	/////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////
	//
	//
	//
	objectClass << this->strClientFullName << ", "
		<< this->strClientPhoneNumber << ", "
		<< this->strDateConclusionContract << ", "
		<< this->strDataExpirationContract << ", "
		<< this->doubleDebtAmount << ", "
		<< this->doubleCreditAllowable << '\n';
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
void SClient::FReadFileSymbolically(std::ifstream& objectClass)
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