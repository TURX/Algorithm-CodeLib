import java.util.Arrays;

/**
 * This class implements the following sorting algorithms insertionSort, selectionSort, mergeSort,
 * QuickSort
 * 
 * @author Mouna AYARI BEN HADJ KACEM
 */
public class QuickSort {
  /**
   * Performs a quick sort on an array of Comparable elements
   * 
   * @param array of comparable elements
   */
  public static <T extends Comparable<T>> void quickSort(T[] array) {
    quickSort(array, 0, array.length - 1); // call the recursive quick sort helper method
  }

  /**
   * Helper method to perform a quick sort that makes recursive calls
   * 
   * @param array of N elements
   * @param leftIndex - left position of the partition of the array to sort
   * @param rightIndex - right position of the partition of the array
   */
  private static <T extends Comparable<T>> void quickSort(T[] array, int leftIndex,
      int rightIndex) {

    if (leftIndex >= rightIndex) {
      return; // Base case: If there are 1 or zero entries to sort, partition is trivially sorted
    }

    // Partition the data within the array. Value index returned from partitioning
    // is the location of the last item in low partition.
    int index = partition(array, leftIndex, rightIndex); // --> O(n)

    // Recursively sort low partition (leftIndex to index) and high partition (index + 1 to
    // rightIndex)

    quickSort(array, leftIndex, index); // recursive call on the low partition to sort small
                                        // elements
    quickSort(array, index + 1, rightIndex); // recursive call on the high partition to sort the
                                             // large elements
  }

  /**
   * Helper method that selects the median of a sub-array as pivot and partitions the data within
   * the array into small and large elements with respect to the pivot
   * 
   * @param array of comparable N items
   * @param leftPos : first index of subarray with respect to the original array
   * @param rightPos: last index of the subarry with respect to the original array
   * @return the index of the last element in the low partition (small elements partition)
   */
  private static <T extends Comparable<T>> int partition(T[] array, int leftPos, int rightPos) {
    int low = leftPos;
    int high = rightPos;
    T temp;

    // Pick middle element as pivot
    int midpointPos = (leftPos + rightPos)/2;
    T pivot = array[midpointPos]; // The middle element is chosen as pivot
    while (low < high) {

      // Increment low while array[low] < pivot
      while (array[low].compareTo(pivot) < 0) {
        low++;
      }

      // Decrement high while pivot < array[high]
      while (pivot.compareTo(array[high]) < 0) {
        high--;
      }

      // If there are zero or one items remaining, all numbers are partitioned. Return high
      if (low < high) {
        // Swap references
        // Swap array[low] and array[high]
        temp = array[low];
        array[low] = array[high];
        array[high] = temp;
        // update low and high
        low++;
        high--;
      }
    }
    return high; // return the index of the last element in the low partition
  }

  public static void main(String[] args) {
    Integer[] data = new Integer[] {24, 12, 2, 18, 8, 34, 22, 6, 40, 30, 32, 16, 36, 14, 8, 38, 10, 28, 26, 20};
    System.out.println("Original array: " + Arrays.toString(data));
    quickSort(data, 0, data.length - 1);
    System.out.println("Quick Sort:     " + Arrays.toString(data));
  }
}
