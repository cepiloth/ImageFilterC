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

		//get the bitmap data
		if (Gdiplus::Ok == bitmap->LockBits(
			&rect, //A rectangle structure that specifies the portion of the Bitmap to lock.
			Gdiplus::ImageLockModeRead | Gdiplus::ImageLockModeWrite, //ImageLockMode values that specifies the access level (read/write) for the Bitmap.
			bitmap->GetPixelFormat(),// PixelFormat values that specifies the data format of the Bitmap.
			&bitmapData //BitmapData that will contain the information about the lock operation.
		))
		{
			//get the lenght of the bitmap data in bytes
			int len = bitmapData.Height * std::abs(bitmapData.Stride);

			BYTE* buffer = new BYTE[len];

			// TODO:: 써글 오픈 소스 src, dst 반대로 해놓고 이걸 스택오버플로우에 올리네;..
#if 0
			memcpy(bitmapData.Scan0, buffer, len);//copy it to an array of BYTEs
#else
			memcpy(buffer, bitmapData.Scan0, len);//copy it to an array of BYTEs
#endif
			//... 

			//cleanup
			bitmap->UnlockBits(&bitmapData);
			delete[]buffer;
		}
		return bitmap;
	}

	gdiplusdecoder::~gdiplusdecoder() {
		
	}

}

}