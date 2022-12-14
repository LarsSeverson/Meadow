#pragma once

#include "Meadow/Core.h"
#include "Meadow/Events/Event.h"

namespace Meadow {

	class MEADOW_API Layer
	{
	public:

		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onEvent(Event& event) {}

		inline const std::string& getDebugName() const { return mDebugName; }

	protected:
		std::string mDebugName;
	};
}

