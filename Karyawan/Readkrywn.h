#ifndef READKRYWN_H
#define READKRYWN_H

#include "Global.h"

void TampilRead() {
    int x = 750; 

    DrawText("DAFTAR KARYAWAN", x, 50, 40, WHITE);
    
    int y = 120;
    DrawText("ID", x, y, 20, YELLOW);
    DrawText("NAMA", x+100, y, 20, YELLOW);
    DrawText("JABATAN", x+350, y, 20, YELLOW);
    DrawText("PASS", x+550, y, 20, YELLOW);
    DrawLine(x, y+30, 1800, y+30, WHITE);
    y += 40;

    for(int i=0; i<jumlahKaryawan; i++) {
        DrawText(dataKaryawan[i].id, x, y, 20, WHITE);
        DrawText(dataKaryawan[i].nama, x+100, y, 20, WHITE);
        DrawText(dataKaryawan[i].jabatan, x+350, y, 20, GREEN); 
        DrawText(dataKaryawan[i].password, x+550, y, 20, GRAY);
        y += 30;
    }

    if(jumlahKaryawan == 0) DrawText("Data Kosong...", x, 200, 20, GRAY);

    DrawText("[TEKAN BACKSPACE] KEMBALI KE MENU", x, 600, 20, RED);
    
    if(IsKeyPressed(KEY_BACKSPACE)) {
        menuAktif = 0; 
        panah = 0;
    }
}

#endif