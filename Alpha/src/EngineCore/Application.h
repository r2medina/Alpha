#pragma once

#include "Core.h"

#include "Window.h"
#include "EngineCore/LayerStack.h"
#include "EngineCore/Events/Event.h"
#include "EngineCore/Events/ApplicationEvent.h"

#include "EngineCore/ImGui/ImGuiLayer.h"


namespace Alpha {

	class ALPHA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window;  }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;



	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}

