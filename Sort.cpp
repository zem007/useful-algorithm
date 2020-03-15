/* File: Permutations.cpp
 *
 * Functions to list off all permutations of a collection of elements.
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Given a string of letters we haven't yet considered, along with the partial
 * string built up so far, prints out all permutations that can be made from
 * those characters.
 */
void listPermutationsRec(const string& str, const string& chosen) {
    /* Base case: If we've already committed to every character, then print out
     * the permutation we made.
     */
    if (str == "") {
        cout << chosen << endl;
    }
    /* Recursive case: Some character must come next in the ordering. Try all
     * possible choices of what it can be.
     */
    else {
        for (int i = 0; i < str.size(); i++) {
            /* Form a new string by dropping out the character at this index.
             * Note that getting a substring from an index that's equal to the
             * length of the string is perfectly legal; it just gives back the
             * empty string.
             */
            char ch = str[i];
            string remaining = str.substr(0, i) + str.substr(i + 1);

            listPermutationsRec(remaining, chosen + ch);
        }
    }
}

void listPermutationsOf(const string& str) {
    listPermutationsRec(str, "");
}

//输出一个string的所有字符组成的子集
//int main() {
//    listPermutationsOf("ABC");
//    return 0;
//}

//冒泡排序(平均n^2，最好n，最差n^2, 空间1, 稳定)
//把两个相邻的数作比较，大的值放右边，小的放左边，交换位置；
//第一次遍历下来，最右边就是最大数；以此类推，第二次遍历，倒数第二大的数在右边倒数第二的位置
void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//插入排序(平均n^2，最好n，最差n^2, 空间1, 稳定)
//插入排序的思想是从第二个数开始循环，每轮循环和这个数的前面所有数进行比较，如果比前面数小的话就把
//这个数移动到前面去；如果这个数组本来就是已经排序好的，那么复杂度就是O(N)；
//和冒泡排序相比(每次需要三次赋值)，插入排序会预存下当前需要插入的数，
//将前面的数往后移动时只需要一次，所以赋值效率更高
void InsertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {    //如果相邻的前面一个大于后面一个的数,才触发
            int temp = arr[i];
            int j = i - 1;
            for (j = i - 1; j >= 0 && temp < arr[j]; j--) {  //如果前面大于后面
                arr[j + 1] = arr[j];    //把前面大的那个j赋给后面j+1
            }
            //j一直减小，直到把小的值插入到最前面
            arr[j + 1] = temp;
        }
    }
}



//选择排序(平均最好最差都是n^2，空间1，不稳定)
//遍历第一遍，把最小的放在数组最左边，遍历第二遍和剩下的元素比较，把第二小的放左边第二位；以此类推
void SelectSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minTemp = arr[i];
        int idxMin = i;
        for (int j = i + 1; j < n; j++) {
            if (minTemp > arr[j]) {
                idxMin = j;
                minTemp = arr[j];
            }
        }
        minTemp = arr[idxMin];
        arr[idxMin] = arr[i];
        arr[i] = minTemp;
    }
}

//排序main
//int main() {
//    int myarr[8] = { 20, 3 ,5,-1,2,4,5,1 };
//    InsertSort(myarr, 8);
//    for (int i = 0; i < 8; i++) {
//        cout << myarr[i] << " ";
//    }
//    cout << endl;
//    return 0;
//}

//归并排序MergeSort(平均最好最差都是nlog(n)，空间O(n),稳定)
//分治递归的思想：把大数组一分为二成小数组，通过递归分开处理；然后将小数组两两合并并排序；
//最后形成排序好的大数组

void MergeArray(vector<int>& vec, int left, int mid, int right, vector<int>& temp)
{
    int i = left, j = mid;
    int m = mid + 1, n = right;
    int k = 0;

    while (i <= j && m <= n)
    {
        if (vec[i] <= vec[m])
        {
            temp[k++] = vec[i++];
        }
        else
        {
            temp[k++] = vec[m++];
        }
    }

    while (i <= j)
    {
        temp[k++] = vec[i++];
    }

    while (m <= n)
    {
        temp[k++] = vec[m++];
    }

    for (int i = 0; i < k; i++)
    {
        vec[left + i] = temp[i];
    }
}

void MergeSort(vector<int>& vec, int left, int right, vector<int>& temp)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(vec, left, mid, temp);
        MergeSort(vec, mid + 1, right, temp);
        MergeArray(vec, left, mid, right, temp);
    }
}

//int main() {
//    vector<int> myvet = { 20, 3 ,5,-1,2,4,5,1 };
//    vector<int> temp(8);
//    MergeSort(myvet, 0, 7, temp);
//    for (int i = 0; i < 8; i++) {
//        cout << myvet[i] << " ";
//    }
//    cout << endl;
//    return 0;
//}

//快速排序(平均nlogn，最好nlogn，最差n^2，空间nlogn，不稳定)
//初始选择一个锚定的值(数组中的第一个)，然后把小于他的放左边，大于的放右边;
//这样就完成了一轮排序，然后对左右两个子数组分别调用递归；
//分治+递归的思想

/*
因此，我们可以得到下面的结论：当基准数选择最左边的数字时，那么就应该先从右边开始搜索；
当基准数选择最右边的数字时，那么就应该先从左边开始搜索。不论是从小到大排序还是从大到小排序！

快速排序之所比较快，因为相比冒泡排序，每次交换是跳跃式的。每次排序的时候设置一个基准点，
将小于等于基准点的数全部放到基准点的左边，将大于等于基准点的数全部放到基准点的右边。
这样在每次交换的时候就不会像冒泡排序一样每次只能在相邻的数之间进行交换，交换的距离就大的多了。
因此总的比较和交换次数就少了，速度自然就提高了。当然在最坏的情况下，仍可能是相邻的两个数进行了交换。
因此快速排序的最差时间复杂度和冒泡排序是一样的都是O(N2)，它的平均时间复杂度为O(NlogN)。
*/


void QuickSort(vector<int>& arr, int leftIdx, int rightIdx) {
    /*
    arr--待排序的数组
    leftIdx--最左边位置==0
    rightIdx--最右边位置==arr.size()-1
    */
    if (leftIdx >= rightIdx) {
        return;
    }
    int i = leftIdx;
    int j = rightIdx;
    int pivot = arr[leftIdx];
    while (i < j) {
        //锚定点选择最左边，一定要从右边开始搜索
        while (i < j && arr[j] >= pivot) {
            j--;
        }
        while (i < j && arr[i] <= pivot) {
            i++;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //把pivot放到锚定点的位置上
    arr[leftIdx] = arr[i];
    arr[i] = pivot;

    QuickSort(arr, leftIdx, i - 1);
    QuickSort(arr, i + 1, rightIdx);
}

//快速排序main
//int main() {
//    vector<int> myarr = { 20, 3 ,5,-1,2,4,5,1 };
//    QuickSort(myarr, 0, 7);
//    for (int i = 0; i < 8; i++) {
//        cout << myarr[i] <<" ";
//    }
//    cout << endl;
//    return 0;
//}