#include "SimpleHTTPServerApplication.h"

#include "HandlerFactory.h"

#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>

int SimpleHTTPServerApplication::main(const std::vector<std::string> &args)
{
	Poco::UInt16 port = 9999;

	Poco::Net::ServerSocket socket(port);

	Poco::Net::HTTPServerParams *pParams = new Poco::Net::HTTPServerParams();
	pParams->setMaxQueued(100);
	pParams->setMaxThreads(16);

	Poco::Net::HTTPServer server(new HandlerFactory(), socket, pParams);

	server.start();

	waitForTerminationRequest();

	server.stop();

	return EXIT_OK;
}
