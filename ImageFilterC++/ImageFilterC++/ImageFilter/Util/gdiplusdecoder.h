#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "gdiplusbase.h"

namespace image
{
namespace util
{
	class gdiplusdecoder {
		
	public:
		gdiplusdecoder(const string& name);
		~gdiplusdecoder();

		static Gdiplus::Bitmap* loadImage(const string& name) {
			gdiplusdecoder decoder(name);
			return decoder.load();
		}

	protected:
		Gdiplus::Bitmap* load();

	private:
		int count;
		std::string filename;
	};

}
}