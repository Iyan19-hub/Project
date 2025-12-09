#ifndef DELETEKRYWN_H
#define DELETEKRYWN_H

#include "Global.h"

void TampilDelete() {
    DrawText("HAPUS KARYAWAN", 800, 50, 40, RED);

    if(IsKeyPressed(KEY_DOWN)) panah++;
    if(IsKeyPressed(KEY_UP)) panah--;
    if(panah > 2) panah = 0; if(panah < 0) panah = 2;

    if(panah==0) InputTeks(tempID, 9);

    if(IsKeyPressed(KEY_ENTER)) {
        if(panah==1) {
            int hapus = -1;
            for(int i=0; i<jumlahKaryawan; i++) {
                if(strcmp(dataKaryawan[i].id, tempID) == 0) {
                    hapus = i; break;
                }
            }
            if(hapus != -1) {
                for(int i=hapus; i<jumlahKaryawan-1; i++) {
                    dataKaryawan[i] = dataKaryawan[i+1];
                }
                jumlahKaryawan--;
                Simpan();
                strcpy(pesan, "Terhapus!");
                tempID[0] = '\0';
            } else strcpy(pesan, "ID Tidak Ada!");
        }
        else if (panah == 2) {
            menuAktif = 0; panah = 0; pesan[0]='\0';
        }
    }

    int x = 800;
    DrawText("Masukkan ID:", x, 150, 20, WHITE);
    DrawRectangleLines(x, 180, 300, 40, (panah==0)?YELLOW:WHITE);
    DrawText(tempID, x+10, 190, 20, WHITE);

    if(panah==1) DrawRectangle(x, 250, 300, 50, RED);
    else DrawRectangleLines(x, 250, 300, 50, RED);
    DrawText("HAPUS PERMANEN", x+60, 265, 20, WHITE);

    if(panah==2) DrawRectangle(x, 320, 300, 50, WHITE);
    else DrawRectangleLines(x, 320, 300, 50, WHITE);
    DrawText("KEMBALI", x+100, 335, 20, BLUE);

    DrawText(pesan, x, 400, 20, GREEN);
}

#endif