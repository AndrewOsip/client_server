#include "InitialConditions/JSONSerialize/JsonInitialConditions.h"
#include "InitialConditions/IInitialConditions.h"
#include "InitialEntities/InitialEntities.h"
#include "Connection/TCP/TCPEntities/TCPEntities.h"

#include "json/usr/include/rapidjson/document.h"
#include "json/usr/include/rapidjson/writer.h"
#include "json/usr/include/rapidjson/stringbuffer.h"

#include <vector>
#include <string.h>

void JsonInitialConditions::toJson(InitialEntities& initialData)
{
    initialData.JSONAnswer = "{\"Mathematical_action\":\"" + initialData.mathematical_action +
            "\",\"parameter\": {\"value1\": " + std::to_string(initialData.value1) + ", \"value2\": " + std::to_string(initialData.value2) + "}}";
}

















/*create command class
внутри себя мапа метод параметр
мапа сереализируеться через рапидджейсон и формироваться строка на отправку
сереализация в отдельном классе
между кдассом команды и сереализация будет агрегация

для сервера интерфейса айконнектион
от него унаследуеться конекшн который содержит логику с тсп и юдп

и потом в тсп и юдп

создать класс клаентворкер внутри себя композировать тсп коннекшн и  агрегировать запрос пользователя
*/
