//
//  previewGL.hpp
//  pic-test
//
//  Created by sunny on 2017/10/11.
//  Copyright © 2017年 HL. All rights reserved.
//

#ifndef previewGL_hpp
#define previewGL_hpp

#include <stdio.h>

typedef enum ReviewMode {
    ReviewModea = 10,
    ReviewModeb,
    ReviewModec,
} mode;

typedef enum DataSourceType {
    DataSourceTypeYUV420 = 100,
    DataSourceTypeRGB42
} dataType;


int disPlayData(const void* data,const int width,const int height);

void transformFrame(float scale,float x,float y);

void isMotionWithUsing(bool us);

void clearFrame(void);

#endif /* previewGL_hpp */
