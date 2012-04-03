#ifndef SimpleHTTPServerApplication_INCLUDED
#define SimpleHTTPServerApplication_INCLUDED

#include <Poco/Util/ServerApplication.h>

class SimpleHTTPServerApplication : public Poco::Util::ServerApplication
{
protected:
	int main(const std::vector<std::string> &args);
};

#endif // SimpleHTTPServerApplication_INCLUDED
