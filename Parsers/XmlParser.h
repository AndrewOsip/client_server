#include <string>

#include "Parsers/IDataParser.h"

class XmlParser : public IDataParser
{
public:
    bool provideClientRequest(ClientRequest& resultData, const std::string& inputData) override;
};



