#pragma once

#ifdef DE_PLATFORM_WINDOWS

extern DreamEngine::APP* DreamEngine::CreateAPP();

int main(int argc, char** argv) {
	DreamEngine::Log::Init();
	DE_CORE_WARN("Initialized Log!");
	int a = 5;
	DE_INFO("Hello! Var={0}", a);
	auto app = DreamEngine::CreateAPP();
	app->Run();
	delete app;
}

#endif

