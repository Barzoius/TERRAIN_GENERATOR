#pragma once

#include "Window.h"

#include <GLFW/glfw3.h>



namespace TERRAIN_GENERATOR
{
	class WindowsWindow : public CWindow
	{

	public:

		WindowsWindow(const SWindow_Specifics& specs);

		virtual ~WindowsWindow() noexcept;

		void OnUpdate() override;

		inline uint32_t GetWidth() const override { return m_Data.Width; };
		inline uint32_t GetHeight() const override { return m_Data.Height; };;

		inline void SetEventCallback(const EventCallbackFn& callback) override {};
		
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;


	private:

		virtual void Init(const SWindow_Specifics& sepcs);
		virtual void Shutdown();

		GLFWwindow* m_Window;

		struct SWindow_Data
		{
			std::string Title;
			uint32_t Width;
			uint32_t Height;
			bool VSync;

			EventCallbackFn EventCallback;

		};

		SWindow_Data m_Data;

	};


}

