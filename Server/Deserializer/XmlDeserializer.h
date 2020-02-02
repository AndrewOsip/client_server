#include <string>

#include "Deserializer/IDeserializer.h"

class XmlDeserializer : public IDeserializer
{
public:
    bool provideClientRequest(ClientRequest& resultData, const std::string& inputData) override;
};



