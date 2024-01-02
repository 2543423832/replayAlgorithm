#include <stdio.h>

/* 选择排序：相较于冒泡排序，减少了交换次序*/



/*数组的函数参数会自动弱化为指针*/
int printArray(int *array, int length)
{
    int ret = 0;
    for (int idx = 0; idx < length; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}

int selectSort(int *array, int length)
{
    int ret = 0;
    int minValue = 0;
    int minIndex = 0;
    for (int pos = 0; pos < length; pos++)
    {
        minValue = array[pos];
        for (int begin = pos + 1; begin < length; begin++)
        {
            /*遍历到的元素比最小值要小， 就更新元素*/
            if (minValue > array[begin])
            {
                minValue = array[begin];
                minIndex = begin;
            }
        }
        if (array[pos] > minValue)
        {
            int temp = array[pos];
            array[pos] = minValue;
            array[minIndex] = temp;
        }
        
    }

        return ret = 0;
}
int main()
{
    int array[] = {2, 1, 3, 7, 50, 60};
    int lenth = sizeof(array) / sizeof(array[0]);

    /*选择排序*/
    selectSort(array, lenth);
    printArray(array, lenth);
    return 0;
}