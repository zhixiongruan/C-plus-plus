//
// Created by zhixiong ruan on 2019-06-20.
//

#ifndef SORTING_ALG_SORTINGALG_H
#define SORTING_ALG_SORTINGALG_H
#include <algorithm>
#include <iostream>

template <typename T>
class SortingAlg {
public:
    SortingAlg();
    ~SortingAlg();
    void selectSorting(T arr[], int n);
    void insertSorting(T arr[], int n);
    void bubbleSorting(T arr[], int n);
    void shellSorting(T arr[], int n);

};
/**
 * 构造函数
 * @tparam T
 */
template<typename T>
SortingAlg<T>::SortingAlg() {}
/**
 * 虚构函数
 * @tparam T
 */
template<typename T>
SortingAlg<T>::~SortingAlg() {}

/**
 * 选择排序，从第一个数开始，依次找到当前位置最小值，然后交换；继续下一个寻找
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void SortingAlg<T>::selectSorting(T arr[], int n) {
    for (int i = 0; i < n; i++){
        int k = i;
        for (int j = i + 1; j < n; j++){
            if(arr[j] < arr[k]) {
                k = j;
            }
        }
        std::swap(arr[i], arr[k]);
    }
}

/**
 * 插入排序,相邻两个数比较，大的数排后面，
 * 该排序算法对于那种大部分已经排好序，只有少部分需要排序的数组，
 * 排序速度较快
 * @tparam T
 * @param arr
 * @param n
 */
template <typename T>
void SortingAlg<T>::insertSorting(T arr[], int n) {

    for (int i = 1; i < n; i++){
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--){
                std::swap(arr[j], arr[j - 1]);
        }
    }
}

/**
 * 冒泡排序
 * @tparam T
 * @param arr
 * @param n
 */
template <typename T>
void SortingAlg<T>::bubbleSorting(T arr[], int n) {

    for (int i = 0; i < n - 1; i++){
        bool flag = true;
        for (int j = 1; j < n - i; j++){
            if (arr[j] < arr[j - 1]){
                std::swap(arr[j], arr[j - 1]);
                flag = false;
            }
        }

        if (flag) {
            return;
        }
    }
//    写法2里:
//    bool swapped;
//    do{
//        swapped = false;
//        for( int i = 1 ; i < n ; i ++ )
//            if( arr[i-1] > arr[i] ){
//                swap( arr[i-1] , arr[i] );
//                swapped = true;
//            }
//
//        n --;
//
//    } while (swapped);

}

/**
 * Shell排序可以说是插入排序的升级版，相比较插入排序，
 * Shell排序首先使用大间隔、少元素的插入排序，使得每次移动的数据少，但是移动的跨度大；
 * 然后再使用小间隔，略多数量元素的插入排序，经过上一步插入排序，很多数据已经距离排序位置不远了，
 * 这样第二次插入排序时，需要移动的数据的数量就会减少，
 * 间隔最终减小到1.Shell排序的执行时间依赖于增量序列。
 * 可以理解为分别用逐步减小一定倍数（下面代码为3倍）的步长做插入排序
 * @tparam T
 * @param arr
 * @param n
 */

template <typename T>
void SortingAlg<T>::shellSorting(T arr[], int n) {
    int h = 1;
    while(h > n/3){
        h = h * 3 + 1;
    }
    // h可为：1，4，13，40，121，364...

    while (h >= 1) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && arr[j] < arr[j - h]; j = j - h) {
                std::swap(arr[j], arr[j - h]);
            }
        }
        h = h / 3;
    }
}


#endif //SORTING_ALG_SORTINGALG_H