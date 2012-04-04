#include "HelloPlugin.h"

#include <iostream>

HelloPlugin::~HelloPlugin()
{
	std::cout << "HelloPlugin::~HelloPlugin()" << std::endl;
}

void HelloPlugin::exec()
{
	std::cout << "Hello, World!" << std::endl;
}
