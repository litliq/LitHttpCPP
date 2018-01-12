#include "../HttpService/LitHttpClient.h"
#include <Poco/Util/ServerApplication.h>
#include <iostream>


int main()
{
	LitHttpClient client("127.0.0.1", 5000, 6000);
	std::cout << "http client start\n\n";
	int iNum = 100;
	for (int i = 0; i < iNum; i++)
	{
		std::cout << "index: " << i + 1 << std::endl;
		std::string sGet;
		int iRet = client.RequestPost("text/html", "lit liq", sGet);
		if (0 == iRet)
		{
			std::cout << sGet.c_str() << std::endl;
		}
		else
		{
			std::cout << "Error: " << iRet << std::endl;
		}

		std::cout << std::endl;

		Sleep(3000);
	}
	
	
#ifdef WIN32
	system("pause");
#endif // WIN32

	std::cout << "http client stop\n";

	return 0;
}


