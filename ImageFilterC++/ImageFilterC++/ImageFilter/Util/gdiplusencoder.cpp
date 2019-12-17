#include "gdiplusencoder.h"
namespace image
{
namespace util
{

	void gdiplusencoder::save(Gdiplus::Bitmap* image, const string& path, bool save) {
		
		if (false == save) {
			return;
		}
		
#ifdef UNICODE
		std::wstring filename;
		filename.assign(path.begin(), path.end());
#else
		std::string filename = path;
#endif

		CLSID clsid;
		int result = -1;
		Gdiplus::PixelFormat format = image->GetPixelFormat();

		switch (format) {
		case PixelFormat32bppARGB:
		case PixelFormat32bppPARGB:
		case PixelFormat32bppRGB:
			result = getEncoderClsid(L"image/png", &clsid);
		default:
			result = getEncoderClsid(L"image/jpeg", &clsid);
			break;
		}
		if (-1 == result) {
			cout << "clsid failed";
			return;
		}
		
		HRESULT hr = image->Save(filename.c_str(), &clsid);
		if (FAILED(hr)) {
			cout << " save failed";
			return;
		}
	}

	int gdiplusencoder::getEncoderClsid(const WCHAR* format, CLSID* pClsid) {
		UINT  num = 0;          // number of image encoders
		UINT  size = 0;         // size of the image encoder array in bytes

		ImageCodecInfo* pImageCodecInfo = NULL;

		Gdiplus::GetImageEncodersSize(&num, &size);
		if (size == 0)
			return -1;  // Failure

		pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
		if (pImageCodecInfo == NULL)
			return -1;  // Failure

		Gdiplus::GetImageEncoders(num, size, pImageCodecInfo);

		for (UINT j = 0; j < num; ++j)
		{
			if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
			{
				*pClsid = pImageCodecInfo[j].Clsid;
				free(pImageCodecInfo);
				return j;  // Success
			}
		}

		free(pImageCodecInfo);
		return -1;  // Failure
	}

} // namespace util
} // namespace image