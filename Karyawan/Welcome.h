#ifndef WELCOME_H
#define WELCOME_H

#include "Global.h"

// Fungsi ini mengembalikan 1 kalau tombol LANJUT ditekan
int TampilWelcome() {

    // Teks Tengah Layar
    DrawText("LOGIN BERHASIL!", 350, 200, 40, GREEN);
    
    DrawText("Selamat Datang,", 350, 260, 20, WHITE);
    DrawText(userAktif, 350, 290, 50, YELLOW); // Menampilkan nama user
    
    DrawText("Semoga harimu menyenangkan di Astra Fest.", 350, 360, 20, LIGHTGRAY);

    // Tombol Lanjut
    DrawText("TEKAN [ENTER] UNTUK MASUK DASHBOARD", 300, 500, 20, WHITE);

    // Logic Pindah
    if (IsKeyPressed(KEY_ENTER)) {
        return 1; // Kode untuk lanjut ke menu utama
    }
    return 0; // Tetap di sini
}

#endif