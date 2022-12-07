#pragma once


#ifdef MD_PLATFORM_WINDOWS

extern Meadow::Application* Meadow::CreateApplication();

int main(int argc, char** argv) {
	auto app = Meadow::CreateApplication();
	app->Run();
	delete app;
}

#endif