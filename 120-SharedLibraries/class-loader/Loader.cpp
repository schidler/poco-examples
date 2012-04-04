#include "Plugin.h"

#include <Poco/ClassLoader.h>
#include <Poco/Manifest.h>

#include <iostream>

typedef Poco::ClassLoader<Plugin> PluginLoader;
typedef Poco::Manifest<Plugin> PluginManifest;

void iterateLoader(const PluginLoader &loader);

int main(int argc, char **argv)
{
	PluginLoader loader;

	std::string libraryName("./plugins");

	loader.loadLibrary(libraryName);

	iterateLoader(loader);

	loader.unloadLibrary(libraryName);

	std::cout << "Library unloaded" << std::endl;

	return 0;
}

void iterateLoader(const PluginLoader &loader)
{
	std::cout << "==== Begin of loader iteraation ====" << std::endl;

	PluginLoader::Iterator it(loader.begin());
	PluginLoader::Iterator end(loader.end());
	for ( ; it != end; ++it)
	{
		std::cout << "== Library: " << (it->first) << std::endl;

		PluginManifest::Iterator itManifest(it->second->begin());
		PluginManifest::Iterator endManifest(it->second->end());
		for ( ; itManifest != endManifest; ++itManifest)
		{
			std::cout << " {-- class: " << itManifest->name() << std::endl;

			Plugin *pPlugin = itManifest->create();
			itManifest->autoDelete(pPlugin);
			pPlugin->exec();

			std::cout << " ----} " << std::endl;
		}

		std::cout << "== End of library ==" << std::endl;
	}

	std::cout << "==== End of loader iteraation ====" << std::endl;
}
