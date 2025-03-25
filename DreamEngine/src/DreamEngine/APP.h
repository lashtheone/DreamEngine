#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace DreamEngine {
	class DREAM_API APP
	{
	public:
		APP();
		virtual ~APP();

		void Run();
	};
	//to be defined in CLIENT
	APP* CreateAPP();
}

