#ifndef LIT_HTTPSERVER_H
#define LIT_HTTPSERVER_H


#include "LitHttpConfig.h"
#include "LitRequestHandlerFactory.h"
#include "Poco/Net/HTTPServer.h"


class LIT_HTTP_API LitHttpServer
{
public:
	LitHttpServer(void);
	~LitHttpServer(void);

public:
	void start(std::string sPath, int iPort);

	void stop();

	void setPort(int iPort);

	void setWebDir(std::string sPath);

	std::string getWebDir();

    bool registerURI(std::string uri, std::string handler,Poco::AbstractInstantiator<HTTPRequestHandler>* pFactory);

private:

	LitRequestHandlerFactory* m_pFactory;
	Poco::Net::ServerSocket *m_pSvs;
	Poco::Net::HTTPServer *m_pSrv;
	std::string m_sWebdir;
	int m_iPort; 
};


#endif
