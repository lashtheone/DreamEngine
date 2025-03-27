#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace DreamEngine {
	class DREAM_API APP
	{
	public:
		APP();
		virtual ~APP();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	//to be defined in CLIENT
	APP* CreateAPP();
}

