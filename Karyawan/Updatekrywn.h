#ifndef UPDATEKRYWN_H
#define UPDATEKRYWN_H

#include "Global.h"

void TampilUpdate() {
    DrawText("EDIT DATA", 800, 50, 40, WHITE);
    
    if(IsKeyPressed(KEY_DOWN)) panah++;
    if(IsKeyPressed(KEY_UP)) panah--;
    if(panah > 5) panah = 0; if(panah < 0) panah = 5;

    if(panah==0) InputTeks(tempID, 9);
    if(panah==1) InputTeks(tempNama, 49);
    if(panah==2) InputTeks(tempJab, 19);
    if(panah==3) InputTeks(tempPass, 19);

    if(IsKeyPressed(KEY_ENTER)) {
        if(panah==4) {
            int ketemu = 0;
            for(int i=0; i<jumlahKaryawan; i++) {
                if(strcmp(dataKaryawan[i].id, tempID) == 0) {
                    if(strlen(tempNama)>0) strcpy(dataKaryawan[i].nama, tempNama);
                    if(strlen(tempJab)>0) strcpy(dataKaryawan[i].jabatan, tempJab);
                    if(strlen(tempPass)>0) strcpy(dataKaryawan[i].password, tempPass);
                    ketemu = 1;
                }
            }
            if(ketemu) {
                Simpan();
                strcpy(pesan, "Sukses Edit!");
                tempID[0]='\0'; tempNama[0]='\0'; tempJab[0]='\0'; tempPass[0]='\0';
            } else strcpy(pesan, "ID Tidak Ada!");
        }
        else if (panah == 5) {
            menuAktif = 0; panah = 0; pesan[0]='\0';
        }
    }

    int x = 800;
    
    DrawText("ID Target:", x, 120, 20, WHITE);
    DrawRectangleLines(x, 150, 300, 40, (panah==0)?YELLOW:WHITE);
    DrawText(tempID, x+10, 160, 20, WHITE);

    DrawText("Nama Baru:", x, 210, 20, WHITE);
    DrawRectangleLines(x, 240, 300, 40, (panah==1)?YELLOW:WHITE);
    DrawText(tempNama, x+10, 250, 20, WHITE);

    DrawText("Jabatan Baru:", x, 300, 20, WHITE);
    DrawRectangleLines(x, 330, 300, 40, (panah==2)?YELLOW:WHITE);
    DrawText(tempJab, x+10, 340, 20, WHITE);

    DrawText("Pass Baru:", x, 390, 20, WHITE);
    DrawRectangleLines(x, 420, 300, 40, (panah==3)?YELLOW:WHITE);
    DrawText(tempPass, x+10, 430, 20, WHITE);

    if(panah==4) DrawRectangle(x, 490, 300, 50, WHITE);
    else DrawRectangleLines(x, 490, 300, 50, WHITE);
    DrawText("UPDATE", x+110, 505, 20, (panah==4)?PURPLE:WHITE);


    if(panah==5) DrawRectangle(x, 560, 300, 50, RED);
    else DrawRectangleLines(x, 560, 300, 50, RED);
    DrawText("KEMBALI", x+100, 575, 20, WHITE);

    DrawText(pesan, x, 620, 20, GREEN);
}

#endif