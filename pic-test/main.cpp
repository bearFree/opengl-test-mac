//
//  main.cpp
//  pic-test
//
//  Created by sunny on 2017/10/9.
//  Copyright © 2017年 HL. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#define GLEW_STATIC
#include "glew.h"
#include "glfw3.h"
//#include <OpenGL/OpenGL.h>

using namespace std;

//void savefile()
//{
//    ofstream out("/Users/sunny/Desktop/Algorithm/test-c++/abc.txt");
//    out << 3 << '\t' << "abc" << endl;
//    out.close( );
//}
//
//void readfile()
//{
//    ifstream infile;
//    infile.open("/Users/sunny/Desktop/Algorithm/test-c++/wifi_yellow4.png", ios::binary);
//    
//    if (infile.is_open()) {
//        
//        //        ofstream out("/Users/sunny/Desktop/Algorithm/test-c++/abc.txt");
//        //        out << 3 << '\t' << "abc" << endl;
//        //        out.close( );
//        
//        ofstream out("/Users/sunny/Desktop/Algorithm/test-c++/save_image.png",ios::binary);
//        filebuf* pbuf = infile.rdbuf();
//        out << pbuf;
//        
//        cout<<"品牌："<<"brand"<<endl;
//        
//        out.close();
//    }
//    
//    infile.close();
//    
//}

void Render(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    {
        glColor3f(1.0,0.0,0.0);
        glVertex2f(-.5, .5);
        glColor3f(0.0,1.0,0.0);
        glVertex2f(0,-.5);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(.5, .5);
    }
    glEnd();
}

#define WIDTH 2
#define HEIGHT 3
int main(int argc, const char * argv[]) {
    
    int nWidth=(int)WIDTH;
    int nHeight=(int)HEIGHT;
    int nSize=(int)nWidth*nHeight;
    
    //创建输入数据
    float* pfInput=new float[4*nSize];
    float* pfOutput=new float[4*nSize];
    for (int i=0; i<nSize*4; i++)
    {
        pfInput[i]= (float)(i + 1.2345);
    }

    GLFWwindow* window;
    
    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }
    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        Render();
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwTerminate();
    

//    //创建FBO并绑定
//    GLuint fb;
//    glGenFramebuffersEXT(1, &fb);
//    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fb);
//
//    //创建纹理对象并绑定
//    GLuint tex;
//    glGenTextures(1, &tex);
//    glBindTexture(GL_TEXTURE_2D, tex);
//    //设置纹理参数
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
//
//    //将纹理关联到FBO
//    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, tex, 0);
//
//    //将纹理数据设置为单精度浮点数
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA_FLOAT32_ATI, nWidth, nHeight,0, GL_RGBA, GL_FLOAT, NULL);
//    //将数据传至输入纹理缓存
//    //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, nWidth, nHeight, 0, GL_RGBA, GL_FLOAT, pfInput);
//    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, nWidth, nHeight, GL_RGBA, GL_FLOAT, pfInput);
//
//    //从输出纹理缓存中读出数据
//    glReadBuffer(GL_COLOR_ATTACHMENT0_EXT);
//    glReadPixels(0,0, nWidth, nHeight, GL_RGBA, GL_FLOAT, pfOutput);
//
//    //打印并检查结果
//    bool bCap=true;
//    for (int i=0; i<nSize*4; i++)
//    {
//        cout<<i<<":\t"<<pfInput[i]<<'\t'<<pfOutput[i]<<endl;
//        if (pfInput[i]!=pfOutput[i])  bCap=false;
//    }
//
//    if (bCap) cout<<"Round trip complete!"<<endl;
//    else      cout<<"Round trip failed!" <<endl;
//
//    system("pause");
//
    // insert code here...
#if 1
//    GLFWwindow* window;
//
//    /* Initialize the library */
//    if (!glfwInit()) {
//        return -1;
//    }
//
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window))
//    {
//        /* Render here */
//        Render();
//
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//
//        /* Poll for and process events */
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
    
#else
    
    cout << "Hello World!" << endl;
    
    string filePath = "/Users/sunny/Desktop/pic-test/pic-test/res/live_verify_bg3x.png";
    Mat image = imread(filePath);
    namedWindow("OpenCVTest");
    imshow("OpenCVTest", image);
    
    Mat gray;
    cvtColor(image, gray, COLOR_RGBA2GRAY);
    namedWindow("gray");
    imshow("gray", gray);
    waitKey(0);
    
#endif
    
    return 0;
}
