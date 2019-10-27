#pragma once

#ifdef MDLG_PLATFORM_WINDOWS
	#ifdef MDLG_BUILD_DLL
		#define MDLG_API __declspec(dllexport)
	#else
		#define MDLG_API __declspec(dllimport)
	#endif
#else
	#error Modular Genetics is only supported on Windows!
#endif 