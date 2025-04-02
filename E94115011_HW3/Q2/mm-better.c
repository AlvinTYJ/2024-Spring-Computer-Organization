void transpose(int *b, int *b_t, int k, int j) {
    for (int x = 0; x < k; x++) {
        for (int y = 0; y < j; y++) {
            b_t[y * k + x] = b[x * j + y];
        }
    }
}

void matrix_multiplication(int *a, int *b, int *output, int i, int k, int j) {
    int b_t[j * k];
    transpose(b, b_t, k, j);

    for (int x = 0; x < i; x++) {
        for (int y = 0; y < j; y++) {
            int sum = 0;
            for (int z = 0; z < k; z++) {
                sum += a[x * k + z] * b_t[y * k + z];
            }
            output[x * j + y] = sum;
        }
    }
}