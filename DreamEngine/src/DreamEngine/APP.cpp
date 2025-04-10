#include "depch.h"
#include "APP.h"

#include "DreamEngine/Log.h"

#include <GLFW/glfw3.h>

namespace DreamEngine {

#define BIND_EVENT_FN(x) std::bind(&APP::x, this, std::placeholders::_1)

	APP::APP() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	APP::~APP() {

	}

	void APP::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		DE_CORE_TRACE("{0}", e);
	}

	void APP::Run() {
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool APP::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
}