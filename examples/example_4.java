class RefExample {
    void incrementBy(ref int x, int y) {
        x = x + y;
    }

    void applyIncrements() {
        int base;
        int[5] values;
        int i;

        base = 10;
        i = 0;
        while (i < 5) {
            incrementBy(base, i);
            values[i] = base;
            i = i + 1;
        }
        print(values[4]);
    }
}
