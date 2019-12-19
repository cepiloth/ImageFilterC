## Motivation
 > https://github.com/daizhenjun/ImageFilterC <br>
위 github 를 fork 하여 visual studio 2017 에서 사용할 수 있도록 하는 프로젝트 입니다.

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
| ![이미지](./ImageFilterC%2B%2B/sample/1.png) | AutoLevelFilter        | 0.197569 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/2.png) | RadialDistortionFilter | 0.192900 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/3.png) | BannerFilter           | 0.288723 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/4.png) | BannerFilter           | 0.304961 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/5.png) | BigBrotherFilter       | 0.089314 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/6.png) | BlackWhiteFilter       | 0.085935 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/7.png) | BrightContrastFilter   | 0.086167 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/8.png) | ColorQuantizeFilter    | 0.102765 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/9.png) | ConvolutionFilter      | 0.097088 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/10.png)| BrickFilter            | 0.199622 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/11.png)| BlockPrintFilter       | 0.529578 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/12.png)| EdgeFilter	         | 0.087640 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/13.png)| FeatherFilter	     | 0.088265 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/14.png)| GaussianBlurFilter	 | 0.114838 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/15.png)| GradientFilter	     | 0.088434 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/16.png)| GradientMapFilter	 | 0.193238 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/17.png)| HistogramEqualFilter	 | 0.095030 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/18.png)| LightFilter	         | 0.087078 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/19.png)| MistFilter	         | 0.193775 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/20.png)| MonitorFilter	     | 0.087076 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/21.png)| MosaicFilter	         | 0.081982 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/22.png)| NeonFilter	         | 0.085314 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/23.png)| NightVisionFilter	 | 0.379196 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/24.png)| NoiseFilter	         | 0.104755 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/25.png)| OilPaintFilter	     | 0.190147 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/26.png)| OldPhotoFilter	     | 0.501815 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/27.png)| PixelateFilter	     | 0.083364 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/28.png)| RainBowFilter	     | 0.267623 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/29.png)| RectMatrixFilter	     | 0.371465 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/30.png)| ReflectionFilter	     | 0.160871 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/31.png)| ReflectionFilter	     | 0.135807 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/32.png)| ReliefFilter	         | 0.085816 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/33.png)| SaturationModifyFilter | 0.094494 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/34.png)| SepiaFilter	         | 0.259721 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/35.png)| SmashColorFilter	     | 0.526652 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/36.png)| ThresholdFilter	     | 0.086255 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/37.png)| TintFilter	         | 0.088502 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/38.png)| VignetteFilter	     | 0.085803 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/39.png)| VintageFilter	     | 0.463607 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/40.png)| WaterWaveFilter	     | 0.473135 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/41.png)| XRadiationFilter	     | 0.261391 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/42.png)| LomoFilter	         | 0.537803 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/43.png)| PaintBorderFilter	 | 0.289284 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/44.png)| PaintBorderFilter	 | 0.291217 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/45.png)| PaintBorderFilter	 | 0.278554 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/46.png)| SceneFilter	         | 0.357648 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/47.png)| SceneFilter	         | 0.361693 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/48.png)| SceneFilter	         | 0.361378 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/49.png)| SceneFilter	         | 0.354712 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/50.png)| ComicFilter	         | 0.805571 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/51.png)| FilmFilter	         | 0.372153 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/52.png)| FocusFilter	         | 0.100596 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/53.png)| CleanGlassFilter	     | 0.156440 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/54.png)| ZoomBlurFilter	     | 0.343415 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/55.png)| ThreeDGridFilter	     | 0.088587 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/56.png)| ColorToneFilter	     | 0.098929 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/57.png)| ColorToneFilter	     | 0.097265 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/58.png)| ColorToneFilter	     | 0.099154 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/59.png)| ColorToneFilter	     | 0.093244 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/60.png)| SoftGlowFilter	     | 0.438236 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/61.png)| TileReflectionFilter	 | 0.180296 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/62.png)| BlindFilter	         | 0.090303 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/63.png)| BlindFilter	         | 0.094129 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/64.png)| RaiseFrameFilter	     | 0.014381 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/65.png)| ShiftFilter	         | 0.176077 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/66.png)| BilinearDistort	     | 0.346604 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/67.png)| BilinearDistort	     | 0.336840 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/68.png)| BilinearDistort	     | 0.358604 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/69.png)| BilinearDistort	     | 0.364747 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/70.png)| IllusionFilter	     | 0.227147 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/71.png)| SupernovaFilter	     | 0.337803 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/72.png)| LensFlareFilter	     | 0.155022 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/73.png)| LUTFilter	         | 0.090318 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/74.png)| LUTFilter	         | 0.086115 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/75.png)| SharpFilter	         | 0.283059 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/76.png)| VideoFilter	         | 0.088937 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/77.png)| VideoFilter	         | 0.089118 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/78.png)| VideoFilter	         | 0.088005 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/79.png)| VideoFilter	         | 0.090388 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/80.png)| TileReflectionFilter	 | 0.181473 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/81.png)| TileReflectionFilter	 | 0.053037 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/82.png)| FillPatternFilter	 | 0.088166 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/83.png)| FillPatternFilter	 | 0.088692 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/84.png)| MirrorFilter	         | 0.081210 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/85.png)| MirrorFilter	         | 0.094007 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/86.png)| YCBCrLinearFilter	 | 0.090032 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/87.png)| YCBCrLinearFilter	 | 0.111320 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/88.png)| TexturerFilter	     | 0.225150 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/89.png)| TexturerFilter	     | 0.097996 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/90.png)| TexturerFilter	     | 0.111416 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/91.png)| TexturerFilter	     | 0.160737 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/92.png)| TexturerFilter	     | 0.188696 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/93.png)| HslModifyFilter	     | 0.117273 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/94.png)| HslModifyFilter	     | 0.116898 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/95.png)| HslModifyFilter	     | 0.110841 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/96.png)| HslModifyFilter	     | 0.112840 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/97.png)| HslModifyFilter	     | 0.108074 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/98.png)| HslModifyFilter	     | 0.112750 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/99.png)| HslModifyFilter	     | 0.111581 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/100.png)| HslModifyFilter	     | 0.115403 ms |
| ![이미지](./ImageFilterC%2B%2B/sample/101.png)| HslModifyFilter	     | 0.105351 ms |

## Development Environment
1. CPU Intel(R) Core(TM) i7-4790 CPU @ 3.60GHz
2. RAM 24.0gb
3. SYSTEM x64
4. Window 10
5. Visual Studio 2019

## License
> via https://github.com/daizhenjun/ImageFilterC 
