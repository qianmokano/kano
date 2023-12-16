#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// 预测函数，根据权重和偏置进行预测
int predict(const vector<double>& data, const vector<double>& w, const double b);

// 生成数据集
void generate_data(const int data_size, vector<vector<double>>& Data, vector<int>& Label)
{
    srand(time(0));
    for (int i = 0; i < data_size; ++i)
    {
        vector<double> Random_num;
        // 生成在 [-1, 1] 范围内的随机浮点数
        double random_num = -1 + (static_cast<double>(rand()) / RAND_MAX) * 2;
        Random_num.push_back(random_num);
        random_num = -1 + (static_cast<double>(rand()) / RAND_MAX) * 2;
        Random_num.push_back(random_num);
        Data.push_back(Random_num);
        // 计算点积
        double dot_product = Random_num[0] * 3 + Random_num[1] * 4 + 10;
        int label = dot_product > 0 ? 1 : -1; // 确定 label
        Label.push_back(label);
    }
}

// 训练函数
void train(vector<vector<double>>& Data, vector<int>& Label, vector<double>& w, double& b, const int epochs, double learning_rate)
{
    for (size_t i = 0; i < epochs; i++)
    {
        for (size_t j = 0; j < Data.size(); j++)
        {
            int predict_label = predict(Data[j], w, b);
            if (predict_label != Label[j])
            {
                // 更新权重和偏置
                for (size_t k = 0; k < 2; k++)
                {
                    w[k] += learning_rate * Label[j] * Data[j][k];
                }
                b += learning_rate * Label[j];
            }
        }
    }
}

// 预测函数
int predict(const vector<double>& data, const vector<double>& w, const double b)
{
    double dot_product = 0;
    for (size_t i = 0; i < data.size(); i++)
    {
        dot_product += data[i] * w[i];
    }
    double predict_result = dot_product + b;
    return predict_result > 0 ? 1 : -1;
}

int main()
{
    // 生成数据集
    vector<vector<double>> Data;
    vector<int> Label;
    int data_size = 1000; // 数据集大小
    generate_data(data_size, Data, Label);

    // 初始化权重和偏置
    vector<double> w = {0, 0};
    double b = 0;

    // 设定学习率和迭代次数
    double learning_rate = 0.01; // 学习率
    int epochs = 100;           // 迭代次数

    // 开始训练
    train(Data, Label, w, b, epochs, learning_rate);

    // 输出训练结果
    cout << "训练结果: w: " << w[0] << ", " << w[1] << ", b: " << b << endl;

    // 测试
    vector<vector<double>> Test;
    vector<int> Test_Label;
    int test_size = 1;
    generate_data(test_size, Test, Test_Label);
    int Predict_Label = predict(Test[0], w, b);

    // 输出测试结果
    cout << "测试数据：" << Test[0][0] << ", " << Test[0][1] << endl;
    cout << "真实标签：" << Test_Label[0] << endl;
    cout << "预测标签：" << Predict_Label << endl;

    return 0;
}