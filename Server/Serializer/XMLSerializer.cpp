#include <algorithm>
#include <iostream>
#include <sstream>

#include "Serializer/XMLSerializer.h"
#include "Executor/FunctionExecutor.h"

#include "pugi/src/pugixml.hpp"

bool XMLSerializer::serializeData(ClientRequest &resultData, ServerResult& result)
{
    result.operationName = resultData.functionName;
    std::string oRes = std::to_string(result.operationResult);

    pugi::xml_document answerDocument;

    pugi::xml_node node = answerDocument.append_child("xml");

    pugi::xml_node funcName = node.append_child("Mathematical_action");
    funcName.append_child(pugi::node_pcdata).set_value(result.operationName.c_str());
    pugi::xml_node answer = node.append_child("answer");
    answer.append_child(pugi::node_pcdata).set_value(oRes.c_str());

    std::cout << "Serialized:" << std::endl;
    answerDocument.save(std::cout);

    std::stringstream buffer;
            answerDocument.save(buffer);
            result.answer =  buffer.str();

    std::cout << result.answer << std::endl;

    return true;

}
