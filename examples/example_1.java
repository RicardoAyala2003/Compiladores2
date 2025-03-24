class MatrixOperations {

    int matrix[9];

    int getSum() {
        int total;
        int i, j;
        total = 0;
        i = 0;
        while (i < 3) {
            j = 0;
            while (j < 3) {
                total = total + matrix[i * 3 + j];
                j = j + 1;
            }
            i = i + 1;
        }
        return total;
    }

    void initializeMatrix() {
        int i, j;
        i = 0;
        while (i < 3) {
            j = 0;
            while (j < 3) {
                matrix[i * 3 + j] = i * j;
                j = j + 1;
            }
            i = i + 1;
        }

    }

    int main() {
        int result;
        initializeMatrix();

        result = getSum();
        print("resultado");
        print(result);
        return 0;
    }
}