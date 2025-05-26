#include <iostream>
using namespace std;
 
int sum (int* arr, int n) // 배열과 배열의 크기를 받아 각 요소들의 합을 구하는 함수 
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += arr[i];
    }
    return result;
}

float avg (int sum, int n) // 배열의 총 합과 배열의 크기를 받아 평균을 구하는 함수 
{
    return  (float) sum / n;
}

void ascending_sort (int* arr, int n) // 오름차순 정렬 (크기가 작을 때) - 삽입정렬
{
    for (int i = 1; i < n; i++)
    {
        int piv = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if(arr[piv] < arr[j])
            {
                int tmp = arr[piv];
                arr[piv] = arr[j];
                arr[j] = tmp;
                piv = j;
            } else {
                break;
            }
        }
    }
}

void descending_sort (int* arr, int n) // 내림차순 정렬렬 (크기가 작을 때) - 선택정렬 
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[maxIdx])
            {
                maxIdx = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = tmp;
    }
}

void print_arr (int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    while (1) // n 값이 0 이하가 되지 않도록 설정 
    {
        cout << "입력할 숫자의 개수?: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "0보다 큰 수를 입력해주세요.";
        } else 
        {
            break;
        }
    }


    int* arr = new int[n]; // 크기가 n인 배열 선언

    for (int i = 0; i < n; i++) // n개의 숫자를 입력받아 배열에 저장
    {
        cout << i + 1 << "번째 숫자는?: ";
        cin >> arr[i];
    }

    cout << "배열의 요소들의 총 합은: " << sum(arr, n) << "입니다." << endl;
    cout << "배열의 요소들의 평균값은: " << avg(sum(arr, n), n) << "입니다." << endl;

    ascending_sort(arr, n);
    cout << "배열의 오름차순 정렬: ";
    print_arr(arr, n);
    cout << endl;
    descending_sort(arr, n);
    cout << "배열의 내림차순 정렬: ";
    print_arr(arr, n);
    cout << endl;

    return 0;
}