#pragma once

#include "Core.h"

#include "Window.h"
#include "DreamEngine/LayerStack.h"
#include "DreamEngine/Events/Event.h"
#include "DreamEngine/Events/APPEvent.h"


namespace DreamEngine {
	class DREAM_API APP
	{
	public:
		APP();
		virtual ~APP();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};
	//to be defined in CLIENT
	APP* CreateAPP();
}

