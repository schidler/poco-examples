#include <Poco/RefCountedObject.h>
#include <Poco/AutoPtr.h>
#include <iostream>

class MyRCO : public Poco::RefCountedObject
{
public:
	MyRCO()
	{
	}

	void great() const
	{
		std::cout << "Hello, RCO!" << std::endl;
	}

protected:
	~MyRCO()
	{
	}
};

int main(int argc, char **argv)
{
	Poco::AutoPtr<MyRCO> pMyRCO(new MyRCO());

	pMyRCO->great();
	(*pMyRCO).great();

	MyRCO *p1 = pMyRCO;
	MyRCO *p2 = pMyRCO.get();

	std::cout << "[Before] Reference count: " << pMyRCO->referenceCount() << std::endl;

	{
		Poco::AutoPtr<MyRCO> anotherAutoPtr(pMyRCO);
		std::cout << "[In Scope] Reference count: " << pMyRCO->referenceCount() << std::endl;
	}

	std::cout << "[Out Scope] Reference count: " << pMyRCO->referenceCount() << std::endl;

	return 0;
}
