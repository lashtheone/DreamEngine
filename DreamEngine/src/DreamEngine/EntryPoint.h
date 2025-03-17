#pragma once

#ifdef DE_PLATFORM_WINDOWS

extern DreamEngine::APP* DreamEngine::CreateAPP();

int main(int argc, char** argv) {
	printf("Dream Engine\n");
	auto app = DreamEngine::CreateAPP();
	app->Run();
	delete app;
}

#endif

