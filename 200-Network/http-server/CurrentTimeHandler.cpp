#include "CurrentTimeHandler.h"

#include <Poco/DateTime.h>
#include <Poco/DateTimeFormatter.h>
#include <Poco/DateTimeFormat.h>

void CurrentTimeHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
	response.setChunkedTransferEncoding(true);
	response.setContentType("text/html");

	Poco::DateTime now;
	std::string timeString(Poco::DateTimeFormatter::format(now, Poco::DateTimeFormat::SORTABLE_FORMAT));

	std::ostream& responseStream = response.send();
	responseStream << "<html><head><head><title>Simple HTTP Server</title></head>";
	responseStream << "<body><h1>Current Time</h1><p>";
	responseStream << ( timeString );
	responseStream << "</p></body></html>";
}
