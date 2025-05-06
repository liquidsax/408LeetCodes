//
// Created by lenovo on 3/3/2025.
//
#include "vector"
#include "algorithm"


class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_area = 0;
        int left = 0;
        int right = height.size() - 1; //c++代码使用size


        while (left < right){
            max_area=std::max(max_area,(right-left)*std::min(height[left],height[right]));
            if (height[left] < height[right]){
                left++;

            } else{
                right--;

            }
        }
        return max_area;

    }
};

//注释：
//第一
// C++ 标准库中的函数和对象（如 max、min、cout 等）都定义在 std 命名空间中。
// 使用 std:: 是为了明确调用标准库中的函数，避免与其他命名空间中同名的函数或变量冲突。
//第二
// 使用++left 比left ++效率更高
//