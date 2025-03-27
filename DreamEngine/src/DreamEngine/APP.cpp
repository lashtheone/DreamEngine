#include "depch.h"
#include "APP.h"

#include "DreamEngine/Events/APPEvent.h"
#include "DreamEngine/Log.h"

#include <GLFW/glfw3.h>

namespace DreamEngine {
	APP::APP() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	APP::~APP() {

	}

	void APP::Run() {
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}