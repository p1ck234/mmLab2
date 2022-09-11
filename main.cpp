#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
 {
     int largest = i;
 // Инициализируем наибольший элемент как корень
     int l = 2*i + 1; // левый = 2*i + 1
     int r = 2*i + 2; // правый = 2*i + 2

  // Если левый дочерний элемент больше корня
     if (l < n && arr[l] > arr[largest])
         largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
     if (r < n && arr[r] > arr[largest])
         largest = r;

     // Если самый большой элемент не корень
     if (largest != i)
     {
         swap(arr[i], arr[largest]);

 // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
         heapify(arr, n, largest);
     }
 }
void heapSort(int arr[], int n)
{
  // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

   // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}
int fibMonaccianSearch(int arr[], int x, int n)
{
    /* Инициализировать числа Фибоначчи */
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
   
    /* fibM будет хранить наименьший Фибоначчи
     Число больше или равно n */
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
   
    // Отмечает удаленный диапазон спереди
    int offset = -1;
   
    /* пока есть элементы, подлежащие проверке. Обратите внимание, что
     мы сравниваем arr[fibMm2] с x. Когда fibM становится 1,
     fibMm2 становится 0 */
    while (fibM > 1) {
        // Проверяем, является ли fibMm2 допустимым местоположением
        int i = min(offset + fibMMm2, n - 1);
   
        /* Если x больше, чем значение по индексу fibMm2,
                    вырезать массив подмассива со смещения до i */
        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
   
        /* Если x больше, чем значение по индексу fibMm2,
                    вырезать подмассив после i+1 */
        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
   
        /* элемент найден. возвращаемый индекс */
        else
            return i;
    }
   
    /* сравнение последнего элемента с x */
    if (fibMMm1 && arr[offset + 1] == x)
        return offset + 1;
   
    /* элемент не найден. возврат -1 */
    return -1;
}
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[10]{3,2,5,6,3,1,9,13,11,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 0, temp = 0;
    cout << "x: "; cin >> x;
    
    for(int i = 0; i < n; i++)
    {
        if(x == arr[i])
        {
            temp = i;
        }
    }
    cout << "array is ";
    printArray(arr, n);
    if (temp <= n)
    {
        cout << "number: " << arr[temp] << " index: " << temp << endl;
    }
    else {
        cout << "Unsuccessful search" << endl;
    }
    heapSort(arr, n);
    cout << "Sorted array is ";
    printArray(arr, n);
    cout << "index: " << fibMonaccianSearch(arr, x, n) << endl;
    return 0;
}
