#include "gdiplusdecoder.h"

namespace image
{
namespace util
{

	gdiplusdecoder::gdiplusdecoder(const string& name) {
		filename = name;
	}

	Gdiplus::Bitmap* gdiplusdecoder::load() {

#ifdef UNICODE
		std::wstring filename_w;
		filename_w.assign(filename.begin(), filename.end());
		Gdiplus::Bitmap* bitmap = Gdiplus::Bitmap::FromFile(filename_w.c_str());
#else
		Gdiplus::Bitmap* bitmap = Gdiplus::Bitmap::FromFile(filename);
#endif

		if (bitmap == NULL) {
			return FALSE;
		}

		if (Gdiplus::Ok != bitmap->GetLastStatus()) {
			return FALSE;
		}

		Gdiplus::BitmapData bitmapData;
		Gdiplus::Rect rect(0, 0, bitmap->GetWidth(), bitmap->GetHeight());

		if (Gdiplus::Ok == bitmap->LockBits(&rect, Gdiplus::ImageLockModeRead | Gdiplus::ImageLockModeWrite, bitmap->GetPixelFormat(), &bitmapData))
		{
			int len = bitmapData.Height * std::abs(bitmapData.Stride);

			BYTE* buffer = new BYTE[len];
			memcpy(buffer, bitmapData.Scan0, len);//copy it to an array of BYTEs
			bitmap->UnlockBits(&bitmapData);
			delete[]buffer;
		}
		return bitmap;
	}

	gdiplusdecoder::~gdiplusdecoder() {
		
	}

}

}