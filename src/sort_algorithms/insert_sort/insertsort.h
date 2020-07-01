#ifndef insertsort_h
#define insertsort_h


void insert_sort(std::vector<int>::iterator begin,std::vector<int>::iterator end){
    if(std::distance(begin, end)<=1) return;
    auto current=begin+1;
    while(current!=end){
        auto pos=current;
        int current_v=*current;
        while(pos!=begin and *(pos-1) > current_v){
            *pos=*(pos-1);
            pos--;
        }
        *pos=current_v;
        current++;
    }
}


namespace IntroductionToAlgorithm
{
    namespace SortAlgorithm
    {
    //!insert_sort：算法导论第二章 2.1
    /*!
    * \param begin : 待排序序列的起始迭代器（也可以是指向数组中某元素的指针）
    * \param end: 待排序序列的终止迭代器（也可以是指向数组中某元素的指针）
    * \param compare: 一个可调用对象，可用于比较两个对象的小于比较，默认为std::less<T>
    * \return void
    *
    * - 插入排序思想，假设对数组A[p...r]排序：
    *   - 维持不变式：设当前排序的元素是 A[q]，则保持A[p...q-1]为排好的，A[q]在A[p...q-1]中找到它的位置坐下
    * - 时间复杂度 O(n^2)
    * - 原地排序
    */
            template<typename Iterator,typename CompareType=std::less<typename std::iterator_traits<Iterator>::value_type>>
                    void insert_sort(const Iterator begin,const Iterator end,CompareType compare=CompareType()){
             typedef typename std::iterator_traits<Iterator>::value_type T;// 迭代器指向对象的值类型
             size_t size=std::distance(begin, end);
             if(size<=1) return;
             Iterator current=begin;
             while(++current!=end){
                 Iterator insertPosition=current;
                 while(insertPosition!=begin and compare(*current,*(insertPosition-1))){//如果current小于当前的insertPosition的前一个位置
                     insertPosition--;
                 }
                 //此时确定了current值插入的位置；
                 T currentValue=*current;                   //需要记录下current的数值
                 Iterator iter=current;
                 while(iter!=insertPosition){
                     *iter=*(iter-1);                       //依次后移
                     iter--;
                 }
                 *insertPosition = currentValue;
             }
        }
    }
}






#endif /* insertsort_h */
