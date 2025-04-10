#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "DreamEngine/Events/APPEvent.h"


namespace DreamEngine {
	class DREAM_API APP
	{
	public:
		APP();
		virtual ~APP();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	//to be defined in CLIENT
	APP* CreateAPP();
}

