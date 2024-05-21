/*
    Graphviz document: https://graphviz.org/documentation/
    OpenCV document (v4.5.5): https://docs.opencv.org/4.5.5/
*/
#include <graphviz/gvc.h>
#include <opencv2/opencv.hpp>
#include "boost_typedef.h"

//#pragma warning(disable:4996)

//-------------------------------------
//  Convert .dot to .png using Graphviz
//
bool saveImageGV(std::string file_path)
{
    GVC_t* gvc;
    Agraph_t* g;
    FILE* fp1, * fp2;
    gvc = gvContext();
    fopen_s(&fp1, (file_path + ".dot").c_str(), "r");
    g = agread(fp1, 0);
    gvLayout(gvc, g, "dot");
    fopen_s(&fp2, (file_path + ".png").c_str(), "wb");
    gvRender(gvc, g, "png", fp2);
    gvFreeLayout(gvc, g);
    agclose(g);
    _fcloseall();
    return (gvFreeContext(gvc));
} // end of saveImageGV

//-------------------------------
// Show graph image using OpenCV
//
int showImageCV(std::string file_path)
{
    cv::Mat src;
    src = cv::imread(file_path + ".png"); //Ū�� test.png��
    cv::imshow(file_path, src); //���ͼ��D��image!�������A���src
    cv::waitKey(0); //�Ȱ��@�w���ɶ�(ms)�A== 0�ɫؽL���U�h�~�|����
    cv::destroyWindow(file_path);
} // end of showImageCV

//--------------------------------------------------
// Convert .dot to .png and show graph on the screen
//
void show_graph(std::string file_path)
{
    saveImageGV(file_path); 
    showImageCV(file_path);
} // end of show_graph
