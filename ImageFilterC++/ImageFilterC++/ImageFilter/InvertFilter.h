/* 
 * HaoRan ImageFilter Classes v0.1
 * Copyright (C) 2012 Zhenjun Dai
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation; either version 2.1 of the License, or (at your
 * option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation.
 */

#if !defined(INVERTFILTER_H)
#define INVERTFILTER_H

#include "IImageFilter.h"


namespace imagefilter{

class InvertFilter : public IImageFilter{

public:

	InvertFilter(){};

    std::string get_type_id() {
        return typeid(this).name();
    }

	virtual Image process(Image imageIn)
	{
		  int r, g, b, a;
          if (imageIn.GetBPP() == 32) 
          {
              for (int x = 0; x < imageIn.getWidth(); x++)
              {
                  for (int y = 0; y < imageIn.getHeight(); y++)
                  {
                      a = imageIn.getAComponent(x, y);
                      r = 255 - imageIn.getRComponent(x, y) * a / 255;
                      g = 255 - imageIn.getGComponent(x, y) * a / 255;
                      b = 255 - imageIn.getBComponent(x, y) * a / 255;
                      imageIn.setPixelColor(x, y, r, g, b);
                  }
              }
          }
          else 
          {
              for (int x = 0; x < imageIn.getWidth(); x++)
              {
                  for (int y = 0; y < imageIn.getHeight(); y++)
                  {
                      r = 255 - imageIn.getRComponent(x, y);
                      g = 255 - imageIn.getGComponent(x, y);
                      b = 255 - imageIn.getBComponent(x, y);
                      imageIn.setPixelColor(x, y, r, g, b);
                  }
              }
          }
          
          return imageIn;
	}
};

}// namespace imagefilter
#endif