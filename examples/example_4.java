class RefExample {
    void incrementBy(ref int x, int y) {
        x = x + y;
    }

    void applyIncrements() {
        int values[5];
        int base;
        int i;
        int fa2;
    
  
        base = 0;
       
        fa2 = 5;
       
        i = 0;
        while (i < fa2) {
            incrementBy( base, i);
            
            values[i] = base + i;
            i = i + 1;
        }
        print(fa2);

        
        print(values[0]);
        print(values[1]);
        print(values[2]);
        print(values[3]);
        print(values[4]);

     
    }

    void main() {
        applyIncrements();

    }
}