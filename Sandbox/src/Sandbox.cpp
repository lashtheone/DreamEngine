#include <Dream.h>

class Sandbox :public DreamEngine::APP
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

DreamEngine::APP* DreamEngine::CreateAPP() {
	return new Sandbox();
}