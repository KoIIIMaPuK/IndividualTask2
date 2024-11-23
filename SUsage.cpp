#include "SUsage.h"

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// Геттеры
// 
//  * В теории даже не пригодятся особо, но почему бы и нет?
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void SUsage::FSETSTRING_ClientPhoneNumber(const std::string& VARIABLE_strClientPhoneNumber) { this->strClientPhoneNumber = VARIABLE_strClientPhoneNumber; }
void SUsage::FSETSTRING_UsageDateTime(const std::string& VARIABLE_strUsageDateTime) { this->strUsageDateTime = VARIABLE_strUsageDateTime; }
void SUsage::FSETSTRING_Duration(const std::string& VARIABLE_strDuration) { this->strDuration = VARIABLE_strDuration; }
void SUsage::FSETSTRING_PathFile(const std::string& VARIABLE_strPathFile) { this->strPathFile = VARIABLE_strPathFile; }
void SUsage::FSETUINT64T_ServiceCode(const std::uint64_t& VARIABLE_strServiceCode) { this->uint64tServiceCode = VARIABLE_strServiceCode; }







//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// Геттеры
// 
//  * В теории даже не пригодятся особо, но почему бы и нет?
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
std::string SUsage::FGETSTRING_ClientPhoneNumber()	const { return this->strClientPhoneNumber; }
std::string SUsage::FGETSTRING_UsageDateTime()		const { return this->strUsageDateTime; }
std::string SUsage::FGETSTRING_Duration()			const { return this->strDuration; }
std::string SUsage::FGETSTRING_PathFile()			const { return this->strPathFile; }
std::uint64_t SUsage::FGETUINT64T_ServiceCode()		const { return this->uint64tServiceCode; }








//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
// Запись в файл
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
void SUsage::FWriteToFile(std::ofstream& objectClass)
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
	std::cout << "~$ Enter phone number: ";								std::getline(std::cin, this->strClientPhoneNumber);		std::cout << "-------------------" << std::endl;	// Используем getline, чтобы избежать проблем с пробелами у std::cin
	std::cout << "~$ Enter data time: ";								std::getline(std::cin, this->strUsageDateTime);			std::cout << "-------------------" << std::endl;	// Используем getline, чтобы избежать проблем с пробелами у std::cin
	std::cout << "~$ Enter duration: ";									std::getline(std::cin, this->strDuration);				std::cout << "-------------------" << std::endl;	// Используем getline, чтобы избежать проблем с пробелами у std::cin
	std::cout << "~$ Enter servie code: ";								std::cin >> this->uint64tServiceCode;					std::cout << "-------------------" << std::endl;
	SetConsoleCP(866);	// Возвращаем исходную
	//
	/////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////
	//
	// Запись в файл
	//
	objectClass << this->strClientPhoneNumber << ", "
		<< this->strUsageDateTime << ", "
		<< this->strDuration << ", "
		<< this->uint64tServiceCode << '\n';
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
void SUsage::FReadFileSymbolically(std::ifstream& objectClass)
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
