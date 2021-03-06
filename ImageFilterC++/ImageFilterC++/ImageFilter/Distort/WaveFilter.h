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

#ifndef WaveFilter_H
#define WaveFilter_H

#include "BilinearDistort.h"

namespace imagefilter
{

class WaveFilter : public BilinearDistort{

private:
	double _phase;
    double _amplitude ;
    double _waveLength ;

public:

	WaveFilter(int wavelength, int amplitude, double phase=0)
    {
        _waveLength = 2 * ((wavelength >= 1) ? wavelength : 1) ;
        _amplitude = ((amplitude >= 1) ? amplitude : 1) ;
		_phase = phase ;
    };

	virtual void calc_undistorted_coord (int x, int y, double& un_x, double& un_y)
    {
        double width = clone.getWidth();
        double height = clone.getHeight() ;
        double fScaleX = 1.0;
		double fScaleY = 1.0 ;
        if (width < height)
            fScaleX = height / width ;
        else if (width > height)
            fScaleY = width / height ;

        // distances to center, scaled
        double cen_x = width / 2.0;
        double cen_y = height / 2.0;
        double dx = (x - cen_x) * fScaleX;
        double dy = (y - cen_y) * fScaleY;
        double amnt = _amplitude * sin (2 * LIB_PI * sqrt (dx*dx + dy*dy) / _waveLength + _phase) ;
        un_x = (amnt + dx) / fScaleX + cen_x ;
        un_y = (amnt + dy) / fScaleY + cen_y ;
        un_x = FClamp (un_x, 0.0, width-1.0) ;
        un_y = FClamp (un_y, 0.0, height-1.0) ;
    }
};

}// namespace imagefilter
#endif