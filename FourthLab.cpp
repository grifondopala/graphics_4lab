#include "lib.h" 

using namespace std;
using namespace cv;

void showImage(const Mat image) {
    imshow("Display window", image);
}

void saveImage(Mat* image, string name) {
    imwrite("D:/MEPHI/KG/FourthLab/FourthLab/FourthLab/result/" + name, *image);
}

void Bezier() {
    Mat bezierImage = Mat::zeros({ 1000, 1000 }, CV_8UC3);

    fillBackground(bezierImage, WHITE);

    MyPoint p0 = { 10, 10 };
    MyPoint p1 = { 400, 10 };
    MyPoint p2 = { 400, 800 };
    MyPoint p3 = { 800, 800 };
    DrawBezierCubic(p0, p1, p2, p3, bezierImage, BLACK);

    MyPoint p4 = { 600, 400 };
    MyPoint p5 = { 600, 200 };
    MyPoint p6 = { 800, 200 };
    MyPoint p7 = { 800, 400 };

    DrawBezierCubic(p4, p5, p6, p7, bezierImage, BLACK);

    saveImage(&bezierImage, "bezier_default.png");
}

void CyrusBeck() {
    Mat cyrusBeckImage = Mat::zeros({ 1000, 1000 }, CV_8UC3);

    fillBackground(cyrusBeckImage, WHITE);

    vector<MyPoint> points = {
        {100, 100},
        {100, 400},
        {200, 550},
        {300, 600},
        {400, 500},
        {450, 300},
        {400, 100},
        {200, 50},
        {100, 100}
    };

    Segment s1 = { {50, 150}, {500, 500} }; // Пересекает в 2 точках
    Segment s2 = { {250, 650}, {300, 500} }; // Пересекает в 1 точке
    Segment s3 = { {250, 150}, {250, 250} }; // Полностью лежит внутри
    Segment s4 = { {550, 550}, {600, 450} }; // Полностью вне многоугольника


    drawCyrusBeckLine(s1.p0, s1.p1, points, cyrusBeckImage);
    drawCyrusBeckLine(s2.p0, s2.p1, points, cyrusBeckImage);
    drawCyrusBeckLine(s3.p0, s3.p1, points, cyrusBeckImage);
    drawCyrusBeckLine(s4.p0, s4.p1, points, cyrusBeckImage);
    

    drawPolygon(points, cyrusBeckImage, BLACK);

    saveImage(&cyrusBeckImage, "cyrus_beck.png");
}

int main()
{
    Bezier();

    CyrusBeck();

    waitKey(0);
}
