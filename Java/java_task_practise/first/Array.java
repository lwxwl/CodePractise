import java.util.Scanner;

public class Array {
    public static void main(String[] args) {
        System.out.println("Please input the amount of members in the array: ");
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int array[] = new int[num];
        System.out.println("Please input the members in the array: ");
        for (int i = 0; i < num; i++) {
            array[i] = scanner.nextInt();
        }
        scanner.close();
        showArray(array);
    }

    public static void showArray(int array[]) {
        for (int i = 0; i < array.length; i++) {
            System.out.printf("%d ", array[i]);
        }
    }

}
