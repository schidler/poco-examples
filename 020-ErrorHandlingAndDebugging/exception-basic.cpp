#include <iostream>
#include <Poco/Exception.h>

int main(int argc, char **argv)
{
	Poco::Exception *pException = NULL;

	try
	{
		throw Poco::ApplicationException("Just testing.");
	}
	catch (const Poco::Exception &exception)
	{
		pException = exception.clone();
	}

	try
	{
		pException->rethrow();
	}
	catch (const Poco::Exception &exception)
	{
		std::cerr << exception.displayText() << std::endl;
	}

	delete pException;

	return 0;
}
