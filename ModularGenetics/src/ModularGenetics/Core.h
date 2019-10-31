#pragma once
#ifdef MDLG_BUILD_DLL
	#define MDLG_API __declspec(dllexport)
#else
	#define MDLG_API __declspec(dllimport)
#endif