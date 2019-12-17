#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "gdiplusbase.h"

namespace image
{
namespace util
{
	class gdiplusencoder {
	public:
		gdiplusencoder() {
		};
		~gdiplusencoder() {
		};

		static void createImage(Gdiplus::Bitmap* image, const string& path, bool save = true) {
			gdiplusencoder encoder;
			encoder.save(image, path, save);
		}

		void save(Gdiplus::Bitmap* image, const string& path, bool save = true);

	private:
		int getEncoderClsid(const WCHAR* format, CLSID* pClsid);
	};

} // namespace util
} // namespace image