//
//  quicksort.h
//  cpp-_Implementation_Of_Introduction_to_Algorithms
//
//  Created by 兆吉 王 on 2020/7/1.
//  Copyright © 2020 兆吉 王. All rights reserved.
//

#ifndef quicksort_h
#define quicksort_h
#include<assert.h>
namespace IntroductionToAlgorithm
{
    namespace SortAlgorithm
    {
    //! partition： 算法导论第7章快速排序中的划分算法
    /*!
     * \param begin : 待划分序列的起始迭代器（也可以是指向数组中某元素的指针）
     * \param end: 待划分序列的终止迭代器（也可以是指向数组中某元素的指针）
     * \param partition_iter: 指定划分元素的对应的迭代器（也可以是指向数组中某元素的指针）
     * \param compare: 一个可调用对象，可用于比较两个对象的小于比较，默认为std::less<T>
     * \return :划分之后该划分元素值在序列中对应的新迭代器（也可以是指向数组中某元素的指针）
     *
     * - 划分思想，假设对数组A[p...r]划分，划分主元为A[q]：
     *   - 交换：首先将A[q]与A[r]交换，使得新的A[r]成为划分元素
     *   - 循环：维持循环不变式： A[p...smaller_next-1]始终小于A[r]，A[smaller_next...current-1]始终大于A[r]。开始对A[current]进行判别：
     *          - 若A[current]<A[r] 则交换 A[current]与 A[smaller_next], current右移（进行下一个元素的判断），smaller_next右移（维持不变式）
     *          - 若A[current]>=A[r], current右移（进行下一个元素的判断）
     * - 时间复杂度 O(n)
     * - 原地操作
    */
        template<typename Iterator,typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type>>
                        Iterator partition(const Iterator begin,const Iterator end,const Iterator partition_iter,CompareType compare=CompareType())
        {
            //typedef typename std::iterator_traits<Iterator>::value_type T;// 迭代器指向对象的值类型
            size_t size = std::distance(begin, end);
            std::swap(*partition_iter,*(end-1));         //将pivot换到最后一位
            Iterator current=begin;
            Iterator smaller_next=begin;
            
            while(current!=end-1){
                if(compare(*current,*(end-1))){
                    std::swap(*smaller_next,*current);
                    smaller_next++;
                }
                current++;
            }
            std::swap(*smaller_next,*(end-1));
            return smaller_next;
        
        }
        //! quick_sort： 算法导论第7章
        /*!
         * \param begin : 待排序序列的起始迭代器（也可以是指向数组中某元素的指针）
         * \param end: 待排序序列的终止迭代器（也可以是指向数组中某元素的指针）
         * \param compare: 一个可调用对象，可用于比较两个对象的小于比较，默认为std::less<T>
         * \return void
         *
         * - 快速排序思想，假设对数组A[p...r]排序：
         *   - 分解：将数组A[p...r]划分为两个（可能为空）的子数组A[p...q-1]个A[q+1...r]，使得A[q]大于前面一个数组中每个元素，小于后面一个数组中每个元素（划分算法见partition算法）
         *   - 解决： 对 A[p...q-1]和A[q+1...r]递归调用快速排序
         * - 最坏时间复杂度 O(n^2)， 期望时间复杂度 O(nlgn)。它平均性能非常好，是实际排序应用中最好的选择
         * - 原地排序
        */
        template<typename Iterator,typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type>>
                        void quick_sort(const Iterator begin,const Iterator end,CompareType compare=CompareType())
        {
            //typedef typename std::iterator_traits<Iterator>::value_type T;// 迭代器指向对象的值类型
            size_t size = std::distance(begin, end);
            if(size<=1) return;
            
            Iterator partition_iter = partition(begin, end, end-1);
            quick_sort(begin, partition_iter);
            quick_sort(partition_iter+1, end);
        }
    }
}

#endif /* quicksort_h */
