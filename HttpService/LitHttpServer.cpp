#include "LitHttpServer.h"



LitHttpServer::LitHttpServer(void):
    m_pFactory(NULL), m_pSvs(NULL), m_pSrv(NULL)
{
	m_sWebdir = "C:/Lit";
	m_iPort = 6000;
}

LitHttpServer::~LitHttpServer(void)
{
	stop();
}

void LitHttpServer::setPort(int iNum)
{
	m_iPort = iNum;
}

void LitHttpServer::setWebDir(std::string sPath)
{
	m_sWebdir = sPath;
}

std::string LitHttpServer::getWebDir()
{
	return m_sWebdir;
}

bool LitHttpServer::registerURI(std::string uri, std::string handler,Poco::AbstractInstantiator<HTTPRequestHandler>* pFactory)
{
    if(m_pFactory)
    {
       return m_pFactory->registerURI (uri, handler, pFactory);
    }
    return false;
}

void LitHttpServer::start(std::string sPath, int iPort)
{
	setPort(iPort);
	setWebDir(sPath);

    try
    {
        m_pSvs = new Poco::Net::ServerSocket(m_iPort);

        Poco::Net::HTTPServerParams *pParams = new Poco::Net::HTTPServerParams();
        pParams->setMaxQueued(100);
        pParams->setMaxThreads(16);
        pParams->setKeepAlive(false);
        pParams->setKeepAliveTimeout(Poco::Timespan(10,0));
        pParams->setMaxKeepAliveRequests(100);

        m_pFactory = new LitRequestHandlerFactory(m_sWebdir);

        m_pSrv = new Poco::Net::HTTPServer(m_pFactory, *m_pSvs, pParams);
        m_pSrv->start();
    }
    catch(Poco::Exception& e)
    {
        
    }
}

void LitHttpServer::stop()
{
	if(m_pSrv != NULL)
	{
		m_pSrv->stop();

		delete m_pSrv;
		m_pSrv = NULL;
	}

	if(m_pSvs != NULL)
	{
		delete m_pSvs;
		m_pSvs = NULL;
	}
}

