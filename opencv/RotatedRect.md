# opencv中RotatedRect（旋转矩形）类型

RotatedRect表示平面上的旋转矩形

这个类中包含了外接矩形的中心center、大小size以及角度angle，首先center是很好理解的，就是这个矩形的中心点位置，而angle代表的是旋转角度，size包含一个width和一个height，代表的是矩形的宽和高。

p[0]定义：未知

p[0]~p[3]按顺时针方向依次排列。

width与height定义：p[0]到p[3]之间的距离为宽width，其邻边为高height。

angle定义：以顶点画出水平线，顺时针旋转的角度

实例代码：

```c++
# include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    // 创建旋转矩形的中心、大小和旋转角度
    Point2f center(100, 100);
    Size2f size(150, 50);//(width,height)P0到P3之间的距离为width，和它相邻的边为height
    float angle = -30.0;//以顶点画出水平线，顺时针旋转的角度

    // 创建 RotatedRect 对象
    RotatedRect rotatedRect(center, size, angle);

    // 获取旋转矩形的顶点
    Point2f rectPoints[4];
    rotatedRect.points(rectPoints);

    // 绘制矩形
    Mat img(200, 200, CV_8UC3, Scalar(255, 255, 255));  // 创建一个白色背景的图像
    for (int i = 0; i < 4; ++i) {
        line(img, rectPoints[i], rectPoints[(i + 1) % 4], Scalar(0, 0, 255), 2);  // 用红色绘制矩形的边
    }

    imshow("Rotated Rectangle", img);
    for (int i = 0; i < 4; i++) {
        std::cout << "P" << i << "的坐标是" << rectPoints[i] << std::endl;
    }

    waitKey(0);

    return 0;
}
```
