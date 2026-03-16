void QuickSort(int array[], int n) {
    int pivotPosition;
    if (n <= 1) return;
    pivotPosition = Partition(array, n);
    QuickSort(array, pivotPosition);
    QuickSort(array + PivotPosition + 1, n–PivotPosition–1);
}