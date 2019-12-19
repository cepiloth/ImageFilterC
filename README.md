## Motivation
 > https://github.com/daizhenjun/ImageFilterC <br>
위 github 를 fork 하여 visual studio 2017 에서 사용할 수 있도록 하는 프로젝트 입니다.

## Usage
> InvertFilter 를 적용하는 예제
```c
#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include "ImageFilter/InvertFilter.h"
#include "ImageFilter/Util/Timer.h"
#include "ImageFilter/Util/gdiplusencoder.h"

using namespace imagefilter;
using namespace image::util;
using namespace std;

int main() {
   
   imagefilter::Image image = imagefilter::Image::loadImage("TODO PATH");
   InvertFilter invertFilter;
   invertFilter.process(image);
   
   return 0;
}

```

## Overview Lenna Picture
> https://en.wikipedia.org/wiki/Lenna <br>
Lenna 이미지 사용
<center><img src="./ImageFilterC%2B%2B/sample/overview_lenna.jpg"></center>

## Overview Earth Picture
> https://en.wikipedia.org/wiki/Earth <br>
지구 이미지 사용
<center><img src="./ImageFilterC%2B%2B/sample/overview_earth.jpg"></center>

## Preview
> 512x512 크기의 Lenna 이미지를 사용하고 이미지 효과를 적용한 처리 속도 입니다.

| Result Effect | Method                 | Throuput    |
|---------------|------------------------|-------------|
| ![이미지](./ImageFilterC%2B%2B/sample/0.png) | InvertFilter | 0.106086 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/1.png) | AutoLevelFilter        | 0.197569 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/2.png) | RadialDistortionFilter | 0.192900 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/3.png) | BannerFilter           | 0.288723 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/4.png) | BannerFilter           | 0.304961 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/5.png) | BigBrotherFilter       | 0.089314 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/6.png) | BlackWhiteFilter       | 0.085935 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/7.png) | BrightContrastFilter   | 0.086167 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/8.png) | ColorQuantizeFilter    | 0.102765 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/9.png) | ConvolutionFilter      | 0.097088 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/10.png)| BrickFilter            | 0.199622 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/11.png)| BlockPrintFilter       | 0.529578 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/12.png)| EdgeFilter	         | 0.087640 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/13.png)| FeatherFilter	     | 0.088265 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/14.png)| GaussianBlurFilter	 | 0.114838 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/15.png)| GradientFilter	     | 0.088434 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/16.png)| GradientMapFilter	 | 0.193238 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/17.png)| HistogramEqualFilter	 | 0.095030 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/18.png)| LightFilter	         | 0.087078 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/19.png)| MistFilter	         | 0.193775 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/20.png)| MonitorFilter	     | 0.087076 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/21.png)| MosaicFilter	         | 0.081982 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/22.png)| NeonFilter	         | 0.085314 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/23.png)| NightVisionFilter	 | 0.379196 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/24.png)| NoiseFilter	         | 0.104755 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/25.png)| OilPaintFilter	     | 0.190147 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/26.png)| OldPhotoFilter	     | 0.501815 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/27.png)| PixelateFilter	     | 0.083364 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/28.png)| RainBowFilter	     | 0.267623 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/29.png)| RectMatrixFilter	     | 0.371465 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/30.png)| ReflectionFilter	     | 0.160871 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/31.png)| ReflectionFilter	     | 0.135807 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/32.png)| ReliefFilter	         | 0.085816 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/33.png)| SaturationModifyFilter | 0.094494 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/34.png)| SepiaFilter	         | 0.259721 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/35.png)| SmashColorFilter	     | 0.526652 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/36.png)| ThresholdFilter	     | 0.086255 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/37.png)| TintFilter	         | 0.088502 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/38.png)| VignetteFilter	     | 0.085803 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/39.png)| VintageFilter	     | 0.463607 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/40.png)| WaterWaveFilter	     | 0.473135 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/41.png)| XRadiationFilter	     | 0.261391 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/42.png)| LomoFilter	         | 0.537803 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/43.png)| PaintBorderFilter	 | 0.289284 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/44.png)| PaintBorderFilter	 | 0.291217 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/45.png)| PaintBorderFilter	 | 0.278554 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/46.png)| SceneFilter	         | 0.357648 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/47.png)| SceneFilter	         | 0.361693 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/48.png)| SceneFilter	         | 0.361378 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/49.png)| SceneFilter	         | 0.354712 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/50.png)| ComicFilter	         | 0.805571 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/51.png)| FilmFilter	         | 0.372153 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/52.png)| FocusFilter	         | 0.100596 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/53.png)| CleanGlassFilter	     | 0.156440 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/54.png)| ZoomBlurFilter	     | 0.343415 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/55.png)| ThreeDGridFilter	     | 0.088587 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/56.png)| ColorToneFilter	     | 0.098929 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/57.png)| ColorToneFilter	     | 0.097265 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/58.png)| ColorToneFilter	     | 0.099154 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/59.png)| ColorToneFilter	     | 0.093244 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/60.png)| SoftGlowFilter	     | 0.438236 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/61.png)| TileReflectionFilter	 | 0.180296 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/62.png)| BlindFilter	         | 0.090303 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/63.png)| BlindFilter	         | 0.094129 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/64.png)| RaiseFrameFilter	     | 0.014381 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/65.png)| ShiftFilter	         | 0.176077 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/66.png)| BilinearDistort	     | 0.346604 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/67.png)| BilinearDistort	     | 0.336840 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/68.png)| BilinearDistort	     | 0.358604 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/69.png)| BilinearDistort	     | 0.364747 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/70.png)| IllusionFilter	     | 0.227147 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/71.png)| SupernovaFilter	     | 0.337803 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/72.png)| LensFlareFilter	     | 0.155022 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/73.png)| LUTFilter	         | 0.090318 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/74.png)| LUTFilter	         | 0.086115 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/75.png)| SharpFilter	         | 0.283059 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/76.png)| VideoFilter	         | 0.088937 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/77.png)| VideoFilter	         | 0.089118 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/78.png)| VideoFilter	         | 0.088005 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/79.png)| VideoFilter	         | 0.090388 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/80.png)| TileReflectionFilter	 | 0.181473 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/81.png)| TileReflectionFilter	 | 0.053037 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/82.png)| FillPatternFilter	 | 0.088166 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/83.png)| FillPatternFilter	 | 0.088692 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/84.png)| MirrorFilter	         | 0.081210 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/85.png)| MirrorFilter	         | 0.094007 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/86.png)| YCBCrLinearFilter	 | 0.090032 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/87.png)| YCBCrLinearFilter	 | 0.111320 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/88.png)| TexturerFilter	     | 0.225150 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/89.png)| TexturerFilter	     | 0.097996 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/90.png)| TexturerFilter	     | 0.111416 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/91.png)| TexturerFilter	     | 0.160737 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/92.png)| TexturerFilter	     | 0.188696 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/93.png)| HslModifyFilter	     | 0.117273 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/94.png)| HslModifyFilter	     | 0.116898 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/95.png)| HslModifyFilter	     | 0.110841 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/96.png)| HslModifyFilter	     | 0.112840 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/97.png)| HslModifyFilter	     | 0.108074 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/98.png)| HslModifyFilter	     | 0.112750 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/99.png)| HslModifyFilter	     | 0.111581 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/100.png)| HslModifyFilter	     | 0.115403 sec |
| ![이미지](./ImageFilterC%2B%2B/sample/101.png)| HslModifyFilter	     | 0.105351 sec |

## Development Environment
1. CPU Intel(R) Core(TM) i7-4790 CPU @ 3.60GHz
2. RAM 24.0gb
3. SYSTEM x64
4. Window 10
5. Visual Studio 2019

## License
> via https://github.com/daizhenjun/ImageFilterC 
