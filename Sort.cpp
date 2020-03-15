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

//���һ��string�������ַ���ɵ��Ӽ�
//int main() {
//    listPermutationsOf("ABC");
//    return 0;
//}

//ð������(ƽ��n^2�����n�����n^2, �ռ�1, �ȶ�)
//���������ڵ������Ƚϣ����ֵ���ұߣ�С�ķ���ߣ�����λ�ã�
//��һ�α������������ұ߾�����������Դ����ƣ��ڶ��α����������ڶ���������ұߵ����ڶ���λ��
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

//��������(ƽ��n^2�����n�����n^2, �ռ�1, �ȶ�)
//���������˼���Ǵӵڶ�������ʼѭ����ÿ��ѭ�����������ǰ�����������бȽϣ������ǰ����С�Ļ��Ͱ�
//������ƶ���ǰ��ȥ�����������鱾�������Ѿ�����õģ���ô���ӶȾ���O(N)��
//��ð���������(ÿ����Ҫ���θ�ֵ)�����������Ԥ���µ�ǰ��Ҫ���������
//��ǰ����������ƶ�ʱֻ��Ҫһ�Σ����Ը�ֵЧ�ʸ���
void InsertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {    //������ڵ�ǰ��һ�����ں���һ������,�Ŵ���
            int temp = arr[i];
            int j = i - 1;
            for (j = i - 1; j >= 0 && temp < arr[j]; j--) {  //���ǰ����ں���
                arr[j + 1] = arr[j];    //��ǰ�����Ǹ�j��������j+1
            }
            //jһֱ��С��ֱ����С��ֵ���뵽��ǰ��
            arr[j + 1] = temp;
        }
    }
}



//ѡ������(ƽ���������n^2���ռ�1�����ȶ�)
//������һ�飬����С�ķ�����������ߣ������ڶ����ʣ�µ�Ԫ�رȽϣ��ѵڶ�С�ķ���ߵڶ�λ���Դ�����
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

//����main
//int main() {
//    int myarr[8] = { 20, 3 ,5,-1,2,4,5,1 };
//    InsertSort(myarr, 8);
//    for (int i = 0; i < 8; i++) {
//        cout << myarr[i] << " ";
//    }
//    cout << endl;
//    return 0;
//}

//�鲢����MergeSort(ƽ���������nlog(n)���ռ�O(n),�ȶ�)
//���εݹ��˼�룺�Ѵ�����һ��Ϊ����С���飬ͨ���ݹ�ֿ�����Ȼ��С���������ϲ�������
//����γ�����õĴ�����

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

//��������(ƽ��nlogn�����nlogn�����n^2���ռ�nlogn�����ȶ�)
//��ʼѡ��һ��ê����ֵ(�����еĵ�һ��)��Ȼ���С�����ķ���ߣ����ڵķ��ұ�;
//�����������һ������Ȼ�����������������ֱ���õݹ飻
//����+�ݹ��˼��

/*
��ˣ����ǿ��Եõ�����Ľ��ۣ�����׼��ѡ������ߵ�����ʱ����ô��Ӧ���ȴ��ұ߿�ʼ������
����׼��ѡ�����ұߵ�����ʱ����ô��Ӧ���ȴ���߿�ʼ�����������Ǵ�С���������ǴӴ�С����

��������֮���ȽϿ죬��Ϊ���ð������ÿ�ν�������Ծʽ�ġ�ÿ�������ʱ������һ����׼�㣬
��С�ڵ��ڻ�׼�����ȫ���ŵ���׼�����ߣ������ڵ��ڻ�׼�����ȫ���ŵ���׼����ұߡ�
������ÿ�ν�����ʱ��Ͳ�����ð������һ��ÿ��ֻ�������ڵ���֮����н����������ľ���ʹ�Ķ��ˡ�
����ܵıȽϺͽ������������ˣ��ٶ���Ȼ������ˡ���Ȼ���������£��Կ��������ڵ������������˽�����
��˿�����������ʱ�临�ӶȺ�ð��������һ���Ķ���O(N2)������ƽ��ʱ�临�Ӷ�ΪO(NlogN)��
*/


void QuickSort(vector<int>& arr, int leftIdx, int rightIdx) {
    /*
    arr--�����������
    leftIdx--�����λ��==0
    rightIdx--���ұ�λ��==arr.size()-1
    */
    if (leftIdx >= rightIdx) {
        return;
    }
    int i = leftIdx;
    int j = rightIdx;
    int pivot = arr[leftIdx];
    while (i < j) {
        //ê����ѡ������ߣ�һ��Ҫ���ұ߿�ʼ����
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
    //��pivot�ŵ�ê�����λ����
    arr[leftIdx] = arr[i];
    arr[i] = pivot;

    QuickSort(arr, leftIdx, i - 1);
    QuickSort(arr, i + 1, rightIdx);
}

//��������main
//int main() {
//    vector<int> myarr = { 20, 3 ,5,-1,2,4,5,1 };
//    QuickSort(myarr, 0, 7);
//    for (int i = 0; i < 8; i++) {
//        cout << myarr[i] <<" ";
//    }
//    cout << endl;
//    return 0;
//}