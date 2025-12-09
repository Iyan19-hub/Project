#ifndef CREATEKRYWN_H
#define CREATEKRYWN_H

#include "Global.h"

void TampilCreate() {
    DrawText("REGISTRASI PEGAWAI", 800, 50, 40, WHITE);
    DrawText("Info Jabatan: ADMIN | MANAGER | KASIR | MERCH", 800, 100, 20, YELLOW);

    if(IsKeyPressed(KEY_DOWN)) panah++;
    if(IsKeyPressed(KEY_UP)) panah--;
    if(panah > 5) panah = 0; if(panah < 0) panah = 5;

    if(panah==0) InputTeks(tempID, 9);
    if(panah==1) InputTeks(tempNama, 49);
    if(panah==2) InputTeks(tempJab, 19); 
    if(panah==3) InputTeks(tempPass, 19);

    if(IsKeyPressed(KEY_ENTER)) {
        if (panah == 4) {
            strcpy(dataKaryawan[jumlahKaryawan].id, tempID);
            strcpy(dataKaryawan[jumlahKaryawan].nama, tempNama);
            strcpy(dataKaryawan[jumlahKaryawan].jabatan, tempJab);
            strcpy(dataKaryawan[jumlahKaryawan].password, tempPass);
            jumlahKaryawan++;
            Simpan();
            
            tempID[0]='\0'; tempNama[0]='\0'; tempJab[0]='\0'; tempPass[0]='\0';
            menuAktif = 0; panah = 0;
        }
        else if (panah == 5) {
            menuAktif = 0; panah = 0;
            tempID[0]='\0'; tempNama[0]='\0'; tempJab[0]='\0'; tempPass[0]='\0';
        }
    }

    int x = 800; 
    
    DrawText("ID:", x, 150, 20, WHITE);
    DrawRectangleLines(x, 180, 300, 40, (panah==0)?YELLOW:WHITE);
    DrawText(tempID, x+10, 190, 20, WHITE);

    DrawText("Nama:", x, 240, 20, WHITE);
    DrawRectangleLines(x, 270, 300, 40, (panah==1)?YELLOW:WHITE);
    DrawText(tempNama, x+10, 280, 20, WHITE);

    DrawText("Jabatan:", x, 330, 20, WHITE);
    DrawRectangleLines(x, 360, 300, 40, (panah==2)?YELLOW:WHITE);
    DrawText(tempJab, x+10, 370, 20, WHITE);

    DrawText("Password:", x, 420, 20, WHITE);
    DrawRectangleLines(x, 450, 300, 40, (panah==3)?YELLOW:WHITE);
    DrawText(tempPass, x+10, 460, 20, WHITE);

    if(panah==4) DrawRectangle(x, 520, 300, 50, WHITE);
    else DrawRectangleLines(x, 520, 300, 50, WHITE);
    DrawText("SIMPAN DATA", x+80, 535, 20, (panah==4)?PURPLE:WHITE);


    if(panah==5) DrawRectangle(x, 580, 300, 50, RED); 
    else DrawRectangleLines(x, 580, 300, 50, RED);
    DrawText("BATAL / KEMBALI", x+60, 595, 20, WHITE);
}

#endif