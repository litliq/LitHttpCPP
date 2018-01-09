#include "LitRequestHandlerFactory.h"
#include "LitRequestHandler.h"


LitRequestHandlerFactory::LitRequestHandlerFactory(std::string &webDir)
{
	m_sWebdir = webDir;
}

LitRequestHandlerFactory::~LitRequestHandlerFactory(void)
{
}

HTTPRequestHandler* LitRequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest& request)
{
	std::string URL = request.getURI();
	if(URL[0] != '/')
	{
		return NULL;
	}

	//删除多余的'/'
	while(URL.length() > 1)
	{

		if(URL[0] == '/' && URL[1]=='/')
		{
			URL.erase(0,1);
			continue;
		}
		break;
	}

    if(m_uriRoute.find (URL) != m_uriRoute.end ())
    {
        std::string className = m_uriRoute[URL];
        return m_httpReqFactory.createInstance (className);
    }

    return new LitRequestHandler(m_sWebdir);
}

HTTPRequestHandler* LitRequestHandlerFactory::createRequestHandler (const std::string& className) const
{
	return m_httpReqFactory.createInstance (className);
}

bool LitRequestHandlerFactory::registerURI(std::string uri, std::string handlerClassName,HttpReqFactory* pFactory)
{
    m_uriRoute[uri] = handlerClassName;
    m_httpReqFactory.registerClass(handlerClassName, pFactory);
    return true;
}
