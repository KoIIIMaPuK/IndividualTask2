#pragma once
#include "include.h"


/*
*
*       Структура SClient
*
*       Структура SClient предназначена для хранения информации о клиенте,
*       включая следующие поля:
*
*       - полное имя клиента (strClientFullName),
*       - номер телефона клиента (strClientPhoneNumber),
*       - дата заключения договора (strDateConclusionContract),
*       - дата окончания договора (strDataExpirationContract),
*       - путь к файлу (strPathFile),
*       - размер задолженности (doubleDebtAmount),
*       - допустимый кредит (doubleCreditAllowable).
*
*       Она предоставляет методы для:
*       - чтения данных из файла,
*       - записи данных в файл,
*       - получения значений полей (геттеры),
*       - установки значений полей (сеттеры).
*
*/
struct SClient
{
public:
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [0] Конструктор класса
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	SClient
	(
		const std::string& VARIABLE_strClientFullName,					// Ссылка на переменную <ФИО клиента>
		const std::string& VARIABLE_strClientPhoneNumber,				// Ссылка на переменную <Номер телефона клиента>
		const std::string& VARIABLE_strDateConclusionContract,			// Ссылка на переменную <Дату заключения договора>
		const std::string& VARIABLE_strDataExpirationContract,			// Ссылка на переменную <Дату окончания договора>
		const std::string& VARIABLE_strPathFile,						// Ссылка на переменную <Путь к файлу>
		const double& VARIABLE_doubleDebtAmount,						// Ссылка на переменную <Размер задолжности>
		const double& VARIABLE_doubleCreditАllowable					// Ссылка на переменную <Допустимый кредит>
	) : strClientFullName(VARIABLE_strClientFullName),
		strClientPhoneNumber(VARIABLE_strClientPhoneNumber),
		strDateConclusionContract(VARIABLE_strDateConclusionContract),
		strDataExpirationContract(VARIABLE_strDataExpirationContract),
		strPathFile(VARIABLE_strPathFile),
		doubleDebtAmount(VARIABLE_doubleDebtAmount),
		doubleCreditAllowable(VARIABLE_doubleCreditАllowable)
	{}








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [1] Конструктор класса
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
	// Сеттеры
	// 
	// * В теории даже не пригодятся особо, но почему бы и нет?
	// 
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FSETSTRING_ClientFullName(const std::string& VARIABLE_strClientFullName);
	void FSETSTRING_ClientPhoneNumber(const std::string& VARIABLE_strClientPhoneNumber);
	void FSETSTRING_DateConclusionContract(const std::string& VARIABLE_strDateConclusionContract);
	void FSETSTRING_DataExpirationContract(const std::string& VARIABLE_strDataExpirationContract);
	void FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile);
	void FSETDOUBLE_DebtAmount(const double& VARIABLE_doubleDebtAmount);
	void FSETDOUBLE_CreditАllowable(const double& VARIABLE_doubleCreditАllowable);







	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// Геттеры
	// 
	//  * В теории даже не пригодятся особо, но почему бы и нет?
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
	// Запись в файл.
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FWriteToFile(std::ofstream& objectClass);









	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// Чтение из файла.
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FReadFileSymbolically(std::ifstream& objectClass);










	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [0] Насследуемая часть структуры
	// 
	// 	   Protected... Возможно как-нибудь воспользуюсь
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
protected:
	std::string		strClientFullName;					// ФИО клиента
	std::string		strClientPhoneNumber;				// Номер телефона клиента
	std::string		strDateConclusionContract;			// Дата заключения договора
	std::string		strDataExpirationContract;			// Дата окончание договора
	std::string		strPathFile;						// Путь к файлу
	double			doubleDebtAmount;					// Размер задолжности
	double			doubleCreditAllowable;				// Допустимый кредит
};