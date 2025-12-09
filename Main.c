#include <stdio.h>
#include <raylib.h>
#include <time.h>
#include <string.h>

// --- PANGGIL FILE HEADER ---
#include "Karyawan/MenuKaryawan.h"
#include "Karyawan/Welcome.h" 

int main () {
    // 1. SETUP WINDOW
    InitWindow(800, 600, "Astra Fest System");
    int displayWidth = GetMonitorWidth(0); 
    int displayHeight = GetMonitorHeight(0); 
    SetWindowSize(displayWidth, displayHeight); 
    ToggleFullscreen(); 
    SetTargetFPS(60);     

    // 2. LOAD DATA
    if(jumlahKaryawan == 0) Baca(); 

    // 3. LOAD GAMBAR
    Texture2D logo = LoadTexture("Assets/Logo.png"); 
    
    // Variabel Waktu
    time_t rawtime; 
    struct tm *timeinfo; 
    char textJam[10];

    // Variabel UI
    float posisiGaris = 710.0f; 
    int screenW, screenH; 

    // Variabel Menu Awal
    int menuPilihan = 0; 
    int tombolX = 245; int mulaiY = 575; int lebar= 220; int tinggi = 50; int jarakT = 70; 
    bool apakahMasihJalan = true;

    // Variabel Form Login (LAYAR 1)
    char loginNama[10] = "";
    char loginPass[20] = "";
    int kursorLogin = 0;
    char pesanError[50] = "";

    // --- PENGATUR HALAMAN (ROUTING) ---
    int layar = 0; 
  
    while (!WindowShouldClose() && apakahMasihJalan) {
        // Update Waktu
        time(&rawtime); 
        timeinfo = localtime(&rawtime);
        strftime(textJam, 10, "%H:%M", timeinfo);
        screenW = GetScreenWidth(); 
        screenH = GetScreenHeight(); 

        BeginDrawing();
        ClearBackground(PURPLE); 

        // --- BACKGROUND ASET ---
        DrawTexture(logo, 90, 120, BLACK); DrawTexture(logo, 85, 115, WHITE); 

        // --- LAYAR 0: MENU AWAL ---
        if (layar == 0) {
            DrawLineEx((Vector2){posisiGaris, 0}, (Vector2){posisiGaris, (float)screenH}, 5.0f, WHITE); 
            
            // Reset Data Login
            statusLogin = 0; 
            loginNama[0] = '\0'; loginPass[0] = '\0'; pesanError[0] = '\0';

            if (IsKeyPressed(KEY_DOWN)) { menuPilihan++; } 
            if (menuPilihan > 1) { menuPilihan = 0; } 
            if (IsKeyPressed(KEY_UP)) { menuPilihan--; }           
            if (menuPilihan < 0) { menuPilihan = 1; } 

            if (IsKeyPressed(KEY_ENTER)) {
                if (menuPilihan == 0) {
                    layar = 1; // Ke Form Login
                } 
                else if (menuPilihan == 1) {
                    apakahMasihJalan = false; 
                }
            }

            DrawText("PILIH MENU", 233, 500, 40, WHITE); 
            DrawText("*Tekan ENTER untuk memilih", 210, 900, 20, WHITE);

            // Tombol Login
            if (menuPilihan == 0) { 
                DrawRectangle(tombolX, mulaiY, lebar, tinggi, WHITE); 
                DrawText("LOGIN", tombolX + 85, mulaiY + 15, 20, BLUE);
            } else {
                DrawRectangleLines(tombolX, mulaiY, lebar, tinggi, WHITE); 
                DrawText("LOGIN", tombolX + 85, mulaiY + 15, 20, WHITE);
            }   

            // Tombol Keluar
            if (menuPilihan == 1) { 
                DrawRectangle(tombolX, mulaiY + jarakT, lebar, tinggi, WHITE); 
                DrawText("KELUAR", tombolX + 75, mulaiY + jarakT + 15, 20, BLUE);
            } else {
                DrawRectangleLines(tombolX, mulaiY + jarakT, lebar, tinggi, WHITE);
                DrawText("KELUAR", tombolX + 75, mulaiY + jarakT + 15, 20, WHITE);
            }
        }

        // --- LAYAR 1: FORM LOGIN ---
        else if (layar == 1) {
            DrawLineEx((Vector2){posisiGaris, 0}, (Vector2){posisiGaris, (float)screenH}, 5.0f, WHITE); 
            DrawText("MASUKKAN AKUN", 215, 400, 30, WHITE);

            // Navigasi Atas Bawah
            if (IsKeyPressed(KEY_DOWN)) kursorLogin++; if (kursorLogin > 2) kursorLogin = 0;
            if (IsKeyPressed(KEY_UP)) kursorLogin--; if (kursorLogin < 0) kursorLogin = 2;

            // Input Keyboard
            if (kursorLogin == 0) InputTeks(loginNama, 9);
            if (kursorLogin == 1) InputTeks(loginPass, 19);

            // --- LOGIKA CEK LOGIN (YANG DIPERBAIKI) ---
            if (IsKeyPressed(KEY_ENTER) && kursorLogin == 2) {
                int ketemu = 0;

                // Loop Database
                for (int i = 0; i < jumlahKaryawan; i++) {
                    // Cek ID dan Password
                    // Saya ubah .nama jadi .id agar sesuai dengan variabel 'loginNama'
                    if (strcmp(dataKaryawan[i].nama, loginNama) == 0 && strcmp(dataKaryawan[i].password, loginPass) == 0) {
                        ketemu = 1; 
                        strcpy(userAktif, dataKaryawan[i].nama);
                        strcpy(roleAktif, dataKaryawan[i].jabatan); 
                        break; 
                    }
                }

                if (ketemu) {
                    layar = 2;            
                    pesanError[0] = '\0'; 
                } else {
                    strcpy(pesanError, "ID/Pass Salah!"); 
                }
            }
            // ------------------------------------------

            int formX = 200;
            

            // --- 1. Form Nama ---
            // Posisi Label Y = 500 (Turun jauh)
            DrawText("Nama:", formX, 500, 20, WHITE);
            // Posisi Kotak Y = 525
            DrawRectangleLines(formX, 525, 300, 40, (kursorLogin==0)?YELLOW:WHITE);
            DrawText(loginNama, formX+10, 535, 20, WHITE);

            // --- 2. Form Password ---
            // Posisi Label Y = 580
            DrawText("Password:", formX, 580, 20, WHITE);
            // Posisi Kotak Y = 605
            DrawRectangleLines(formX, 605, 300, 40, (kursorLogin==1)?YELLOW:WHITE);
            
            char bintang[20]=""; 
            for(int i=0; i<strlen(loginPass); i++) bintang[i]='*'; 
            DrawText(bintang, formX+10, 615, 20, WHITE);

            // --- 3. Tombol Masuk ---
            // Posisi Tombol Y = 680
            int tombolY = 680; 
            
            if(kursorLogin==2) DrawRectangle(formX, tombolY, 300, 50, WHITE);
            else DrawRectangleLines(formX, tombolY, 300, 50, WHITE);
            
            DrawText("MASUK", formX+115, tombolY + 15, 20, (kursorLogin==2)?BLUE:WHITE);

            // --- 4. Pesan Error ---
            // Tampil di Y = 740
            DrawText(pesanError, formX, tombolY + 60, 20, RED);
            
            // --- 5. Logika Kembali ---
            if(IsKeyPressed(KEY_BACKSPACE) && strlen(loginNama)==0) layar = 0;
        }

        // --- LAYAR 2: WELCOME ---
        else if (layar == 2) {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), (Color){0,0,0, 200});
            
            int lanjut = TampilWelcome(); 
            
            if (lanjut == 1) {
                statusLogin = 1; 
                menuAktif = 0; panah = 0; 

                if (strcmp(roleAktif, "ADMIN") == 0) layar = 3;
                else if (strcmp(roleAktif, "KASIR") == 0) layar = 4;
                else if (strcmp(roleAktif, "MANAGER") == 0) layar = 5;
                else if (strcmp(roleAktif, "MERCH") == 0) layar = 6;
                else layar = 3; 
            }
        }

        // --- LAYAR 3: DASHBOARD ADMIN ---
        else if (layar == 3) {
            DrawLineEx((Vector2){posisiGaris, 0}, (Vector2){posisiGaris, (float)screenH}, 5.0f, WHITE); 
            TampilMenuKaryawan();
            if (statusLogin == 0) layar = 0; 
        }

        // --- LAYAR 4+: DASHBOARD LAIN ---
        else if (layar >= 4) {
            char *judul = "";
            if(layar==4) judul = "MENU KASIR";
            if(layar==5) judul = "MENU MANAGER";
            if(layar==6) judul = "MENU MERCHANDISE";

            DrawText(judul, 300, 50, 40, WHITE);
            DrawText("Fitur ini belum tersedia.", 250, 300, 30, GRAY);
            DrawText("[ENTER] Logout", 350, 500, 20, RED);
            
            if(IsKeyPressed(KEY_ENTER)) layar = 0; 
        }
        
        // Tampilkan Jam
        DrawText(textJam, screenW - 130, 30, 40, WHITE); 

        EndDrawing();
    }

    UnloadTexture(logo);
    // Disarankan juga unload texture lain untuk mencegah memori bocor
    CloseWindow();  

    return 0;
}