#ifndef LIT_REQ_HANDLER_H
#define LIT_REQ_HANDLER_H


#include <string>
#include "LitHttpConfig.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Util/ServerApplication.h"




class LIT_HTTP_API LitRequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
	LitRequestHandler(const std::string &webDir, const std::string& sContentType);
	~LitRequestHandler(void);


	virtual void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

private:
	std::string m_website_path;
	std::string m_index_path;
	std::string m_error_path;
	std::string m_sContentType;
	
};

#endif