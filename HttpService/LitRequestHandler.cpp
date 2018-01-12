#include "LitRequestHandler.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "stdio.h"


LitRequestHandler::LitRequestHandler(const std::string &webDir, const std::string& sContentType)
{
	m_website_path = webDir;
	m_sContentType = sContentType;
	
	m_index_path = m_website_path + "/index.html";
	m_error_path = m_website_path + "/error.html";
}


LitRequestHandler::~LitRequestHandler(void)
{
}


void LitRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);  
	response.setContentType(m_sContentType);

	printf("\nurl: %s\n", request.getURI().c_str());
	printf("method: %s\n", request.getMethod().c_str());

	std::istream &res = request.stream();
	std::string sTemp, sGet;
	while (!res.eof())
	{
		std::getline(res, sTemp);
		//		res >> sTemp;
		sGet += sTemp;
	}
	printf("stream: %s\n", sGet.c_str());

	std::ostream &out = response.send();

	out << "Hello World!";
}

