int countBits(int num) {
    int count = 0;
    while (num > 0) {
        if (num % 2 == 1) {
            count++;
        }
        num /= 2;
    }
    return count;
}

int solution(int n) {
    int original_count = countBits(n);

    while (true) {
        n++;

        int next_count = countBits(n);

        if (next_count == original_count) {
            return n;
        }
    }
}
