#include "HandlerFactory.h"

#include "CurrentTimeHandler.h"

HandlerFactory::HandlerFactory () 
{
}

Poco::Net::HTTPRequestHandler * HandlerFactory::createRequestHandler (const Poco::Net::HTTPServerRequest &request)
{
	return new CurrentTimeHandler();
} 
