#pragma once
#include "include.h"


/*
*
*       Структура SService
*
*       Структура SService предназначена для хранения информации о сервисе,
*       включая следующие поля:
*
*       - название сервиса (strNameService),
*       - единицу времени (strTimeUnit),
*       - путь к файлу (strPathFile),
*       - код сервиса (uint64tServiceCode),
*       - тариф (doubleTariff).
*
*       Она предоставляет методы для:
*       - чтения данных из файла,
*       - записи данных в файл,
*       - получения значений полей (геттеры),
*       - установки значений полей (сеттеры).
*
*/
struct SService
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
	// [1] Конструктор структуры
	// 
	//		* Здесь используем дефолтные
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
	// Сеттеры
	// 
	// * В теории даже не пригодятся особо, но почему бы и нет?
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	void FSETSTRING_NameService(const std::string& VARIABLE_strNameService);
	void FSETSTRING_TimeUnit(const std::string& VARIABLE_strTimeUnit);
	void FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile);
	void FSETUINT64T_ServiceCode(const std::uint64_t& VARIABLE_uint64tServiceCode);
	void FSETDOUBLE_Tariff(double VARIABLE_doubleTariff);








	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	//
	// Геттеры
	// 
	//  * В теории даже не пригодятся особо, но почему бы и нет?
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
	std::string		FGETSTRING_NameService()		const;
	std::string		FGETSTRING_TimeUnit()			const;
	std::string		FGETSTRING_PathFile()			const;
	std::uint64_t	FGETUINT64T_ServiceCode()		const;
	double			FGETDOUBLE_Tariff()				const;








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
	std::string strNameService;
	std::string strTimeUnit;
	std::string strPathFile;
	std::uint64_t uint64tServiceCode;
	double doubleTariff;
};