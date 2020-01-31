#include <algorithm>
#include <iostream>

#include "Serializor/XMLSerializor.h"
#include "Executor/FunctionExecutor.h"

#include "pugi/src/pugixml.hpp"

std::string XMLSerializer::serializeData(ClientRequest &resultData)
{
    this->operationName = resultData.functionName;
    this->operationResult = resultData.resultOperation;
    std::string oRes = std::to_string(operationResult);

    pugi::xml_document answerDocument;

    pugi::xml_node node = answerDocument.append_child("xml");

    pugi::xml_node funcName = node.append_child("Mathematical_action");
    funcName.append_child(pugi::node_pcdata).set_value(operationName.c_str());
    pugi::xml_node answer = node.append_child("answer");
    answer.append_child(pugi::node_pcdata).set_value(oRes.c_str());

    std::cout << "Serialized:" << std::endl;
    answerDocument.save(std::cout);

    return operationName;
}
