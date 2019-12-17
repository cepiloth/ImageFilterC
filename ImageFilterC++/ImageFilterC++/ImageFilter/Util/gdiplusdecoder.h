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

		Gdiplus::Bitmap* load();

	private:
		int count;
		std::string filename;
	};

}
}