#pragma once
#include "include.h"


/*
*
*       ��������� SService
*
*       ��������� SService ������������� ��� �������� ���������� � �������,
*       ������� ��������� ����:
*
*       - �������� ������� (strNameService),
*       - ������� ������� (strTimeUnit),
*       - ���� � ����� (strPathFile),
*       - ��� ������� (uint64tServiceCode),
*       - ����� (doubleTariff).
*
*       ��� ������������� ������ ���:
*       - ������ ������ �� �����,
*       - ������ ������ � ����,
*       - ��������� �������� ����� (�������),
*       - ��������� �������� ����� (�������).
*
*/
struct SService
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
	SService
	(
		const std::string& VARIABLE_strNameService,
		const std::string& VARIABLE_strTimeUnit,
		const std::string& VARIABLE_strPathFile,
		const std::uint64_t& VARIABLE_uint64tServiceCode,
		const double& VARIABLE_doubleTariff
	) : strNameService("Undefined"),
		strTimeUnit("Undefined"),
		strPathFile("Undefined.txt"),
		uint64tServiceCode(0),
		doubleTariff(0.0)
	{}








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [1] ����������� ���������
	// 
	//		* ����� ���������� ���������
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	SService()
		: strNameService("Undefined"),
		strTimeUnit("Undefined"),
		uint64tServiceCode(0),
		doubleTariff(0.0)
	{}







	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// �������
	// 
	// * � ������ ���� �� ���������� �����, �� ������ �� � ���?
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FSETSTRING_NameService(const std::string& VARIABLE_strNameService);
	void FSETSTRING_TimeUnit(const std::string& VARIABLE_strTimeUnit);
	void FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile);
	void FSETUINT64T_ServiceCode(const std::uint64_t& VARIABLE_uint64tServiceCode);
	void FSETDOUBLE_Tariff(double VARIABLE_doubleTariff);








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// �������
	// 
	//  * � ������ ���� �� ���������� �����, �� ������ �� � ���?
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	std::string		FGETSTRING_NameService()		const;
	std::string		FGETSTRING_TimeUnit()			const;
	std::string		FGETSTRING_PathFile()			const;
	std::uint64_t	FGETUINT64T_ServiceCode()		const;
	double			FGETDOUBLE_Tariff()				const;








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
	std::string strNameService;
	std::string strTimeUnit;
	std::string strPathFile;
	std::uint64_t uint64tServiceCode;
	double doubleTariff;
};