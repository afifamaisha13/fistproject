public class MergeSort {
    public static void divide(int arr[], int st, int end) {
        if (st >= end) {
            return;
        }
        int mid = st + (end - st) / 2; 
        divide(arr, st, mid);
        divide(arr, mid + 1, end);
        conquer(arr, st, mid, end);
    }

    public static void conquer(int arr[], int st, int mid, int end) {
        int ind1 = st;
        int ind2 = mid + 1;
        int c = 0;
        int merge[] = new int[end - st + 1];

        while (ind1 <= mid && ind2 <= end) {
            if (arr[ind1] <= arr[ind2]) {
                merge[c++] = arr[ind1++];
            } else {
                merge[c++] = arr[ind2++];
            }
        }

        while (ind1 <= mid) {
            merge[c++] = arr[ind1++];
        }

        while (ind2 <= end) {
            merge[c++] = arr[ind2++];
        }

       
        for (int i = 0; i < merge.length; i++) {
            arr[st + i] = merge[i];
        }
    }

    public static void main(String[] args) {
        int arr[] = {7, 3, 6, 2, 10, 13, 5};
        int n = arr.length;
        divide(arr, 0, n - 1);

        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
