/*
    Problem 2: Alien-In-The-Middle
    Nasywaa Kamila_Calcite - TLS26

    Aturan:
    - Hanya menggunakan library <iostream>
    - Tidak menggunakan function dari library manapun (semua function dibuat manual)

    Logika singkat:
    Setiap huruf digeser sebanyak nilai huruf ASLI tepat sebelumnya
    (A=1, B=2, ..., Z=26). Huruf pertama tidak berubah. Jika hasil
    pergeseran melewati Z, perhitungan kembali dari A (wrap-around),
    yang ditangani dengan rumus:
        nilaiBaru = ((nilaiSekarang + prevValue - 1) % 26) + 1
    Contoh: ALIENS -> AMUNSG
*/

#include <iostream>
using namespace std;

const int MAX_LEN = 1000;

// ---------- Fungsi manual: mengubah huruf kecil menjadi kapital ----------
char keKapital(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

// ---------- Fungsi manual: menghitung panjang string (tanpa strlen) ----------
int panjangString(char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len = len + 1;
    }
    return len;
}

// ---------- Fungsi manual: nilai posisi huruf, A=1 ... Z=26 ----------
int nilaiHuruf(char c) {
    return (c - 'A') + 1;
}

// ---------- Fungsi manual: mengubah nilai posisi menjadi huruf ----------
char hurufDariNilai(int n) {
    return (char)((n - 1) + 'A');
}

int main() {
    char pesan[MAX_LEN];
    char hasil[MAX_LEN];

    cout << "Masukkan pesan (huruf saja): ";
    cin.getline(pesan, MAX_LEN);

    // ubah seluruh huruf menjadi kapital secara manual
    int L = panjangString(pesan);
    for (int i = 0; i < L; i++) {
        pesan[i] = keKapital(pesan[i]);
    }

    if (L == 0) {
        cout << "Pesan tidak boleh kosong." << endl;
        return 0;
    }

    // huruf pertama tidak berubah
    hasil[0] = pesan[0];
    int prevValue = nilaiHuruf(pesan[0]);

    for (int i = 1; i < L; i++) {
        int nilaiSekarang = nilaiHuruf(pesan[i]);
        int nilaiBaru = ((nilaiSekarang + prevValue - 1) % 26) + 1;
        hasil[i] = hurufDariNilai(nilaiBaru);

        // nilai acuan untuk huruf berikutnya harus dari huruf ASLI
        prevValue = nilaiSekarang;
    }
    hasil[L] = '\0';

    cout << "Pesan asli    : " << pesan << endl;
    cout << "Pesan tersandi: " << hasil << endl;

    return 0;
}
