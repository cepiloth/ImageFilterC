/* 
 * HaoRan ImageFilter Classes v0.3
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

#if !defined(IllusionFilter_H)
#define IllusionFilter_H

#include "IImageFilter.h"


namespace imagefilter{

class IllusionFilter : public IImageFilter{

private:
	double _amount;
    double _scale;
    double _offset;
 
public:

	IllusionFilter (int amount)
    {
        _amount = LIB_PI / ((amount >= 1) ? amount : 1) ;
    }

	std::string get_type_id() {
		return typeid(this).name();
	}

	virtual Image process(Image imageIn)
	{
		double width = imageIn.getWidth();
        double height = imageIn.getHeight();
        Image clone = imageIn.clone();
		int r, g, b;
		for(int x = 0 ; x < (width - 1) ; x++){
			for(int y = 0 ; y < (height - 1) ; y++){
				r = imageIn.getRComponent(x, y);
				g = imageIn.getGComponent(x, y);
				b = imageIn.getBComponent(x, y);

				_scale = sqrt(width*width + height*height) / 2 ;
				_offset = (int)(_scale / 2) ;
				double cx = (x - width / 2.0) / _scale ;
				double cy = (y - height / 2.0) / _scale ;
				double angle = floor (atan2(cy,cx) / 2.0 / _amount) * 2.0 * _amount + _amount;
				double radius = sqrt(cx*cx + cy*cy) ;
				int xx = (int)(x - _offset * cos(angle)) ;
				int yy = (int)(y - _offset * sin(angle)) ;
				xx = FClamp(xx, 0, (int)(width-1));
				yy = FClamp(yy, 0, (int)(height-1));

				r = FClamp0255 (r + radius * (clone.getRComponent(xx, yy) - r)) ;
				g = FClamp0255 (g + radius * (clone.getGComponent(xx, yy) - g)) ;
				b = FClamp0255 (b + radius * (clone.getBComponent(xx, yy) - b)) ;
				imageIn.setPixelColor(x, y, r, g, b);
			}
		}
		return imageIn;
	}
};

}// namespace imagefilter
#endif