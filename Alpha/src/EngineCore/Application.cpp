#include "alphapch.h"
#include "Application.h"

#include "EngineCore/Events/ApplicationEvent.h"
#include "EngineCore/Log.h"

namespace Alpha {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}
