#include <iostream>
#include <vector>
#include "array.h"
#include <math.h>

using namespace array;

/**
 * 【704. 二分查找】（重点：区间的开与闭）
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
 * 写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 */
int Solution::search(std::vector<int>& nums, int target){
#if 0   // [left, right]：左闭右闭
    int left = 0, right = nums.size()-1;
    while(left <= right){
        int mid = (left+right)/2;
        if(nums[mid] > target){
            right = mid-1;  // right可以nums选中取值，因而不选mid这个已知不存在的
        }
        else if(nums[mid] < target){
            left = mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;

#else   // [left, right）：左闭右开
    int left = 0, right = nums.size();
    while(left < right){
        int mid = (left+right)/2;
        if(nums[mid] > target){
            right = mid;
        }
        else if(nums[mid] < target){
            left = mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
#endif
}


/**
 * 【27. 移除元素】（技巧：快慢指针）
 */
int Solution::removeElement(std::vector<int>& nums, int val){
    int fast_p = 0, slow_p = 0;
    int size = nums.size();
    for(fast_p=0; fast_p<nums.size(); fast_p++){
        if(nums[fast_p] != val){
            nums[slow_p] = nums[fast_p];
            slow_p++;
        }
        else{
            size--;
        }
    }
    return size;
}

/**
 * 【977.有序数组的平方】（特点：平方后左右都向中部递减，使用双指针左右比较递进）
 */
std::vector<int> Solution::sortedSquares(std::vector<int>& nums){
    std::vector<int> res(nums.size(), 0);
    int left_p = 0, right_p = nums.size()-1;
    int i = right_p;
    while(i >= 0){
        int left2 = nums[left_p]*nums[left_p];
        int right2 = nums[right_p]*nums[right_p];
        if(left2 >= right2){
            res[i--] = left2;
            left_p++;
            // 只存储其中一个，另一个未免就是次大
        }
        else{
            res[i--] = right2;
            right_p--;
        }
    }
    return res;
}

/**
 * 【209.长度最小的子数组】
 * 【自己尝试解决的，依靠双指针思想】
 */
int Solution::minSubArrayLen(int target, std::vector<int>& nums){
    int right_p = 0, left_p = 0;
    int total_sum = nums[0], min_len = nums.size();
    int match_flag = 0, move_flag = 0;
    while(right_p <= nums.size()-1 && left_p <= right_p){
        if(move_flag == 1){
            total_sum += nums[right_p];
        }
        else if(move_flag == 2){
            total_sum -= nums[left_p-1];
        }

        if(total_sum < target){
            right_p++;
            move_flag = 1;
        }
        else if(total_sum >= target){
            if(match_flag == 0){
                match_flag = 1;  // 告知存在符合
            }
            int len = right_p - left_p + 1;    // 注意右边是否是闭
            if(len < min_len){
                min_len = len;
            }
            left_p++;
            move_flag = 2;
        }
    }
    if(match_flag){
        return min_len;
    }
    return 0;
}

/**
 * 【59.螺旋矩阵II】
 */
std::vector<std::vector<int>> Solution::generateMatrix(int n){
#if 0 //能过但是不是最优解
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    int cur_num = 1, end_num = n*n;
    int start_x = -1, start_y = 0;
    int cur_x = -1, cur_y = 0;
    int len = n, flag = 0, step = 0;

    while(len > 0){
        switch(flag){
            case 0:  // 右添加
                cur_x++;
                step++;
                matrix[cur_y][cur_x] = cur_num++;
                if(step >= len){
                    flag = 1;   
                    step = 0;
                    len -= 1;
                }
                break;
            
            case 1:  // 下添加
                cur_y++;
                step++;
                matrix[cur_y][cur_x] = cur_num++;
                if(step >= len){
                    flag = 2;
                    step = 0;   
                }
                break;          
            
            case 2: // 左添加
                cur_x--;
                step++;
                matrix[cur_y][cur_x] = cur_num++;
                if(step >= len){
                    flag = 3;
                    step = 0;   
                    len -= 1;
                }
                break;     
                
            case 3: // 上添加
                cur_y--;
                step++;
                matrix[cur_y][cur_x] = cur_num++;
                if(step >= len){
                    flag = 0;
                    step = 0;   
                }
                break;      
        }
    }
    return matrix;
#else

#endif
}

void test_generateMatrix(void){
    Solution s;
    int n = 4;
    std::vector<std::vector<int>> res = s.generateMatrix(n);
    for(int i=0; i<n; i++){
        printf("[ ");
        for(int j=0; j<n; j++){
            printf("%d ", res[i][j]);
        }
        printf("]\r\n");
    }
}

/**
 * 【58. 区间和】
 * 为避免重复计算，将“区间和”转换为“积分减”
 */
void Solution::interval_sum(void){
    int num = 0;
    std::cin >> num;

    std::vector<int> arr(num, 0);
    for(int i=0; i<num; i++){
        std::cin >> arr[i];
    }

    // 为了避免每次都累加计算，一次性对vector进行累加
    std::vector<int> arr_sum(num, 0);
    arr_sum[0] = arr[0];
    for(int i=1; i<num; i++){
        arr_sum[i] = arr_sum[i-1] + arr[i];
    }

    int a=0, b=0, res=0;
    while(std::cin >> a >> b){  // 分别输入给a和b
        if(a <= b){
            if(a == 0)  res = arr_sum[b];
            else        res = arr_sum[b] - arr_sum[a-1]; 
            std::cout << res << "\r\n";
        }
    }
}

/**
 * 【44. 开发商购买土地】
 */
void Solution::purchase_land(void){
    int n=0, m=0;       // n 行 m 列
    std::cin >> n >> m;
    std::vector<std::vector<int>> land(n, std::vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cin >> land[i][j];
        }
    }

    std::vector<int> line_sum(n, 0);
    std::vector<int> row_sum(m, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            line_sum[i] += land[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            row_sum[i] += land[j][i];
        }
    }

    int value_1=0, value_2=0, dif_value=0;
    int index_1=0, index_2=n-1;
    // 行划分
    while(index_1 <= index_2){
        if(value_1 <= value_2){
            value_1 += line_sum[index_1++];
        }
        else{
            value_2 += line_sum[index_2--];
        }
    }
    dif_value = abs(value_1 - value_2);
    std::cout << dif_value << "\r\n";

    // 竖划分
    index_1=0, index_2=m-1;
    value_1 = 0;
    value_2 = 0;
    while(index_1 <= index_2){
        if(value_1 <= value_2){
            value_1 += row_sum[index_1++];
        }
        else{
            value_2 += row_sum[index_2--];
        }
    }
    std::cout << dif_value << "\r\n";

    dif_value = (abs(value_1 - value_2) < dif_value)?abs(value_1 - value_2):dif_value;
    std::cout << dif_value;
}
 
