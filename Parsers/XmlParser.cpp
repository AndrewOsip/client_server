#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "Parsers/JSONParser.h"
#include "Parsers/XmlParser.h"

#include "pugi/src/pugixml.hpp"

bool XmlParser::provideClientRequest(ClientRequest &resultData, const std::string &inputData)
{
    pugi::xml_document currentDocument;
    pugi::xml_parse_result result = currentDocument.load_buffer(inputData.c_str(),
                                                                pugi::parse_default|pugi::parse_declaration);
    if (!result) {
        std::cout << "Parse error: " << result.description() << ", character pos= " << result.offset;
    }
    currentDocument.document_element();

    resultData.functionName = currentDocument.child("xml").child("funcName").text().as_string();
    pugi::xml_node params = currentDocument.child("xml").child("params");

    if (currentDocument.child("xml").child("params").child("value1") == nullptr ||
        currentDocument.child("xml").child("params").child("value2") == nullptr) {
        std::cout << "You miss operand" << std::endl;
        return false;
    }

    for (pugi::xml_node child: params.children()) {
        resultData.mapParams[child.name()] = child.text().as_int();
    }

    return true;
}






