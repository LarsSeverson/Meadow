#pragma once

#include "Meadow/Core/Layer.h"

namespace Meadow {

	class 
		ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach() override;
		void onDetach() override;
		void onUpdate() override;
		void onEvent(Event& event) override;

		void guiBegin();
		void guiEnd();
	private:
		float mTime = 0.0f;
	};

}