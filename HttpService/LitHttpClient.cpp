#include "LitHttpClient.h"


LitHttpClient::LitHttpClient(void)
{
}

LitHttpClient::LitHttpClient(const std::string &sIp, int iPort, int iTimeOut)
{
	SetHost(sIp);
	SetPort(iPort);
	SetTimeOut(iTimeOut);
}

LitHttpClient::~LitHttpClient(void)
{
}

void LitHttpClient::SetHost(const std::string& sHost)
{
	m_session.setHost(sHost);
}

void LitHttpClient::SetPort(int iPort)
{
	m_session.setPort(iPort);
}

void LitHttpClient::SetTimeOut(int iTimeOut)
{
	m_session.setTimeout(iTimeOut);
}

int LitHttpClient::RequestPost(const std::string &sContentType, const std::string &sSend, std::string &sGet)
{
	try
	{
		m_request.setMethod(Poco::Net::HTTPRequest::HTTP_POST);
		m_request.setContentType(sContentType);
		m_request.setContentLength(sSend.size());

		std::ostream& send = m_session.sendRequest(m_request);
		send << sSend;

		
		std::istream& res = m_session.receiveResponse(m_response);
		std::string sTemp;
		while (!res.eof())
		{
			std::getline(res, sTemp);
	//		res >> sTemp;
			sGet += sTemp;
		}
	}
	catch (...)
	{
		return -1;
	}
	
	return 0;
}