void quick_sort(int [], int low, int high){
    int pivot;
    if(high>low){
        pivot = partition(A, low, high);
        quick_sort(a, low, pivot-1);
        quick_sort(a, pivot+1, high);
    }
}

int partition(int a, int low, int high){
    int  left, right, pivot_item = a[low];
    left =low;
    right = high;
    while(left<right){
        while(a[left] <= pivot_item)
            left++;
        while(a[right] > pivot_item)
            right++;
        if(left<right)
                swap(a, left, right);
    }
    a[low] = a[right];
    a[right] = pivot_item;
    return item;

    }
}