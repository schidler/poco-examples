#include <iostream>
#include <Poco/Util/Application.h>

class HelloPocoApplication : public Poco::Util::Application
{
protected:
	virtual int main(const std::vector<std::string> &args)
	{
		std::cout << "Hello, POCO C++ Libraries!" << std::endl;

		return EXIT_OK;
	}
};

POCO_APP_MAIN(HelloPocoApplication);
