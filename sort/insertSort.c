#include <stdio.h>

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

int insertSort(int *array, int length)
{
    int ret = 0;
    int num = 0;
    for (int pos = 1; pos < length; pos++)
    {
        num = array[pos];
        for (int idx = pos; idx >= 0; idx--)
        {
            if (array[idx - 1] > num)
            {
                array[idx] = array[idx - 1];
            }
            else
            {
                array[idx] = num;
                break;
            }
        }
    }
    return ret = 0;
}

/*优化2*/
int insertSort1(int *array, int length)
{
    int ret = 0;
    int copyNum = 0;
    int cur = 0;
    for (int idx = 1; idx < length; idx++)
    {
        cur = idx;
        copyNum = array[idx];
        while (cur > 0 && copyNum < array[cur - 1])
        {
            array[cur] = array[cur - 1];
            cur--;
        }//退出条件是：cur == 0 && copyNum >= array[cur - 1]
        array[cur] = copyNum;
        
    return ret = 0;
}
}
int main()
{
    int array[] = {3, 7, 11, 25, 4, 18};
    int length = sizeof(array) / sizeof(array[0]);

    /*插入排序*/
    // insertSort(array, length);
    insertSort1(array, length);
    printArray(array, length);
    return 0;
}