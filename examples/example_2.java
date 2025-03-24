class FactorialCalculator {

    int factorial(int n) {

        print("Factorial");
        print(n);

        if (n <= 1) {
            print("VERDADERO");
            print(n);
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }

    int main() {
        int n;
        int resultado;
        n = 5;

        resultado = factorial(n);

        print("Resultado: ");
        print(resultado);
        print("Fin");
        return 0;
    }
}
