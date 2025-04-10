#include <DreamEngine.h>


class ExampleLayer :public DreamEngine::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
		DE_INFO("ExampleLayer::Update");
	}

	void OnEvent(DreamEngine::Event& event) override
	{
		DE_TRACE("{0}", event);
	}
};

class Sandbox :public DreamEngine::APP
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

DreamEngine::APP* DreamEngine::CreateAPP() {
	return new Sandbox();
}