#include "depch.h"
#include "APP.h"

#include "DreamEngine/Log.h"

#include <glad/glad.h>

namespace DreamEngine {

#define BIND_EVENT_FN(x) std::bind(&APP::x, this, std::placeholders::_1)

	APP* APP::s_Instance = nullptr;

	APP::APP() {
		DE_CORE_ASSERT(!s_Instance, "APP already exists!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

	}
	APP::~APP() {

	}

	void APP::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void APP::PushOverlay(Layer* layer) {
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void APP::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		DE_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.m_Handled) break;
		}
	}

	void APP::Run() {
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate();
			}
			m_Window->OnUpdate();
		}
	}

	bool APP::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
}