#include <iostream>
#include <algorithm>
#include <cstdlib>
#include<ctime>
using namespace std;

void heapify(int A[], int n, int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int large = i;
    if(l < n && A[l] > A[i]){  // jezeli lewe dziecko jest wieksze od zrodla
        large = l;
    }
    if(r < n && A[r] > A[large]){ // jezeli prawe dziecko jest wieksze od zrodla
        large = r;
    }
    if(large != i){ // jezeli najwiekszy nie jest zrodlem
        swap(A[i], A[large]);
        heapify(A, n, large);
    }
}

void buildHeap(int A[], int n){
    for(int i=(n/2)-1;i>=0;i--)
        heapify(A, n, i);
}

void heapSort(int A[], int n){
    buildHeap(A, n);
    for(int i=n-1;i>=0;i--){
        swap(A[0], A[i]);  // zamiana obecnego elementu z koncowym
        heapify(A, i, 0);
    }
}

//####################KOPIEC#######################

void reverseArray(int A[], int p, int r){
    if (p<r){
        swap(A[p], A[r]);
        reverseArray(A, p+1, r-1);
    }
}

//##############ODWROCENIE_TABLICY#################

int Partition(int A[], int p, int r){
    int pivot = A[r];
    int i = p;

    for(int j=p; j<r-1; j++){
        if(A[j] <= pivot){
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[r]);
    return i;
}

void QuickSort(int A[], int p, int r){
    if(p < r){
        int q = Partition(A, p, r);
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }
}

//####################QUICK#######################

void BubbleSort(int A[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(A[j] > A[j+1])
                swap(A[j], A[j+1]);
        }
    }
}

//####################BUBBLE#######################

int main() {
    srand(time(0));
//    int n = (rand() % 900000) + 100000;
    int n = 40000;
    int A[n];
    int B[n];
    int C[n];

    cout << "Wielkosc tablicy: " << n << endl;
    cout << endl;

    clock_t randomNumbersStart = clock();
    for (int i = 0; i < n; i++) {
       int r = (rand() % 30000) + 1;
       A[i] = r;
       B[i] = r;
       C[i] = r;
    }
    clock_t randomNumbersEnd = clock();
    double timeOfRandomizeNumbers = (randomNumbersEnd - randomNumbersStart);

    cout << "Nieposortowane liczby wyznaczono w czasie: " << timeOfRandomizeNumbers << " ms" << endl;

    cout << "###################################################" << endl;
    cout << endl;

    clock_t heapSortStart = clock();
    heapSort(A, n);
    clock_t heapSortEnd = clock();
    double timeOfHeapSortNumbers = (heapSortEnd - heapSortStart);
    cout << "Posortowano liczby KOPCEM w czasie: " << timeOfHeapSortNumbers << " ms" << endl;

    clock_t heapSortStart1 = clock();
    heapSort(A, n);
    clock_t heapSortEnd1 = clock();
    double timeOfHeapSortNumbers1 = (heapSortEnd1 - heapSortStart1);
    cout << "Posortowano posortowane liczby KOPCEM w czasie: " << timeOfHeapSortNumbers1 << " ms" << endl;

    clock_t reverseHeapSortStart = clock();
    reverseArray(A, 0, n-1);
    heapSort(A, n);
    clock_t reverseHeapSortEnd = clock();
    double timeOfReverseHeapSortNumbers = (reverseHeapSortEnd - reverseHeapSortStart);
    cout << "Posortowano odwrocone liczby KOPCEM w czasie: " << timeOfReverseHeapSortNumbers <<  " ms" << endl;

    cout << "###################################################" << endl;
    cout << endl;

    clock_t quickSortStart = clock();
    QuickSort(B, 0, n-1);
    clock_t quickSortEnd = clock();
    double timeOfQuickSortNumbers = (quickSortEnd - quickSortStart);
    cout << "Posortowano liczby QUICKIEM w czasie: " << timeOfQuickSortNumbers << " ms" << endl;

    clock_t quickSortStart1 = clock();
    QuickSort(B, 0, n-1);
    clock_t quickSortEnd1 = clock();
    double timeOfQuickSortNumbers1 = (quickSortEnd1 - quickSortStart1);
    cout << "Posortowano posortowane liczby QUICKIEM w czasie: " << timeOfQuickSortNumbers1 << " ms" << endl;

    clock_t reverseQuickSortStart = clock();
    reverseArray(B, 0, n-1);
    QuickSort(B, 0, n-1);
    clock_t reverseQuickSortEnd = clock();
    double timeOfReverseQuickSortNumbers = (reverseQuickSortEnd - reverseQuickSortStart);
    cout << "Posortowano odwrocone liczby QUICKIEM w czasie: " << timeOfReverseQuickSortNumbers << " ms" << endl;

    cout << "###################################################" << endl;
    cout << endl;


    clock_t bubbleSortStart = clock();
    BubbleSort(C, n);
    clock_t bubbleSortEnd = clock();
    double timeOfBubbleSortNumbers = (bubbleSortEnd - bubbleSortStart);
    cout << "Posortowano liczby BUBBLEM w czasie: " << timeOfBubbleSortNumbers << " ms" << endl;

    clock_t bubbleSortStart1 = clock();
    BubbleSort(C, n);
    clock_t bubbleSortEnd1 = clock();
    double timeOfBubbleSortNumbers1 = (bubbleSortEnd1 - bubbleSortStart1);
    cout << "Posortowano posortowane liczby BUBBLEM w czasie: " << timeOfBubbleSortNumbers1 << " ms" << endl;

    clock_t reverseBubbleSortStart = clock();
    reverseArray(C, 0, n-1);
    BubbleSort(C, n);
    clock_t reverseBubbleSortEnd = clock();
    double timeOfReverseBubbleSortNumbers = (reverseBubbleSortEnd - reverseBubbleSortStart);
    cout << "Posortowano odwrocone liczby BUBBLEM w czasie: " << timeOfReverseBubbleSortNumbers << " ms" << endl;

    cout << "###################################################" << endl;
    cout << endl;

    return 0;
}



//int main() {
//    cout << "TEST DZIALANIA NA MNIEJSZEJ TABLICY = 10" << endl;
//    srand(time(0));
//    int n = 10;
//    int A[n];
//    cout << "Wielkosc tablicy: " << n << endl;
//       cout << "LOSOWO WYGENEROWANE LICZBY: " << '\n';
//    for(int i=0; i<n; i++){
//        A[i] = (rand() % 900000) + 100000;
//        cout << A[i] << '\n';
//    }
//
//    cout << '\n' << "HEAP SORT - POSORTOWANE LICZBY: " << '\n';
//    heapSort(A, n);
//    for(int i=0; i<n; i++){
//        cout << A[i] << '\n';
//    }
//
//    cout << '\n' << "HEAP SORT - ODWROTNIE POSORTOWANE LICZBY: " << '\n';
//    reverseArray(A, 0, n-1);
//    for(int i=0; i<n; i++) {
//        cout << A[i] << '\n';
//    }
//
//    cout << '\n' << "QUICK SORT - POSORTOWANE LICZBY: " << '\n';
//    QuickSort(A, 0, n-1);
//    for(int i=0; i<n; i++){
//        cout << A[i] << '\n';
//    }
//
//    cout << '\n' << "QUICK SORT - ODWROTNIE POSORTOWANE LICZBY: " << '\n';
//    reverseArray(A, 0, n-1);
//      for(int i=0; i<n; i++) {
//          cout << A[i] << '\n';
//      }
//
//    cout << '\n' << "BUBBLE SORT - POSORTOWANE LICZBY: " << '\n';
//    BubbleSort(A, n);
//    for(int i=0; i<n; i++){
//        cout << A[i] << '\n';
//    }
//
//    cout << '\n' << "BUBBLE SORT - ODWROTNIE POSORTOWANE LICZBY: " << '\n';
//    reverseArray(A, 0, n-1);
//    for(int i=0; i<n; i++) {
//        cout << A[i] << '\n';
//    }
//
//    return 0;
//}