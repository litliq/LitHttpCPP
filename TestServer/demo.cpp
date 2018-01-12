#include "../HttpService/LitHttpServer.h"
#include <Poco/Util/ServerApplication.h>
#include <iostream>


int main()
{
	LitHttpServer server;
	std::cout << "http server start\n";
	server.start("server", "text/html", 5000);	

#ifdef WIN32
	system("pause");
#endif // WIN32

	std::cout << "http server stop\n";
	server.stop();

	return 0;
}


