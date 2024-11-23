#pragma once
#include "include.h"


/*
*
*       ��������� SUsage
*
*       ��������� SUsage ������������� ��� �������� ���������� �� ������������� �������,
*       ������� ��������� ����:
*
*       - ����� �������� ������� (strClientPhoneNumber),
*       - ���� � ����� ������������� (strUsageDateTime),
*       - ����������������� ������������� (strDuration),
*       - ���� � ����� (strPathFile),
*       - ��� ������� (uint64tServiceCode).
*
*       ��� ������������� ������ ���:
*       - ������ ������ �� �����,
*       - ������ ������ � ����,
*       - ��������� �������� ����� (�������),
*       - ��������� �������� ����� (�������).
*
*/
struct SUsage
{
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [0] ��������� ����� ���������
	// 
	// 	   * ������� ����� ���������
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
public:
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [0] ����������� ���������
	// 
	//		* ���� ������ ��������
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	SUsage
	(
		const std::string& VARIABLE_strClientPhoneNumber,
		const std::string& VARIABLE_strUsageDateTime,
		const std::string& VARIABLE_strDuration,
		const std::string& VARIABLE_strPathFile,
		const std::uint64_t& VARIABLE_uint64tServiceCode
	) : strClientPhoneNumber(VARIABLE_strClientPhoneNumber),
		strUsageDateTime(VARIABLE_strUsageDateTime),
		strDuration(VARIABLE_strDuration),
		strPathFile(VARIABLE_strPathFile),
		uint64tServiceCode(VARIABLE_uint64tServiceCode)
	{}







	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [1] ����������� ���������
	// 
	//		* ����� ���������� ���������
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	SUsage()
		: strClientPhoneNumber("Undefined"),
		strUsageDateTime("Undefined"),
		strDuration("Undefined"),
		strPathFile("Undefined.txt"),
		uint64tServiceCode(0)
	{}








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// �������
	// 
	// * � ������ ���� �� ���������� �����, �� ������ �� � ���?
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FSETSTRING_ClientPhoneNumber(const std::string& VARIABLE_strClientPhoneNumber);
	void FSETSTRING_UsageDateTime(const std::string& VARIABLE_strUsageDateTime);
	void FSETSTRING_Duration(const std::string& VARIABLE_strDuration);
	void FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile);
	void FSETUINT64T_ServiceCode(const std::uint64_t& VARIABLE_uint64tServiceCode);








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// �������
	// 
	// * � ������ ���� �� ���������� �����, �� ������ �� � ���?
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	std::string FGETSTRING_ClientPhoneNumber()		const;
	std::string FGETSTRING_UsageDateTime()			const;
	std::string FGETSTRING_Duration()				const;
	std::string FGETSTRING_PathFile()				const;
	std::uint64_t FGETUINT64T_ServiceCode()			const;








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [1] ��������� ����� ���������
	// 
	//		* ������������� ��� ������ �������
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
public:
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// ������ � ����
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FWriteToFile(std::ofstream& objectClass);









	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// ������ �� �����
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
	std::string strClientPhoneNumber;
	std::string strUsageDateTime;
	std::string strDuration;
	std::string strPathFile;
	std::uint64_t uint64tServiceCode;
};

