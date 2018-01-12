#pragma once

#include "LitHttpConfig.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"


class LIT_HTTP_API LitHttpClient
{
public:
	LitHttpClient(void);
	LitHttpClient(const std::string &sIp, int iPort, int iTimeOut);
	~LitHttpClient(void);

public:
	void SetHost(const std::string& sHost);

	void SetPort(int iPort);

	void SetTimeOut(int iTimeOut);

	int RequestPost(const std::string &sContentType, const std::string &sSend, std::string &sGet);


private:
	Poco::Net::HTTPClientSession m_session;
	Poco::Net::HTTPRequest m_request;
	Poco::Net::HTTPResponse m_response;
};

