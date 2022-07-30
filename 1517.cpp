#include <iostream>
#include <vector>

void count_cross(std::vector<int> *arr, int start, int end, long long *result) {
    int i, j, pos, middle;
    std::vector<int> sorted_arr;

    sorted_arr.assign(end-start+1,0);

    i = start; // 왼쪽 배열에 대한 idx
    middle = (start + end)/2;
    j = middle + 1; // 오른쪽 배열에 대한 idx
    pos = start; // 좌우 배열을 정렬하며 정렬된 값의 위치에 대한 idx
    
    while (i <= middle && j <= end) {
        // 오른쪽 배열의 원소가 왼쪽보다 큰 경우에는 정렬된 배열에 왼쪽 원소를 넣고 왼쪽 배열의 idx를 증가
        if (arr->at(i) <= arr->at(j)) {
            sorted_arr[pos - start] = arr->at(i);
            i++;
            pos++;

        // 오른쪽 배열의 원소가 왼쪽보다 작으면 오른쪽 idx의 값이 왼쪽의 i ~ middle 보다 앞으로 가야하므로 result에 해당 값을 추가, 오른쪽 idx 증가
        } else if (arr->at(i) > arr->at(j)) {
            *result += (middle - i + 1);
            sorted_arr[pos - start] = arr->at(j);
            j++;
            pos++;
        }
    }
    
    // 오른쪽, 왼쪽 중 한쪽의 배열이 모두 정렬할 배열에 추가된 경우 남아있는 왼쪽, 오른쪽을 그대로 정렬된 배열에 넣어서 총 정렬을 마무리
    if (i <= middle) {// 오른쪽이 모두 정렬되어 왼쪽이 남아있는 경우
        for (int k = i; k <= middle; k++) {
            sorted_arr[(end - middle) + (k - start)] = arr->at(k);
        }
    } else {// 왼쪽이 모두 정렬되어 오른쪽이 남아있는 경우
        for (int k = j; k <= end; k++) {
            sorted_arr[k - start] = arr->at(k);
        }
    }
    
    // 정렬된 배열을 기존 배열로 이동
    for (int idx = 0; idx <= end - start; idx++) {
        arr->at(start + idx) = sorted_arr[idx];
    }
}

void merge_sort(std::vector<int> *arr, int start, int end, long long *result) {
    if (start < end) {
        int mid;
        mid = (start + end)/2;
        merge_sort(arr, start, mid, result);
        merge_sort(arr, mid+1, end, result);
        count_cross(arr, start, end, result);
    }
}

int main() {
    int N;
    long long result;
    std::vector<int> arr;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        std::cin >> n;
        arr.push_back(n);
    }

    result = 0;
    merge_sort(&arr, 0, N-1, &result);
    std::cout << result;
    return 0;
}