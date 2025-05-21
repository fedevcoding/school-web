package parallelsum;

public class Main {

    public static void main(String[] args) {
        int[] numbers = new int[50];

        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = i + 1;
        }

        int numThreads = 5;
        SumTask[] threads = new SumTask[numThreads];

        for (int i = 0; i < numThreads; i++) {
            int start = i * 10;
            int end = start + 10;
            threads[i] = new SumTask(numbers, start, end);
            threads[i].start();
        }

        int totalSum = 0;
        for (int i = 0; i < numThreads; i++) {
            try {
                threads[i].join();
                totalSum += threads[i].getPartialSum();
            } catch (Exception e) {
                System.err.println("Errore durante l'esecuzione del thread: " + e.getMessage());
            }
        }

        System.out.println("La somma totale è: " + totalSum);
    }
}
