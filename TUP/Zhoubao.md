# TUP周报

## 2023.12.9

* **上周计划：**

1. ROS 相机 + imu联合标定（已完成） 
2. 校内赛绿色弹丸识别（已完成）  

* **遇到的问题： **

1. 弹丸识别要求五个场景下使用同一 参数进行识别任务，多场景共用一套 预处理识别效果差
2. 相机 + imu联合标定时编译aslam_cv, sm_common等时出错  

* **下周计划： **

1. 学习感知机编写 
2. 学习Markdown编写

## 2023.12.16

* **上周计划：**

1. 学习Markdown编写（已完成，尝试编写了一个.md格式的Markdown语法总结方便回顾）

![image-20231216170409045](/home/kano/.config/Typora/typora-user-images/image-20231216170409045.png)

2. 学习感知机编写（已完成简单感知机的编写，尝试用Markdown写了个笔记）

![image-20231216170539499](/home/kano/.config/Typora/typora-user-images/image-20231216170539499.png)

![image-20231216171708396](/home/kano/.config/Typora/typora-user-images/image-20231216171708396.png)

* **遇到的问题：**

在学习感知机时，损失函数（极大似然估计法和交叉熵）和反向传播随机梯度下降法时高数和线代等数学基础知识不够...

![image-20231216165955335](/home/kano/.config/Typora/typora-user-images/image-20231216165955335.png)

导致感知机不能使用sigmoid函数（涉及到需要使用交叉熵计算的损失函数）

***在假期学习线代后***，写一个更复杂的感知机。

* **下周计划**：

  学习多线程（生产消费者模型）

