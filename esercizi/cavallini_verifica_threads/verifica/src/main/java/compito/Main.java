package compito;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Scanner per chiedere i valori delle variabili dall'utente

        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Inserisci il numero A: ");
            int a = scanner.nextInt();

            System.out.print("Inserisci il numero B: ");
            int b = scanner.nextInt();

            System.out.print("Inserisci il numero C: ");
            int c = scanner.nextInt();

            // Thread della prima moltiplicazione interna (2a)
            Moltiplicazione mult1 = new Moltiplicazione(2, a);
            Thread mult1T = new Thread(mult1);

            // Thread della seconda moltiplicazione interna (7b)
            Moltiplicazione mult2 = new Moltiplicazione(7, b);
            Thread mult2T = new Thread(mult2);

            // Thread dell'ultima moltiplicazione esterna (10c)
            Moltiplicazione lastMult = new Moltiplicazione(10, c);
            Thread lastMultT = new Thread(lastMult);

            // Run delle 3 moltiplicazioni
            lastMultT.run();
            mult1T.run();
            mult2T.run();
            // Attesa dell'esecuzione delle 3 moltiplicazioni
            try {
                mult1T.join();
                mult2T.join();
                lastMultT.join();
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted unexpectedly");
                System.exit(0);
            }

            System.out.println("Calcolo in corso...");
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted unexpectedly");
                System.exit(0);

            }
            // Stampa dei risultati
            System.out.println("Risultato moltiplicazione 1: " + mult1.getResult());
            System.out.println("Risultato moltiplicazione 2: " + mult2.getResult());
            System.out.println("Risultato ultima moltiplicazione: " + lastMult.getResult());

            // Somma della prima parentesi (2a + 4)
            Somma parentesi1 = new Somma(mult1.getResult(), 4);
            Thread parentesi1T = new Thread(parentesi1);

            // Somma della seconda parentesi (7b + 3)
            Somma parentesi2 = new Somma(mult2.getResult(), 3);
            Thread parentesi2T = new Thread(parentesi2);

            // Run delle 2 somme
            parentesi1T.run();
            parentesi2T.run();
            // Attesa dell'esecuzione delle 2 somme
            try {
                parentesi1T.join();
                parentesi2T.join();
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted unexpectedly");
                System.exit(0);

            }

            System.out.println("Calcolo in corso...");

            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted unexpectedly");
                System.exit(0);
            }

            System.out.println("Risultato parentesi 1: " + parentesi1.getResult());
            System.out.println("Risultato parentesi 2: " + parentesi2.getResult());

            // Moltiplicazione della parentesi quadra [(ris1) * (ris2)]
            Moltiplicazione quadra = new Moltiplicazione(parentesi1.getResult(), parentesi2.getResult());
            Thread quadraT = new Thread(quadra);

            // Run della moltiplicazione
            quadraT.run();
            // Attesa della moltiplicazione
            try {
                quadraT.join();
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted unexpectedly");
                System.exit(0);
            }

            System.out.println("Calcolo in corso...");
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted unexpectedly");
                System.exit(0);
            }
            System.out.println("Risultato parentesi quadra: " + quadra.getResult());

            // Calcolo del risultato finale nel main
            int result = 5 * quadra.getResult() - lastMult.getResult();

            // Stampa del risultato finale
            System.out.println("Calcolo in corso...");
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted unexpectedly");
                System.exit(0);
            }
            System.out.println("Risultato finale: " + result);

        } catch (Exception e) {
            System.out.println("Invalid number");
        }
        // Chiusura dello scanner
        scanner.close();
    }
}
