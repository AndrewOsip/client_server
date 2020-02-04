#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "Serializer/XML/XMLSerializer.h"

bool XMLSerializer::provideClientRequest(ClientRequest &resultData, const std::string &inputData)
{
    pugi::xml_document currentDocument;
    pugi::xml_parse_result result = currentDocument.load_buffer(inputData.c_str(),
                                                                pugi::parse_default|pugi::parse_declaration);
    if (!result) {
        std::cout << "Parse error: " << result.description() << ", character pos= " << result.offset;
    }
    currentDocument.document_element();

    resultData.functionName = currentDocument.child("xml").child("funcName").text().as_string();
    pugi::xml_node params = currentDocument.child("xml").child("parameter");

    if (currentDocument.child("xml").child("parameter").child("value1") == nullptr ||
        currentDocument.child("xml").child("parameter").child("value2") == nullptr) {
        std::cout << "You miss operand" << std::endl;
        return false;
    }

    for (pugi::xml_node child: params.children()) {
        resultData.mapParams[child.name()] = child.text().as_int();
    }

    return true;
}






