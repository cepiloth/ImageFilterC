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
		class gdiloader {
		
		public:
			gdiloader(const string& name);
			~gdiloader();

			bool load();

		private:
			GdiplusStartupInput gdiplusStartupInput;
			ULONG_PTR gdiplusToken;
			int count;
			std::string filename;
		};

	}
}