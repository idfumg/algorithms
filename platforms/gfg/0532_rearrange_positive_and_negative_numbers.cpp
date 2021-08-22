#include "../../template.hpp"

void merge(vi& arr, vi& aux, int low, int mid, int high) {
    int k = low;

    for (int i = low; i <= mid; ++i) {
        if (arr[i] < 0) {
            aux[k++] = arr[i];
        }
    }
    for (int i = mid + 1; i <= high; ++i) {
        if (arr[i] < 0) {
            aux[k++] = arr[i];
        }
    }
    for (int i = low; i <= mid; ++i) {
        if (arr[i] >= 0) {
            aux[k++] = arr[i];
        }
    }
    for (int i = mid + 1; i <= high; ++i) {
        if (arr[i] >= 0) {
            aux[k++] = arr[i];
        }
    }
    for (int i = low; i <= high; ++i) {
        arr[i] = aux[i];
    }
}

void partition(vi& arr, vi& aux, int low, int high) {
    if (low >= high) return;
    const int mid = low + (high - low) / 2;
    partition(arr, aux, low, mid);
    partition(arr, aux, mid + 1, high);
    merge(arr, aux, low, mid, high);
}

vi sol(vi arr) {
    const int n = arr.size();
    vi aux(n);
    partition(arr, aux, 0, n - 1);
    return arr;
}

int main() { TimeMeasure _; __x();
    cout << sol({12,11,-13,-5,6,-7,5,-3,-6}) << endl; // -13 -5 -7 -3 -6 12 11 6 5
}
