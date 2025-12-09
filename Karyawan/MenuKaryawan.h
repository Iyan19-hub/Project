#ifndef MENUKARYAWAN_H
#define MENUKARYAWAN_H

#include "Global.h"
#include "Createkrywn.h"
#include "Readkrywn.h"
#include "Updatekrywn.h"
#include "Deletekrywn.h"


void TampilMenuKaryawan() {
    

    int x = 245; 
    int y = 575; 
    int jarak = 70;
    float posisiGaris = 710.0f; 
    int screenW, screenH; 

    DrawText("Karyawan", 245, 500, 30, WHITE); 

 
    if (menuAktif == 0) {
        if(IsKeyPressed(KEY_DOWN)) panah++;
        if(IsKeyPressed(KEY_UP)) panah--;
        if(panah > 4) panah = 0; if(panah < 0) panah = 4;

        if(IsKeyPressed(KEY_ENTER)) {
            if(panah==0) { menuAktif=1; panah=0; } 
            if(panah==1) { menuAktif=2; panah=0; } 
            if(panah==2) { menuAktif=3; panah=0; } 
            if(panah==3) { menuAktif=4; panah=0; } 
            if(panah==4) { 
                statusLogin = 0; 
                menuAktif = 0;   
                panah = 0;
            }
        }
    }

    int sorot = panah;
    if (menuAktif != 0) sorot = -1; 

    
    // Tombol LIHAT (Hijau kalau lagi dibuka)
    Color warna1 = (menuAktif == 1) ? GREEN : PURPLE;
    GambarTombol(0, sorot, "LIHAT DATA", x, y, warna1);
    
    // Tombol TAMBAH
    Color warna2 = (menuAktif == 2) ? GREEN : PURPLE;
    GambarTombol(1, sorot, "TAMBAH DATA", x, y+jarak, warna2);
    
    // Tombol EDIT
    Color warna3 = (menuAktif == 3) ? GREEN : PURPLE;
    GambarTombol(2, sorot, "EDIT DATA", x, y+(jarak*2), warna3);
    
    // Tombol HAPUS
    Color warna4 = (menuAktif == 4) ? GREEN : PURPLE;
    GambarTombol(3, sorot, "HAPUS DATA", x, y+(jarak*3), warna4);
    
    // Tombol LOGOUT
    GambarTombol(4, sorot, "KELUAR / LOGOUT", x, y+(jarak*4), PURPLE);
    
    if (menuAktif == 0) {
        DrawText("SELAMAT DATANG ADMIN", 900, 400, 40, LIGHTGRAY);
        DrawText("Gunakan tombol UP dan DOWN untuk navigasi menu", 900, 450, 20, WHITE);
    }
    else if (menuAktif == 1) TampilRead();
    else if (menuAktif == 2) TampilCreate();
    else if (menuAktif == 3) TampilUpdate();
    else if (menuAktif == 4) TampilDelete();
}

#endif