#include "Plugin.h"

#include "HelloPlugin.h"
#include "CurrentTimePlugin.h"

#include <Poco/ClassLibrary.h>

POCO_BEGIN_MANIFEST(Plugin)
	POCO_EXPORT_CLASS(HelloPlugin)
	POCO_EXPORT_CLASS(CurrentTimePlugin)
POCO_END_MANIFEST

