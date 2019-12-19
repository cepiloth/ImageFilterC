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

#if !defined(Image_H)
#define Image_H

#include "../stdafx.h"
#include "Util/gdiplusdecoder.h"
#include "Util/gdiplusdecoder.h"
using namespace image::util;

#define SAFECOLOR(color) min(255, max(0, color))

namespace imagefilter{

class Image 
{
private:
	int width, height;
    int bitcount;
public:
	 
	//format of image (jpg/png)
    CString formatName;
	 // RGB Array Color
	unsigned int* colorArray;

public:
    
    int GetPixelFormat() const {
        return bitcount;
    }

	//original bitmap image
    Gdiplus::Bitmap* image;
    Gdiplus::Bitmap* destImage;
   
	Image(){}; 

	//dimensions of image 
    Image(Gdiplus::Bitmap *img){        
        
        if (NULL == img) {
            return;
        }
        
        image =  img;

        Gdiplus::PixelFormat format = image->GetPixelFormat();

        switch (format) {
        case PixelFormat32bppARGB:
        case PixelFormat32bppPARGB:
        case PixelFormat32bppRGB:
            bitcount = 32;
            formatName = "png";
            break;
        default:
            bitcount = 24;
            formatName = "jpg";
            break;
        }

        width = img->GetWidth();
        height = img->GetHeight();
        Gdiplus::Bitmap* dest = img->Clone(0, 0, img->GetWidth(), img->GetHeight(), format);
	    destImage = dest;
        updateColorArray();
    };

    Image clone(){
    	return Image(image);
    }
    
    /**
     * Method to reset the image to a solid color
     * @param color - color to rest the entire image to
     */
    void clearImage(int color){
    	for(int y=0; y<height; y++){
            for(int x=0; x<width; x++){
            	setPixelColor(x, y, color);
            }
        }
    }
    
    /**
     * Set color array for image - called on initialisation
     * by constructor
     * 
     * @param bitmap
     */
    void updateColorArray(){
        colorArray = new unsigned int[width * height];
        int index = 0;

        for (int y = 0; y < image->GetHeight(); y++)
            {
                for (int x = 0; x < image->GetWidth(); x++)
                {
                    int index = y * width + x;
                    Gdiplus::Color color;
                    image->GetPixel(x, y, &color);
                    
                    unsigned int rgbcolor = color.GetValue();
                    colorArray[index] = rgbcolor;
                    index++;
                }
            }       
    }
    
    /**
     * Method to set the color of a specific pixel
     * 
     * @param x
     * @param y
     * @param color
     */
    void setPixelColor(int x, int y, int color){
		colorArray[((y * width+x))] = color;
		BYTE r  = (0xFF0000 & color) >> 16;
		BYTE g  = (0x00FF00 & color) >> 8;
		BYTE b  = (0x0000FF & color);
        Gdiplus::Color pixel(r, g, b);
		destImage->SetPixel(x, y, pixel);
    }
    

    /**
     * Get the color for a specified pixel
     * 
     * @param x
     * @param y
     * @return color
     */
    int getPixelColor(int x, int y){
        return colorArray[y*width+x];
    }
    
    /**
     * Set the color of a specified pixel from an RGB combo
     * 
     * @param x
     * @param y
     * @param c0
     * @param c1
     * @param c2
     */
    void setPixelColor(int x, int y, int r, int g, int b){
		colorArray[((y * width+x))] = (255 << 24) + (r << 16) + (g << 8) + b;
        Gdiplus::Color pixel(colorArray[((y * width + x))]);
        destImage->SetPixel(x, y, pixel);
    }

    
    void copyPixelsFromBuffer() { //将colorArray数组指针中的数据绑定到destImage
	    int index = 0;
		for(int x = 0 ; x < (image->GetWidth() - 1); x++){
			for(int y = 0 ; y < (image->GetHeight() - 1); y++){
				   index = y * width + x;
				   setPixelColor(x, y, colorArray[index]);
				   index++;	  
			  }
		 }
    }
    
    /**
     * Method to get the ALPHA color for the specified
     * pixel
     * @param x
     * @param y
     * @return color of A
    */
    int getAComponent(int x, int y) {
        return (colorArray[((y * width + x))] & 0xFF000000) >> 24;
    }

    /**
     * Method to get the RED color for the specified 
     * pixel 
     * @param x
     * @param y
     * @return color of R
     */
    int getRComponent(int x, int y){
         return (colorArray[((y*width+x))]& 0xFF0000) >> 16;
    }

    
    /**
     * Method to get the GREEN color for the specified 
     * pixel 
     * @param x
     * @param y
     * @return color of G
     */
    int getGComponent(int x, int y){
         return (colorArray[((y*width+x))]& 0x00FF00) >> 8;
    }


    /**
     * Method to get the BLUE color for the specified 
     * pixel 
     * @param x
     * @param y
     * @return color of B
     */
    int getBComponent(int x, int y){
         return (colorArray[((y*width+x))] & 0x0000FF);
    }

    
 
    /**
     * @return the image
     */
    Gdiplus::Bitmap* getImage() {
        //return image;
    	return destImage;
    }


    /**
     * @param image the image to set
     */
    void setImage(Gdiplus::Bitmap *img) {
        image = img;
    }


    /**
     * @return the formatName
     */
    CString getFormatName() {
        return formatName;
    }


    /**
     * @param formatName the formatName to set
     */
    void setFormatName(CString formatName) {
        formatName = formatName;
    }


    /**
     * @return the width
     */
    int getWidth() {
        return width;
    }


    /**
     * @param width the width to set
     */
    void setWidth(int width) {
       width = width;
    }


    /**
     * @return the height
     */
    int getHeight() {
        return height;
    }


    /**
     * @param height the height to set
     */
    void setHeight(int height) {
        height = height;
    }


    /**
     * @return the colorArray
     */
    unsigned int* getColorArray() {
        return colorArray;
    }


    /**
     * @param colorArray the colorArray to set
     */
    void setColorArray(unsigned int colors[]) {
        if (colorArray) {
            delete[] colorArray;
        }
        colorArray = colors;
    }

	void Destroy()
	{
		delete[] colorArray;
	}

	static Image loadImage(const string& path){
		
        Gdiplus::Bitmap* bitmap = gdiplusdecoder::loadImage(path);
        if (NULL == bitmap) {
            return NULL;
        }
		Image image = bitmap;
		return image;
	}
};

}// namespace imagefilter
#endif