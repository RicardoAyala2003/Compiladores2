class PrimeChecker {
    int isPrime(int num) {
        int i;
        if (num <= 0) {
            return 0;
        }

        i = 2;
        while (i < num) {
            if (num % i == 0) {
                return 0;
            }
            i = i + 1;
        }
        return 1;

    }

    int main() {
        int num;
        int result;
        num = 7;
        result = isPrime(num);
        print("respuesta: ");
        print(result);
        return 0;
    }
}