#ifndef GLOBAL_H
#define GLOBAL_H

#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char id[10];
    char nama[50];
    char jabatan[20];
    char password[20];
} Karyawan;

Karyawan dataKaryawan[100]; 
int jumlahKaryawan = 0;

int statusLogin = 0; 

int menuAktif = 0; 

int panah = 0;        


char tempID[10] = "";
char tempNama[50] = "";
char tempJab[20] = "";
char tempPass[20] = "";
char pesan[50] = "";
char userAktif [50] = "";
char roleAktif [20] = "";

void Simpan() {
    FILE *file = fopen("karyawan.dat", "wb");
    if(file) {
        fwrite(&jumlahKaryawan, sizeof(int), 1, file);
        fwrite(dataKaryawan, sizeof(Karyawan), jumlahKaryawan, file);
        fclose(file);
    }
}


void Baca() {
    FILE *file = fopen("karyawan.dat", "rb");

    if(file) {
        fread(&jumlahKaryawan, sizeof(int), 1, file);
        fread(dataKaryawan, sizeof(Karyawan), jumlahKaryawan, file);
        fclose(file);
    }
}

void InputTeks(char teks[], int batas) {
    int tombol = GetCharPressed();
    int p = strlen(teks);
    while (tombol > 0) {
        if (tombol >= 32 && tombol <= 125 && p < batas) {
            teks[p] = (char)tombol; teks[p+1] = '\0'; p++;
        }
        tombol = GetCharPressed();
    }
    if (IsKeyPressed(KEY_BACKSPACE) && p > 0) teks[--p] = '\0';
}


void GambarTombol(int urutan, int dipilih, char teks[], int x, int y, Color warnaTeks) {
    // Ukuran Kotak
    int lebarKotak = 220;
    int tinggiKotak = 50;

    // Rumus Teks di Tengah
    int lebarTeks = MeasureText(teks, 20); // Hitung panjang tulisan pixel-nya
    int posisiX = x + (lebarKotak - lebarTeks) / 2; // Rumus matematika tengah
    int posisiY = y + 15; // Jarak dari atas

    if (urutan == dipilih) {
        // Kalo dipilih: Kotak Putih Full
        DrawRectangle(x, y, lebarKotak, tinggiKotak, WHITE);
        DrawText(teks, posisiX, posisiY, 20, warnaTeks); 
    } else {
        // Kalo gak dipilih: Kotak Garis doang
        DrawRectangleLines(x, y, lebarKotak, tinggiKotak, WHITE);
        DrawText(teks, posisiX, posisiY, 20, WHITE);
    }
}
#endif