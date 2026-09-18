# Pemrograman_NasywaaKamila_Calcite_TLS26

**Nama Lengkap:** Nasywaa Kamila
**Kelompok:** Calcite
**Kelas/Batch:** TLS26

## Isi Repository

Repository ini berisi hasil pengerjaan Tugas Pemrograman fase 1 dan fase 2.

### Fase 1 — Logika Penyelesaian Masalah
- `Fase1_NasywaaKamila_Calcite_TLS26.pdf`
  Berisi pseudocode, flowchart, dan penjelasan logika (masing-masing minimal 2 paragraf) untuk:
  - **Problem 1: The Last Astronaut** — simulasi Josephus Problem dengan nilai K yang berubah dinamis setiap eliminasi.
  - **Problem 2: Alien-In-The-Middle** — sistem sandi pergeseran huruf berantai berdasarkan nilai huruf sebelumnya.

### Fase 2 — Implementasi C++
- `Problem1_TheLastAstronaut.cpp`
  Program simulasi eliminasi astronot secara melingkar. Menerima input N (jumlah astronot) dan K (nilai eliminasi awal), lalu menampilkan urutan astronot yang dieliminasi serta astronot terakhir yang bertahan.
- `Problem2_AlienInTheMiddle.cpp`
  Program penyandian pesan sesuai sistem sandi pada Problem 2. Menerima input pesan, lalu menampilkan pesan yang telah tersandi.

**Ketentuan implementasi:**
- Hanya menggunakan library `<iostream>`.
- Tidak menggunakan function dari library manapun; seluruh function (menghitung panjang string, mengubah huruf ke kapital, menghapus elemen array, dsb.) dibuat secara manual (user-defined function).

## Cara Menjalankan

```bash
g++ -o problem1 Problem1_TheLastAstronaut.cpp
./problem1

g++ -o problem2 Problem2_AlienInTheMiddle.cpp
./problem2
```
