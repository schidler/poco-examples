#include "Plugin.h"

#include <Poco/ClassLoader.h>
#include <Poco/Manifest.h>

typedef Poco::ClassLoader<Plugin> PluginLoader;
typedef Poco::Manifest<Plugin> PluginManifest;

int main(int argc, char **argv)
{
	PluginLoader loader;

	std::string libraryName("./plugins");

	loader.loadLibrary(libraryName);

	PluginLoader::Iterator it(loader.begin());
	PluginLoader::Iterator end(loader.end());
	for ( ; it != end; ++it)
	{
		PluginManifest::Iterator itManifest(it->second->begin());
		PluginManifest::Iterator endManifest(it->second->end());
		for ( ; itManifest != endManifest; ++itManifest)
		{
			Plugin *pPlugin = itManifest->create();
			pPlugin->exec();
			delete pPlugin;
		}
	}

	loader.unloadLibrary(libraryName);

	return 0;
}
