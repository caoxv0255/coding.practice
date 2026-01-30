#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void gradeManagementSystem() {
    // 初始成绩列表
    std::vector<int> grades = { 85, 92, 76, 88, 95, 62, 70, 98, 83, 90 };

    // TODO 1: 打印所有成绩
    for (const auto& val : grades) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
    // TODO 2: 计算并打印平均分
    // 提示：使用accumulate或循环求和
    double sum = std:: accumulate(grades.begin(), grades.end(), 0.0);
    std::cout << "平均分：" << sum / grades.size();
    std::cout << std::endl;
    // TODO 3: 查找并打印最高分和最低分
    // 提示：使用std::max_element和std::min_element
    std::cout << "最高分：" << *std::max_element(grades.begin(),grades.end());
    std::cout << std::endl; 
    std::cout << "最低分：" << *std::min_element(grades.begin(), grades.end());
    std::cout << std::endl;
    // TODO 4: 统计及格人数（≥60分）
    // 提示：使用std::count_if
    int count = 0;
    for (const auto& grade : grades) {
        if (grade >= 60) {
            count++;
        }
    }
    std::cout << "及格人数：" << count;
    std::cout << std::endl;
    // TODO 5: 筛选出优秀成绩（≥90分）到新的vector并打印
    std::vector<int>great;
    for (const auto& grade : grades) {
        if (grade >= 90) {
            great.push_back(grade);
        }
    }
    std::cout << "优秀成绩：";
    for (const auto& val : great) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
    // TODO 6: 对成绩进行排序（从高到低）并打印
    for (int i = 0; i < grades.size()-1;i++) {
        int max = grades[i];
        int pos = i;
        for (int j = i+1; j < grades.size(); j++) {
            if (max < grades[j]) {
                max = grades[j];
                pos = j;
            }
        }
        int tmp = grades[i];
        grades[i] = grades[pos];
        grades[pos] = tmp;
    }
    std::cout << "排序后：";
    for (const auto& val : grades) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
    // TODO 7: 添加新成绩：从用户输入或固定添加3个新成绩，重新计算统计
    std::cout << "输入3个新成绩：";
    int a, b, c;
    std::cin >> a >> b >> c;
    grades.push_back(a);
    grades.push_back(b);
    grades.push_back(c);
    for (const auto& val : grades) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
    double sum1 = std::accumulate(grades.begin(), grades.end(), 0.0);
    std::cout << "平均分：" << sum1 / grades.size();
    std::cout << std::endl;
    std::cout << "最高分：" << *std::max_element(grades.begin(), grades.end());
    std::cout << std::endl;
    std::cout << "最低分：" << *std::min_element(grades.begin(), grades.end());
    std::cout << std::endl;
    int count1 = 0;
    for (const auto& grade : grades) {
        if (grade >= 60) {
            count1++;
        }
    }
    std::cout << "及格人数：" << count;
    std::cout << std::endl;    
    std::vector<int>great1;
    for (const auto& grade : grades) {
        if (grade >= 90) {
            great1.push_back(grade);
        }
    }
    std::cout << "优秀成绩：";
    for (const auto& val : great1) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < grades.size() - 1; i++) {
        int max = grades[i];
        int pos = i;
        for (int j = i + 1; j < grades.size(); j++) {
            if (max < grades[j]) {
                max = grades[j];
                pos = j;
            }
        }
        int tmp = grades[i];
        grades[i] = grades[pos];
        grades[pos] = tmp;
    }
    std::cout << "排序后：";
    for (const auto& val : grades) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
    // TODO 8: 删除不及格成绩（＜60分），打印删除后的列表
    for (auto it = grades.begin(); it != grades.end();) {
        if (*it < 60) {
            it = grades.erase(it);
        }
        else {
            it++;
        }
    }
    std::cout << "去除不及格成绩：";
    for (const auto& val : grades) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
}
int main() {
    gradeManagementSystem();
}