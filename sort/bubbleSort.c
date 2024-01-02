#include <stdio.h>

#define BUFFER_SIZE 6
/*交换两个整数*/
int swap(int *val1, int *val2)
{
    int ret = 0;
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    return ret;
}
/*数组的函数参数会自动弱化为指针*/
int printArray(int *array, int arraySize)
{
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
}
/*时间复杂度:0(n^2)*/
void bubbleSort01(int *array, int length)
{
    for (int end = length; end > 0; end--)
    {
        for (int begin = 1; begin < end; begin++)
        {
            /*后面的数 比 前面的数要小 叫交换*/
            if (array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
            }
        }
    }
}

void bubbleSort02(int *array, int length)
{
    int sorted = 1;
    for (int end = length; end > 0; end--)
    {
        /*已经排好序的标志*/
        sorted = 1;
        for (int begin = 1; begin < end; begin++)
        {
            /*后面的数 比 前面的数要小 叫交换*/
            if (array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
                /*数据是没有排好序的*/
                sorted = 0;
            }
        }
        printf("sorted %d\n", sorted);
        if (sorted == 1)
        {
            break;
        }
    }
}

/*优化2*/
void bubbleSort03(int *array, int length)
{
    int sorted = 1;
    for (int end = length; end > 0; end--)
    {
        int sortedIndex = 1;
        for (int begin = 1; begin < end; begin++)
        {
            /*后面的数 比 前面的数要小 叫交换*/
            if (array[begin] < array[begin - 1])
            {
                swap(&(array[begin]), &(array[begin - 1]));
                /*更新排好序的索引*/
                sortedIndex = begin;
            }
        }
        /*更新*/
        end = sortedIndex;
    }
}
int main()
{
    int array[BUFFER_SIZE] = {2, 1, 3, 7, 50, 60};
    int lenth = sizeof(array) / sizeof(array[0]);

    // bubbleSort01(array, lenth);

    // bubbleSort02(array, lenth);
    bubbleSort03(array, lenth);
    printArray(array, lenth);

    return 0;
}