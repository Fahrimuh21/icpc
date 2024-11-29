#include <iostream>
#include <set>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;  // Membaca jumlah kasus uji

    while (test_cases--) {
        long long n;
        cin >> n;  // Membaca panjang array

        long long left = 0, right = n - 1;
        long long last_true_pos = -1;  // Untuk menyimpan posisi true terakhir

        while (left <= right) {
            long long mid = (left + right) / 2;

            // Mengeluarkan perintah untuk membaca nilai di posisi mid
            cout << "READ " << mid << endl;
            string response;
            cin >> response;  // Membaca nilai yang diterima

            if (response == "true") {
                last_true_pos = mid;  // Menyimpan posisi true
                left = mid + 1;  // Mencari lebih kanan
            } else {
                right = mid - 1;  // Mencari lebih kiri
            }

            // Cek apakah ada true yang diikuti false
            if (last_true_pos != -1 && last_true_pos + 1 < n) {
                cout << "READ " << last_true_pos + 1 << endl;  // Cek nilai setelah true
                string next_response;
                cin >> next_response;
                if (next_response == "false") {
                    cout << "OUTPUT " << last_true_pos << endl;  // Menemukan posisi yang diinginkan
                    break;  // Keluar dari loop
                }
            }
        }
    }
    return 0;
}

