#include <vector>
#include <iostream>

int ternary_search(std::vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (right - left > 1) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] < arr[mid2]) {
            right = mid2;
        } else {
            left = mid1;
        }
    }

    if (arr[left] < arr[right]) {
        return arr[left];
    } else {
        return arr[right];
    }
}

int main() {
    std::vector<int> arr = {10, 9, 8, 7, 1, 2, 3, 4, 5};
    std::cout << "Минимум массива: " << ternary_search(arr) << std::endl;
    return 0;
}
