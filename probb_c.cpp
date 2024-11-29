#include <iostream>
using namespace std;

// Fungsi untuk membaca nilai boolean pada indeks tertentu
bool read(int index) {
    cout << "READ " << index << endl;
    string response;
    cin >> response;
    return response == "true";
}

// Fungsi untuk mencari posisi transisi dari 'true' ke 'false'
void solve(int n) {
    int low = 0, high = n - 1;
    
    // Binary Search
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        // Baca nilai pada posisi mid
        if (read(mid)) {
            // Jika array[mid] adalah 'true', cari di sebelah kanan
            if (!read(mid + 1)) {
                // Jika transisi 'true' ke 'false' ditemukan
                cout << "OUTPUT " << mid << endl;
                return;
            }
            low = mid + 1;
        } else {
            // Jika array[mid] adalah 'false', cari di sebelah kiri
            high = mid - 1;
        }
    }
    
    // Jika loop berhenti, berarti low adalah jawaban
    cout << "OUTPUT " << low << endl;
}

int main() {
    int t;
    cin >> t; // Membaca jumlah test case
    
    while (t--) {
        int n;
        cin >> n; // Membaca panjang array
        solve(n);
    }

    return 0;
}
