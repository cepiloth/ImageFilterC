#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include "example.h"
#include "ImageFilter/Util/Timer.h"
#include "ImageFilter/Util/gdiplusencoder.h"

inline bool exists(const std::string& name) {
	ifstream f(name.c_str());
	return f.good();
}

#define SELECT 1

int main()
{
	gdiplusbase base;
	int i = 0;
	
	vector<IImageFilter*> v;
	int type = SELECT;
	switch (type) {
	case 1:
		v = LoadFilterVector();
		break;
	case 2:
		v = LoadFilterVectorTest();
		break;
	case 3:
		v = LoadFilterTextureVector();
		break;
	}

	char filePath[64];
	for(auto it : v){    
		
		string path = "d:\\Lenna.png";
		if (false == exists(path)) {
			cout << "Please check the file path." << endl;
			break;
		}
		imagefilter::Image image = imagefilter::Image::loadImage("d:\\Lenna.png");
		//imagefilter::Image image = imagefilter::Image::LoadImage("d:\\png.png");
		{
			image::util::chrono_timer timer(i, it->get_type_id());
			image = it->process(image);
		}

		if (image.GetPixelFormat() == 32) {
			sprintf(filePath, "d:\\filter\\%d.png", i);
		}
		else {
			sprintf(filePath, "d:\\filter\\%d.jpg", i);
		}

		string filename(filePath);

		gdiplusencoder::createImage(image.destImage, filename, true);
		i++;
    }

	return 0;
}

