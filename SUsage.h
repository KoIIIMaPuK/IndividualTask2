#pragma once
#include "include.h"


/*
*
*       Структура SUsage
*
*       Структура SUsage предназначена для хранения информации об использовании сервиса,
*       включая следующие поля:
*
*       - номер телефона клиента (strClientPhoneNumber),
*       - дата и время использования (strUsageDateTime),
*       - продолжительность использования (strDuration),
*       - путь к файлу (strPathFile),
*       - код сервиса (uint64tServiceCode).
*
*       Она предоставляет методы для:
*       - чтения данных из файла,
*       - записи данных в файл,
*       - получения значений полей (геттеры),
*       - установки значений полей (сеттеры).
*
*/
struct SUsage
{
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [0] Публичная часть структуры
	// 
	// 	   * Базовая часть структуры
	// 
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
public:
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [0] Конструктор структуры
	// 
	//		* Сами задаем значения
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
	// [1] Конструктор структуры
	// 
	//		* Здесь используем дефолтные
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
	// Сеттеры
	// 
	// * В теории даже не пригодятся особо, но почему бы и нет?
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FSETSTRING_ClientPhoneNumber(const std::string& VARIABLE_strClientPhoneNumber);
	void FSETSTRING_UsageDateTime(const std::string& VARIABLE_strUsageDateTime);
	void FSETSTRING_Duration(const std::string& VARIABLE_strDuration);
	void FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile);
	void FSETUINT64T_ServiceCode(const std::uint64_t& VARIABLE_uint64tServiceCode);








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// Геттеры
	// 
	// * В теории даже не пригодятся особо, но почему бы и нет?
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	std::string FGETSTRING_ClientPhoneNumber()		const;
	std::string FGETSTRING_UsageDateTime()			const;
	std::string FGETSTRING_Duration()				const;
	std::string FGETSTRING_PathFile()				const;
	std::uint64_t FGETUINT64T_ServiceCode()			const;








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// [1] Публичная часть структуры
	// 
	//		* Предназначана для прочих функций
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
public:
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// Запись в файл
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FWriteToFile(std::ofstream& objectClass);









	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// Чтение из файла
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
	std::string strClientPhoneNumber;
	std::string strUsageDateTime;
	std::string strDuration;
	std::string strPathFile;
	std::uint64_t uint64tServiceCode;
};

