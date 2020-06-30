#ifndef MERGESORTE_H
#define MERGESORTE_H
#include<vector>
namespace IntroductionToAlgorithm
{
    namespace SortAlgorithm
    {

    //! merge：算法导论第二章 2.3.1
    /*!
    * \param begin : begin...middle之间为已排好序列
    * \param end: middle...end之间为已排好序列
    * \param middle: begin...middle之间为已排好序列
    * \param compare: 一个可调用对象，可用于比较两个对象的小于比较，默认为std::less<T>
    * \return void
    *
    * - 归并思想，假设对数组A[p...q...r]归并：
    *   - 拷贝： 创建一个result数组，将A[p...q-1]与A[q...r]双指针比较复制到result中
                如果一个指针到尾，则完全复制另一个数组的其余元素
    *   - 归并： 从左到右依次取L、R中的较小的元素，存放到A中（具体算法见代码）
    * - 时间复杂度 O(n)
    * - 归并时需要额外的空间 O(n)
    */
        template<typename Iterator,typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type>>
                void merge(const Iterator begin,const Iterator end,const Iterator middle,CompareType compare=CompareType())
        {
            typedef typename std::iterator_traits<Iterator>::value_type T;
            std::vector<T> result(begin,end);           //暂存结果
            Iterator left_current=begin;
            Iterator right_current=middle;
            
            auto result_current=result.begin();
            
            while(left_current!=middle and right_current!=end){
                if(compare(*left_current,*right_current)){                  //如果左<右
                    *(result_current++)=*(left_current++);
                }
                else{                                                       //如果右<左
                    *(result_current++)=*(right_current++);
                }
            }
            if(left_current==middle){                                       //如果是左侧到头了，右侧直接复制
                std::copy(right_current,end,result_current);
            }
            else{
                assert(right_current==end);                                 //如果是右侧到头了，左侧直接复制
                std::copy(left_current,middle,result_current);
            }
            
            std::copy(result.begin(),result.end(),begin);
            
        }

    //! merge_sort：算法导论第二章 2.3.1
    /*!
    * \param begin : 待排序序列的起始迭代器（也可以是指向数组中某元素的指针）
    * \param end: 待排序序列的终止迭代器（也可以是指向数组中某元素的指针）
    * \param compare: 一个可调用对象，可用于比较两个对象的小于比较，默认为std::less<T>
    * \return void
    *
    * - 归并排序思想，假设对数组A[p...r]排序：
    *   - 分解：将数组A[p...r]平均划分为2子数组A[p...q-1]个A[q...r]，一直划分直到每个子数组只有1个元素
    *   - 归并： 对 A[p...q-1]和A[q...r]这两个已排序好的数组进行合并
    * - 时间复杂度 O(nlgn)
    * - 非原地排序，归并时需要额外的空间 O(n)
    */
        template<typename Iterator,typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type>>
                    void merge_sort(const Iterator begin,const Iterator end,CompareType compare=CompareType())
        {
            size_t size=std::distance(begin,end);   //如果只有1个元素就跳出
            if(size==1) return;
            Iterator mid=begin+size/2;              //找到中间元素
            merge_sort(begin, mid,compare);       //递归左
            merge_sort(mid,end,compare);            //递归右
            merge(begin,end,mid,compare);           //merge
        }
    }
}
#endif // MERGESORTE_H
