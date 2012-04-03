#ifndef Plugin_INCLUDED
#define Plugin_INCLUDED

class Plugin
{
public:
	virtual ~Plugin();

	virtual void exec() = 0;
};

#endif // Plugin_INCLUDED
