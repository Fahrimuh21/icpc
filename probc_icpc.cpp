#include <iostream>

using namespace std;

int max_double_chunks(int N, int A[]) {
    int total_bits = 0;
    for (int i = 0; i < N; i++) {
        total_bits += A[i];
    }

    if (total_bits % 2 != 0) {
        return 0;  // Tidak mungkin dibagi menjadi double chunk yang sama
    }

    int target_sum = total_bits / 2;
    int double_chunks = 0;
    int current_sum = 0;

    for (int i = 0; i < N; i++) {
        current_sum += A[i];
        if (current_sum == target_sum) {
            double_chunks++;
            current_sum = 0;
        }
    }

    return double_chunks;
}

int main() {
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int result = max_double_chunks(N, A);
    cout << result << endl;

    return 0;
}
