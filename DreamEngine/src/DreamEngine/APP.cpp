#include "APP.h"


#include "DreamEngine/Events/APPEvent.h"
#include "DreamEngine/Log.h"

namespace DreamEngine {
	APP::APP() {

	}
	APP::~APP() {

	}

	void APP::Run() {

		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			DE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			DE_TRACE(e);
		}
		while (true);
	}
}