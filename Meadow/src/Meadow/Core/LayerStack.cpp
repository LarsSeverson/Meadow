#include "mdpch.h"
#include "LayerStack.h"

namespace Meadow {

	LayerStack::LayerStack() :
	layerInsert(0)
	{

	}

	LayerStack::~LayerStack() {
		for (Layer* layer : layers) {
			delete layer;
		}
	}

	void LayerStack::pushLayer(Layer* layer) {
		layers.emplace(layers.begin() + layerInsert++, layer);
	}

	void LayerStack::pushOverlay(Layer* overlay) {
		layers.emplace_back(overlay);
	}

	void LayerStack::popLayer(Layer* layer) {
		auto it = std::find(layers.begin(), layers.end(), layer);
		if (it != layers.end()) {
			layers.erase(it);
			layerInsert--;
		}
	}

	void LayerStack::popOverlay(Layer* overlay) {
		auto it = std::find(layers.begin(), layers.end(), overlay);
		if (it != layers.end()) {
			layers.erase(it);
		}
	}
}