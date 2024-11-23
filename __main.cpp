﻿#include "include.h"
#include "SClient.h"
#include "SService.h"
#include "SUsage.h"
#include <iostream>
#include <fstream>


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// 
// Перечисления для действий и типов файлов 
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
/*
*
*   Перечисление Action
*
*   Это перечисление определяет возможные действия, которые может выполнить
*   программа при взаимодействии с файлами. Каждое значение в перечислении
*   соответствует определенному действию, которое может выбрать пользователь.
*
*   Значения:
*   - INPUT: Действие, указывающее на ввод данных в файл. Значение: 1
*   - READ: Действие, указывающее на чтение данных из файла. Значение: 2
*   - EXIT: Действие, указывающее на выход из программы. Значение: 3
*
*/
enum Action { INPUT = 1, READ, EXIT };


/*
*
*   Перечисление FileType
*
*   Это перечисление определяет типы файлов, с которыми может работать
*   программа. Каждое значение в перечислении соответствует определенному
*   типу файла, что упрощает обработку файлов.
*   
*   Значения:
*   - CLIENT: Тип файла, представляющий данные клиента. Значение: 1
*   - SERVICE: Тип файла, представляющий данные сервиса. Значение: 2
*   - USAGE: Тип файла, представляющий данные использования. Значение: 3
*   - BACK: Специальный тип(опция), указывающий на возврат в предыдущее меню или
*     действие. Значение: 4
*
*/
enum FileType { CLIENT = 1, SERVICE, USAGE, BACK };






//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// 
// Функция для отображения меню действий с файлами
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
/*
*
*       Статичная функция для отображения меню действий с файлами
*
*       Эта функция выводит на экран меню, позволяющее пользователю выбрать
*       действие, которое он хочет выполнить с файлами. 
* 
*       Меню включает:
*       - опции для ввода данных в файл, 
*       - чтение данных из файла, 
*       - выход из программы.
*
*/
static inline void FShowMenuAction() {
    std::cout << "\n----------System----------\n"
        << "Select action:\n"
        << "1. Input to file\n"
        << "2. Reading a File\n"
        << "0. Exit to programm\n"
        << "--------------------------\n";
}




/*
*
*       Статичная функция для отображения меню структур
*
*       Эта функция выводит на экран меню, позволяющее пользователю выбрать
*       тип файла, с которым он хочет работать. 
*       I
*       Меню включает опции для выбора типа файла:
*       1. Client;
*       2. Service;
*       3. Usage;
*       4. Опция возврата в предыдущее меню.
*
*/
static inline void FShowMenuFile() {
    std::cout << "\n----------System----------\n"
        << "Select File:\n"
        << "1. Client\n"
        << "2. Service\n"
        << "3. Usage\n"
        << "0. Back\n"
        << "-------------------------\n";
}








/*
*
*       Функция для обработки операций с файлами
*
*       Функция HandleFileOperation выполняет операции ввода и чтения данных
*       из файлов в зависимости от типа файла и действия, выбранного пользователем.
*
*       Параметры:
*       - char action: действие, которое нужно выполнить (INPUT или READ).
*       - FileType fileType: тип файла, с которым будет работать функция (Client, Service, Usage).
*       - SClient& client: ссылка на объект клиента для выполнения операций с файлом клиента.
*       - SService& service: ссылка на объект сервиса для выполнения операций с файлом сервиса.
*       - SUsage& usage: ссылка на объект использования для выполнения операций с файлом использования.
*
*       Функция использует потоки для чтения и записи данных в файлы.
*
*/
void HandleFileOperation(char action, FileType fileType, SClient& client, SService& service, SUsage& usage) {
    std::ofstream WobjectClass; // Объект для записи в файл
    std::ifstream RobjectClass; // Объект для чтения из файла


    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    // 
    // Выбор действия в зависимости от типа файла
    //
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    switch (fileType) {
    case FileType::CLIENT: // Если выбран тип файла "Client"
        if (action == INPUT) { // Если действие - ввод данных
            std::cout << "Writing to Client file...\n";
            client.FWriteToFile(WobjectClass); // Запись данных клиента в файл
            std::cout << "Writing completed successfully!\n";
        }
        else { // Если действие - чтение данных
            std::cout << "Reading from Client file...\n";
            client.FReadFileSymbolically(RobjectClass); // Чтение данных клиента из файла
            std::cout << "Reading completed successfully!\n";
        }
        break;
    case FileType::SERVICE: // Если выбран тип файла "Service"
        if (action == INPUT) { // Если действие - ввод данных
            std::cout << "Writing to Service file...\n";
            service.FWriteToFile(WobjectClass); // Запись данных сервиса в файл
            std::cout << "Writing completed successfully!\n";
        }
        else { // Если действие - чтение данных
            std::cout << "Reading from Service file...\n";
            service.FReadFileSymbolically(RobjectClass); // Чтение данных сервиса из файла
            std::cout << "Reading completed successfully!\n";
        }
        break;
    case FileType::USAGE: // Если выбран тип файла "Usage"
        if (action == INPUT) { // Если действие - ввод данных
            std::cout << "Writing to Usage file...\n";
            usage.FWriteToFile(WobjectClass); // Запись данных использования в файл
            std::cout << "Writing completed successfully!\n";
        }
        else { // Если действие - чтение данных
            std::cout << "Reading from Usage file...\n";
            usage.FReadFileSymbolically(RobjectClass); // Чтение данных использования из файла
            std::cout << "Reading completed successfully!\n";
        }
        break;
    case FileType::BACK: // Если выбран тип файла "Back"
        std::cout << "Returning to the previous menu...\n";
        break;
    default: // Выдаем исключение, в случае ошибочного ввода
        std::cerr << "I$> Invalid input. You entered an invalid file type.\n"; // Сообщение об ошибке
        break;
    }
}







/*
*
*       FUNCTION MAIN
*
**          "Точка входа в программу"
*
*/
int main() {
    Action userAction = EXIT;
    FileType fileType = BACK;
    

    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    //
    // Создание объектов для работы с данными
    //
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    SClient client;
    SService service;
    SUsage usage;



    std::cout << "To start, enter any character: ";




    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    // 
    // Основной цикл программы, который будет выполняться до выхода
    // 
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
    while (true) {
        FShowMenuAction();
        int actionInput;
        std::cin >> actionInput;
        userAction = static_cast<Action>(actionInput);

        if (userAction == EXIT) break;

        if (userAction == INPUT || userAction == READ) {
            FShowMenuFile();
            int fileInput;
            std::cin >> fileInput;
            fileType = static_cast<FileType>(fileInput);

            if (fileType == BACK) continue; // Возврат в главное меню

            HandleFileOperation(userAction, fileType, client, service, usage);
        }
        else { // Обработка неверного ввода
            std::cerr << "Invalid input. Expected 1, 2, or 0.\n";
        }
    }

    return EXIT_SUCCESS;
}