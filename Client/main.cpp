#include <iostream>

#include "json/usr/include/rapidjson/document.h"
#include "json/usr/include/rapidjson/writer.h"
#include "json/usr/include/rapidjson/stringbuffer.h"

#include "InitialConditions.h"

int main()
{
    std::string funcName = "summ";
    int firstParam = 4;
    int secondParam = 2;
/*  std::cout << "Enter Math_action: " << std::endl;
    std::cin >> funcName;
    std::cout << "Enter first param: " << std::endl;
    std::cin >> firstParam;
    std::cout << "Enter second param: " << std::endl;
    std::cin >> secondParam;
*/

    InitialConditions iC(funcName, firstParam, secondParam);
    iC.toJson(); // <--Данные на отправку



    return 0;
}
