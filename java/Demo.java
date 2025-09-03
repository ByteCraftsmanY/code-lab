import java.util.*;

public class Demo {
    public static void main(String[] args) {
        System.out.println("Enter the elements of the array: ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Size of the array is: " + arr.length);
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        for (int num : arr) {
            System.out.println(num);
        }
        sc.close();
    }
}
