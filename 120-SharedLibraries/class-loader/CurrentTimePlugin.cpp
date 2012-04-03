#include "CurrentTimePlugin.h"

#include <Poco/DateTime.h>
#include <Poco/DateTimeFormatter.h>
#include <Poco/DateTimeFormat.h>

#include <iostream>

void CurrentTimePlugin::exec()
{
	Poco::DateTime now;
	std::string timeString(Poco::DateTimeFormatter::format(now, Poco::DateTimeFormat::SORTABLE_FORMAT));

	std::cout << "Current tiem: " << timeString << std::endl;
}
