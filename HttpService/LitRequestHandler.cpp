#include "LitRequestHandler.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"


LitRequestHandler::LitRequestHandler(const std::string &webDir)
{
	m_website_path = webDir;
	
	m_index_path = m_website_path + "/index.html";
	m_error_path = m_website_path + "/error.html";
}


LitRequestHandler::~LitRequestHandler(void)
{
}


void LitRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);  
	response.setContentType("text/html");

	std::ostream &out = response.send();

	out << "<h1>Hello World!</h1>";  
}

