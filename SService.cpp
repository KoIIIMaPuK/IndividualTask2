#include "SService.h"

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// Сеттеры
// 
// * В теории даже не пригодятся особо, но почему бы и нет?
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void SService::FSETSTRING_NameService(const std::string& VARIABLE_strNameService)			{ this->strNameService = VARIABLE_strNameService; }
void SService::FSETSTRING_TimeUnit(const std::string& VARIABLE_strTimeUnit)					{ this->strTimeUnit = VARIABLE_strTimeUnit; }
void SService::FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile)					{ this->strPathFile = VARIABLE_strPathFile; }
void SService::FSETUINT64T_ServiceCode(const std::uint64_t& VARIABLE_uint64tServiceCode)	{ this->uint64tServiceCode = VARIABLE_uint64tServiceCode; }
void SService::FSETDOUBLE_Tariff(double VARIABLE_doubleTariff)								{ this->doubleTariff = VARIABLE_doubleTariff; }







//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// Геттеры
// 
//  * В теории даже не пригодятся особо, но почему бы и нет?
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
std::string SService::FGETSTRING_NameService()		const { return this->strNameService;		}
std::string SService::FGETSTRING_TimeUnit()			const { return this->strTimeUnit;			}
std::string SService::FGETSTRING_PathFile()			const { return this->strPathFile;			}
std::uint64_t SService::FGETUINT64T_ServiceCode()	const { return this->uint64tServiceCode;	}
double SService::FGETDOUBLE_Tariff()				const { return this->doubleTariff;			}








//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// Запись в файл
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void SService::FWriteToFile(std::ofstream& objectClass)
{
	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Открываем файл и проверяем возможные ошибки.
	// В случае неудачи бросем исключение.
	// 
	// Примечание [0]: Поменять на <try catch>
	//
	objectClass.open(this->strPathFile, std::ofstream::app);
	if (!objectClass.is_open()) // Проверяем
	{
		throw std::runtime_error("Failed to open file: " + this->strPathFile);
	}
	//
	/////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Производим инициализацию переменных
	// 
	SetConsoleCP(1251);	// Меняем кодировку консоли для правильной записи кириллици в файл
	std::cout << "~$ Enter full name: ";								std::getline(std::cin, this->strNameService);		std::cout << "-------------------" << std::endl; // Используем getline, чтобы избежать проблем с пробелами у std::cin
	std::cout << "~$ Enter phone number: ";								std::getline(std::cin, this->strTimeUnit);			std::cout << "-------------------" << std::endl; // Используем getline, чтобы избежать проблем с пробелами у std::cin
	std::cout << "~$ Enter the amount of debt ";						std::cin >> this->uint64tServiceCode;				std::cout << "-------------------" << std::endl;
	std::cout << "~$ Enter acceptable credit ";							std::cin >> this->doubleTariff;						std::cout << "-------------------" << std::endl;
	SetConsoleCP(866);	// Возвращаем исходную
	//
	/////////////////////////////////////////////////////////////////////////////////////////





	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Запись в файл
	//
	objectClass << this->strNameService << ", "
		<< this->strTimeUnit << ", "
		<< this->uint64tServiceCode << ", "
		<< this->doubleTariff << '\n';
	//
	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Проверка на ошибки записи
	// 
	// Примечание [0]: Поменять на <try catch>
	//
	if (objectClass.fail())
	{
		throw std::runtime_error("Failed to write to file: " + strPathFile);
	}
	//
	/////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Закрытие файла
	// Хрен знает работает ли так
	//
	objectClass.close();
	//
	/////////////////////////////////////////////////////////////////////////////////////////
}







//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// Чтение из файла
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void SService::FReadFileSymbolically(std::ifstream& objectClass)
{
	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Открытие с проверкой файла для чтения
	//
	objectClass.open(this->strPathFile);
	if (!objectClass.is_open()) // Проверяем
	{
		throw std::runtime_error("Failed to open file: " + this->strPathFile);
	}
	//
	/////////////////////////////////////////////////////////////////////////////////////////






	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Читаем открытый файл
	//
	std::cout << std::endl << "----------File-contents----------" << std::endl;	// Для красивого отображения в консоли
	char charGetSymbolFromFile;													// Переменная, для посимвольной записи из файла
	while (objectClass.get(charGetSymbolFromFile))								// Получаем символы
	{
		std::cout << charGetSymbolFromFile;										// Выводим на экран
	}
	std::cout << std::endl << "---------------------------------" << std::endl;	// Для красивого отображения в консоли
	//
	/////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Закрытие файла
	// Хрен знает работает ли так
	//
	objectClass.close();
	//
	/////////////////////////////////////////////////////////////////////////////////////////
}
