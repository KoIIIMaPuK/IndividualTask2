#include "SUsage.h"

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// �������
// 
//  * � ������ ���� �� ���������� �����, �� ������ �� � ���?
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void SUsage::FSETSTRING_ClientPhoneNumber(const std::string& VARIABLE_strClientPhoneNumber) { this->strClientPhoneNumber = VARIABLE_strClientPhoneNumber; }
void SUsage::FSETSTRING_UsageDateTime(const std::string& VARIABLE_strUsageDateTime) { this->strUsageDateTime = VARIABLE_strUsageDateTime; }
void SUsage::FSETSTRING_Duration(const std::string& VARIABLE_strDuration) { this->strDuration = VARIABLE_strDuration; }
void SUsage::FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile) { this->strPathFile = VARIABLE_strPathFile; }
void SUsage::FSETUINT64T_ServiceCode(const std::uint64_t& VARIABLE_strServiceCode) { this->uint64tServiceCode = VARIABLE_strServiceCode; }







//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// �������
// 
//  * � ������ ���� �� ���������� �����, �� ������ �� � ���?
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
std::string SUsage::FGETSTRING_ClientPhoneNumber()	const { return this->strClientPhoneNumber; }
std::string SUsage::FGETSTRING_UsageDateTime()		const { return this->strUsageDateTime; }
std::string SUsage::FGETSTRING_Duration()			const { return this->strDuration; }
std::string SUsage::FGETSTRING_PathFile()			const { return this->strPathFile; }
std::uint64_t SUsage::FGETUINT64T_ServiceCode()		const { return this->uint64tServiceCode; }








//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// ������ � ����
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void SUsage::FWriteToFile(std::ofstream& objectClass)
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
	std::cout << "~$ Enter phone number: ";								std::getline(std::cin, this->strClientPhoneNumber);		std::cout << "-------------------" << std::endl;	// ���������� getline, ����� �������� ������� � ��������� � std::cin
	std::cout << "~$ Enter data time: ";								std::getline(std::cin, this->strUsageDateTime);			std::cout << "-------------------" << std::endl;	// ���������� getline, ����� �������� ������� � ��������� � std::cin
	std::cout << "~$ Enter duration: ";									std::getline(std::cin, this->strDuration);				std::cout << "-------------------" << std::endl;	// ���������� getline, ����� �������� ������� � ��������� � std::cin
	std::cout << "~$ Enter servie code: ";								std::cin >> this->uint64tServiceCode;					std::cout << "-------------------" << std::endl;
	SetConsoleCP(866);	// ���������� ��������
	//
	/////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// ������ � ����
	//
	objectClass << this->strClientPhoneNumber << ", "
		<< this->strUsageDateTime << ", "
		<< this->strDuration << ", "
		<< this->uint64tServiceCode << '\n';
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
void SUsage::FReadFileSymbolically(std::ifstream& objectClass)
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
