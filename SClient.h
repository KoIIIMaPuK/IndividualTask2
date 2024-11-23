#pragma once
#include "include.h"


/*
*
*       ��������� SClient
*
*       ��������� SClient ������������� ��� �������� ���������� � �������,
*       ������� ��������� ����:
*
*       - ������ ��� ������� (strClientFullName),
*       - ����� �������� ������� (strClientPhoneNumber),
*       - ���� ���������� �������� (strDateConclusionContract),
*       - ���� ��������� �������� (strDataExpirationContract),
*       - ���� � ����� (strPathFile),
*       - ������ ������������� (doubleDebtAmount),
*       - ���������� ������ (doubleCreditAllowable).
*
*       ��� ������������� ������ ���:
*       - ������ ������ �� �����,
*       - ������ ������ � ����,
*       - ��������� �������� ����� (�������),
*       - ��������� �������� ����� (�������).
*
*/
struct SClient
{
public:
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [0] ����������� ������
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	SClient
	(
		const std::string& VARIABLE_strClientFullName,					// ������ �� ���������� <��� �������>
		const std::string& VARIABLE_strClientPhoneNumber,				// ������ �� ���������� <����� �������� �������>
		const std::string& VARIABLE_strDateConclusionContract,			// ������ �� ���������� <���� ���������� ��������>
		const std::string& VARIABLE_strDataExpirationContract,			// ������ �� ���������� <���� ��������� ��������>
		const std::string& VARIABLE_strPathFile,						// ������ �� ���������� <���� � �����>
		const double& VARIABLE_doubleDebtAmount,						// ������ �� ���������� <������ �����������>
		const double& VARIABLE_doubleCredit�llowable					// ������ �� ���������� <���������� ������>
	) : strClientFullName(VARIABLE_strClientFullName),
		strClientPhoneNumber(VARIABLE_strClientPhoneNumber),
		strDateConclusionContract(VARIABLE_strDateConclusionContract),
		strDataExpirationContract(VARIABLE_strDataExpirationContract),
		strPathFile(VARIABLE_strPathFile),
		doubleDebtAmount(VARIABLE_doubleDebtAmount),
		doubleCreditAllowable(VARIABLE_doubleCredit�llowable)
	{}








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [1] ����������� ������
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	SClient()
		: strClientFullName("Undefined"),
		strClientPhoneNumber("Undefined"),
		strDateConclusionContract("Undefined"),
		strDataExpirationContract("Undefined"),
		strPathFile("Undefined.txt"),
		doubleDebtAmount(0.0),
		doubleCreditAllowable(0.0)
	{}







	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// �������
	// 
	// * � ������ ���� �� ���������� �����, �� ������ �� � ���?
	// 
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FSETSTRING_ClientFullName(const std::string& VARIABLE_strClientFullName);
	void FSETSTRING_ClientPhoneNumber(const std::string& VARIABLE_strClientPhoneNumber);
	void FSETSTRING_DateConclusionContract(const std::string& VARIABLE_strDateConclusionContract);
	void FSETSTRING_DataExpirationContract(const std::string& VARIABLE_strDataExpirationContract);
	void FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile);
	void FSETDOUBLE_DebtAmount(const double& VARIABLE_doubleDebtAmount);
	void FSETDOUBLE_Credit�llowable(const double& VARIABLE_doubleCredit�llowable);







	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// �������
	// 
	//  * � ������ ���� �� ���������� �����, �� ������ �� � ���?
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	std::string FGETSTRING_ClientFullName()				const;
	std::string FGETSTRING_ClientPhoneNumber()			const;
	std::string FGETSTRING_DateConclusionContract()		const;
	std::string FGETSTRING_DataExpirationContract()		const;
	std::string FGETSTRING_PathFile()					const;
	double FGETDOUBLE_DebtAmount()						const;
	double FGETDOUBLE_CreditAllowable()					const;








public:
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// ������ � ����.
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FWriteToFile(std::ofstream& objectClass);









	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// ������ �� �����.
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FReadFileSymbolically(std::ifstream& objectClass);










	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [0] ������������ ����� ���������
	// 
	// 	   Protected... �������� ���-������ ������������
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
protected:
	std::string		strClientFullName;					// ��� �������
	std::string		strClientPhoneNumber;				// ����� �������� �������
	std::string		strDateConclusionContract;			// ���� ���������� ��������
	std::string		strDataExpirationContract;			// ���� ��������� ��������
	std::string		strPathFile;						// ���� � �����
	double			doubleDebtAmount;					// ������ �����������
	double			doubleCreditAllowable;				// ���������� ������
};