/*
    Problem 1: The Last Astronaut
    Nasywaa Kamila_Calcite - TLS26

    Aturan:
    - Hanya menggunakan library <iostream>
    - Tidak menggunakan function dari library manapun (semua function dibuat manual)

    Logika singkat:
    Ini adalah varian Josephus Problem dengan nilai K yang berubah setiap
    kali terjadi eliminasi:
      - jika nomor yang dieliminasi genap -> K bertambah 2
      - jika nomor yang dieliminasi ganjil -> K berkurang 1
      - K tidak boleh kurang dari 2
    Astronot disimpan dalam array manual. Astronot yang sudah dieliminasi
    "dihapus" dengan menggeser seluruh elemen setelahnya ke kiri, sehingga
    ukuran array yang aktif berkurang satu setiap eliminasi.
*/

#include <iostream>
using namespace std;

const int MAX_N = 1000;

// ---------- Fungsi manual: menghapus elemen pada indeks tertentu ----------
// Menggeser semua elemen setelah idx satu langkah ke kiri.
void hapusElemen(int arr[], int &ukuran, int idx) {
    for (int i = idx; i < ukuran - 1; i++) {
        arr[i] = arr[i + 1];
    }
    ukuran = ukuran - 1;
}

int main() {
    int N, K;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K awal: ";
    cin >> K;

    if (N <= 0 || K <= 0) {
        cout << "N dan K harus bernilai positif." << endl;
        return 0;
    }

    int astronot[MAX_N];
    int ukuran = N;

    // inisialisasi astronot bernomor 1..N
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    int eliminationOrder[MAX_N];
    int jumlahEliminasi = 0;

    int current = 0; // indeks penunjuk posisi awal hitungan saat ini

    while (ukuran > 1) {
        // hitung indeks yang akan dieliminasi
        int idx = (current + K - 1) % ukuran;

        int eliminated = astronot[idx];
        eliminationOrder[jumlahEliminasi] = eliminated;
        jumlahEliminasi = jumlahEliminasi + 1;

        hapusElemen(astronot, ukuran, idx);

        // update nilai K berdasarkan paritas nomor yang dieliminasi
        if (eliminated % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }
        if (K < 2) {
            K = 2;
        }

        // update posisi awal hitungan berikutnya
        if (ukuran > 0) {
            current = idx % ukuran;
        }
    }

    cout << "\nUrutan astronot yang dieliminasi:" << endl;
    for (int i = 0; i < jumlahEliminasi; i++) {
        cout << eliminationOrder[i];
        if (i != jumlahEliminasi - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "\nAstronot yang bertahan (survivor): " << astronot[0] << endl;

    return 0;
}
