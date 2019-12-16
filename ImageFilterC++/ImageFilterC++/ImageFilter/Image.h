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
#include "Util/loader.h"

#define SAFECOLOR(color) min(255, max(0, color))

namespace imagefilter{

class Image 
{
private:
	int width, height;

public:
	 
	//format of image (jpg/png)
    CString formatName;
	 // RGB Array Color
	unsigned int* colorArray;

public:
    
    int GetBPP() const {
        return image->GetBPP();
    }

	//original bitmap image
    CImage* image;
    CImage* destImage;
   
	Image(){}; 

	//dimensions of image 
    Image(CImage *img){                
        image =  img;

        if (image->GetBPP() == 32) {
            formatName = "png";
        } else {
            formatName = "jpg";
        }

        width = img->GetWidth();
        height = img->GetHeight();
		CImage *dest(img);
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
        int r, g, b, a;
        int index = 0;

        if (image->GetBPP() == 32) {
            BYTE* rgba;
            for (int y = 0; y < image->GetHeight(); y++)
            {
                for (int x = 0; x < image->GetWidth(); x++)
                {
                    int index = y * width + x;
                    rgba = (BYTE*)image->GetPixelAddress(x, y);
                    a = SAFECOLOR(rgba[3]);
                    r = SAFECOLOR(rgba[2]);
                    g = SAFECOLOR(rgba[1]);
                    b = SAFECOLOR(rgba[0]);
                    int rgbcolor = (a << 24) | (r << 16) | (g << 8) | b;
                    colorArray[index] = rgbcolor;
                    index++;
                }
            }
        }
        else {
            BYTE* rgb;
            for (int y = 0; y < image->GetHeight(); y++) 
            {
                for (int x = 0; x < image->GetWidth(); x++) 
                {
                    int index = y * width + x;
                    rgb = (BYTE*)image->GetPixelAddress(x, y);
                    r = SAFECOLOR(rgb[2]);
                    g = SAFECOLOR(rgb[1]);
                    b = SAFECOLOR(rgb[0]);
                    int rgbcolor = (r << 16) | (g << 8) | b;
                    colorArray[index] = rgbcolor;
                    index++;
                }
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
		BYTE r  = (0xFF0000 &color) >> 16;
		BYTE g  = (0x00FF00 &color) >> 8;
		BYTE b  = 0x0000FF &color;
		destImage->SetPixelRGB(x, y, r, g, b);
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
		destImage->SetPixelRGB(x, y, r, g, b);
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
    CImage* getImage() {
        //return image;
    	return destImage;
    }


    /**
     * @param image the image to set
     */
    void setImage(CImage *img) {
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
        colorArray = colors;
    }

	void Destroy()
	{
		delete colorArray;
		image->Destroy();
		destImage->Destroy();
	}
#include "Util/loader.h"
	static Image LoadImage(std::string imagePath){
		CImage *cimage = new CImage;
		CString filePath((CString)imagePath.c_str());
        using namespace image::util;
        gdiloader loader(imagePath);
        loader.load();
		HRESULT hresult = cimage->Load(filePath);
		if(cimage->IsNull()){
		   std::cout<<" failed load ";
		   return 0;
		}
		Image image(cimage);
		return image;
	}
};

}// namespace imagefilter
#endif