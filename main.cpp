//
//  main.cpp
//  cpp-_Implementation_Of_Introduction_to_Algorithms
//
//  Created by 兆吉 王 on 2020/6/30.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#include <gtest/gtest.h>
#include "src/sort_algorithms/insert_sort/insertsort_test.h"
#include "src/sort_algorithms/merge_sort/mergesort_test.h"
#include "src/sort_algorithms/quick_sort/quicksort_test.h"
#include "src/sort_algorithms/heap_sort/heapsort_test.h"



int main(int argc,char** argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
