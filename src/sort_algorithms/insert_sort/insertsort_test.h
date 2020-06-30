//
//  insertsort_test.h
//  cpp-_Implementation_Of_Introduction_to_Algorithms
//
//  Created by 兆吉 王 on 2020/6/30.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#ifndef insertsort_test_h
#define insertsort_test_h

#include <gtest/gtest.h>
#include "insertsort.h"
using IntroductionToAlgorithm::SortAlgorithm::insert_sort;
//!insert_sort_test：测试C数组的插入排序
/*!
*
* 四组数组： 增序排列、降序排列、有重复数字、单元素的数组
* 参考函数： std::sort()函数
*/
TEST(test_insert_sort, test_C_array)
{
    int data1[10]={1,2,3,4,5,6,7,8,9,10};
    int data2[10]={10,9,8,7,6,5,4,3,2,1};
    int data3[10]={5,5,5,5,5,4,4,4,4,4};
    int data4[1]={5};
    int comparedata1[10]={1,2,3,4,5,6,7,8,9,10};
    int comparedata2[10]={10,9,8,7,6,5,4,3,2,1};
    int comparedata3[10]={5,5,5,5,5,4,4,4,4,4};
    int comparedata4[1]={5};

    std::sort(comparedata1,comparedata1+10);
    insert_sort(data1+0,data1+10);
    std::sort(comparedata2,comparedata2+10);
    insert_sort(data2+0,data2+10);
    std::sort(comparedata3,comparedata3+10);
    insert_sort(data3+0,data3+10);
    std::sort(comparedata4,comparedata4+1);
    insert_sort(data4+0,data4+1);
    EXPECT_EQ(std::vector<int>(data1,data1+10),std::vector<int>(comparedata1,comparedata1+10));
    EXPECT_EQ(std::vector<int>(data2,data2+10),std::vector<int>(comparedata2,comparedata2+10));
    EXPECT_EQ(std::vector<int>(data3,data3+10),std::vector<int>(comparedata3,comparedata3+10));
    EXPECT_EQ(std::vector<int>(data4,data4+1),std::vector<int>(comparedata4,comparedata4+1));
}

//!insert_sort_test：测试std::array的插入排序
/*!
*
* 四组std::array： 增序排列、降序排列、有重复数字、单元素的std::array
* 参考函数： std::sort()函数
*/
TEST(test_insert_sort, test_std_container)
{
    std::vector<int> data1={1,2,3,4,5,6,7,8,9,10};
    std::vector<int> data2={10,9,8,7,6,5,4,3,2,1};
    std::vector<int> data3={5,5,5,5,5,4,4,4,4,4};
    std::vector<int> data4={5};
    std::vector<int> comparedata1={1,2,3,4,5,6,7,8,9,10};
    std::vector<int> comparedata2={10,9,8,7,6,5,4,3,2,1};
    std::vector<int> comparedata3={5,5,5,5,5,4,4,4,4,4};
    std::vector<int> comparedata4={5};

    std::sort(comparedata1.begin(),comparedata1.end());
    insert_sort(data1.begin(),data1.end());
    std::sort(comparedata2.begin(),comparedata2.end());
    insert_sort(data2.begin(),data2.end());
    std::sort(comparedata3.begin(),comparedata3.end());
    insert_sort(data3.begin(),data3.end());
    std::sort(comparedata4.begin(),comparedata4.end());
    insert_sort(data4.begin(),data4.end());
    EXPECT_EQ(data1,comparedata1);
    EXPECT_EQ(data2,comparedata2);
    EXPECT_EQ(data3,comparedata3);
    EXPECT_EQ(data4,comparedata4);
}

#endif /* insertsort_test_h */
