#pragma once

#include "LitRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/DynamicFactory.h"


using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPRequestHandler;

class LitRequestHandlerFactory : public HTTPRequestHandlerFactory
{
public:  
	typedef Poco::AbstractInstantiator<HTTPRequestHandler> HttpReqFactory;

	LitRequestHandlerFactory(const std::string &webDir, const std::string& sContentType);
	~LitRequestHandlerFactory(void);

	virtual HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request);

    bool registerURI(std::string uri, std::string handlerClassName, HttpReqFactory* pFactory);

    HTTPRequestHandler* createRequestHandler (const std::string& className) const;

private:

	std::string m_sWebdir;
	std::string m_sContentType;
    std::map<std::string, std::string> m_uriRoute;
    Poco::DynamicFactory<HTTPRequestHandler> m_httpReqFactory;
};

