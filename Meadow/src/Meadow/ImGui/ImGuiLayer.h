#pragma once

#include "Meadow/Layer.h"

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
	private:
		float mTime = 0.0f;
	};

}