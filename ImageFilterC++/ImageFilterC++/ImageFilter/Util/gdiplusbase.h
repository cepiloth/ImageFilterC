#pragma once
#include <iostream>
#include <string>
using namespace std;

#include <Shlwapi.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")

namespace image
{
namespace util
{
	class gdiplusbase {

	public:
		gdiplusbase() {
			Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
		}
		~gdiplusbase() {
			GdiplusShutdown(gdiplusToken);
		}

	private:
		GdiplusStartupInput gdiplusStartupInput;
		ULONG_PTR gdiplusToken;
	};

}
}