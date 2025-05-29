package compito;

public class Somma implements Runnable {

    private final int n1, n2;
    private int result;

    // Costruttore con assegnazione dei valori
    public Somma(int n1, int n2) {
        this.n1 = n1;
        this.n2 = n2;
    }

    // Getter del risultato
    public int getResult() {
        return this.result;
    }

    // Override con somma dei numeri
    @Override
    public void run() {
        this.result = this.n1 + this.n2;
    }
}
