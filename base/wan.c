#include <stdio.h>

int main() {
    int jenisKendaraan;
    int jamMasuk, menitMasuk;
    int jamKeluar, menitKeluar;
    int totalMenitMasuk, totalMenitKeluar, selisihMenit;
    int durasiJam;
    long biayaPerJam = 0, totalBiaya = 0;

    // Header Program
    printf("========================================\n");
    printf("      PROGRAM PERHITUNGAN BIAYA PARKIR  \n");
    printf("========================================\n");
    
    // Input Jenis Kendaraan
    printf("Pilih Jenis Kendaraan:\n");
    printf("1. Motor (Rp 2.000 / jam)\n");
    printf("2. Mobil (Rp 5.000 / jam)\n");
    printf("Masukkan pilihan (1/2): ");
    scanf("%d", &jenisKendaraan);

    // Validasi Pilihan
    if (jenisKendaraan != 1 && jenisKendaraan != 2) {
        printf("\nPilihan tidak valid! Program dihentikan.\n");
        return 1;
    }

    // Input Waktu Masuk
    printf("Masukkan Jam Masuk (format: jam menit): ");
    scanf("%d %d", &jamMasuk, &menitMasuk);

    // Input Waktu Keluar
    printf("Masukkan Jam Keluar (format: jam menit): ");
    scanf("%d %d", &jamKeluar, &menitKeluar);

    // Proses Konversi Waktu ke Menit
    totalMenitMasuk = (jamMasuk * 60) + menitMasuk;
    totalMenitKeluar = (jamKeluar * 60) + menitKeluar;

    // Antisipasi jika kendaraan keluar pada hari berikutnya (lewat tengah malam)
    if (totalMenitKeluar < totalMenitMasuk) {
        totalMenitKeluar += (24 * 60);
    }

    // Hitung selisih durasi dalam menit
    selisihMenit = totalMenitKeluar - totalMenitMasuk;

    // Konversi durasi ke jam (pembulatan ke atas jika ada kelebihan menit)
    durasiJam = selisihMenit / 60;
    if (selisihMenit % 60 != 0) {
        durasiJam += 1;
    }
    // Minimal durasi parkir dihitung 1 jam
    if (durasiJam == 0) {
        durasiJam = 1;
    }

    // Menentukan tarif per jam berdasarkan jenis kendaraan
    if (jenisKendaraan == 1) {
        biayaPerJam = 2000;
    } else {
        biayaPerJam = 5000;
    }

    // Menghitung total biaya
    totalBiaya = durasiJam * biayaPerJam;

    // Output / Cetak Struk Hasil Perhitungan
    printf("\n========================================\n");
    printf("            STRUK BIAYA PARKIR          \n");
    printf("========================================\n");
    printf("Jenis Kendaraan : %s\n", (jenisKendaraan == 1) ? "Motor" : "Mobil");
    printf("Waktu Masuk     : %02d:%02d\n", jamMasuk, menitMasuk);
    printf("Waktu Keluar    : %02d:%02d\n", jamKeluar, menitKeluar);
    printf("Durasi Parkir   : %d jam (%d menit)\n", durasiJam, selisihMenit);
    printf("Tarif per Jam   : Rp %ld\n", biayaPerJam);
    printf("----------------------------------------\n");
    printf("TOTAL BIAYA     : Rp %ld\n", totalBiaya);
    printf("========================================\n");
    printf("Terima kasih atas kunjungan Anda!\n");

    return 0;
}