#include <stdio.h>
#include <raylib.h>
#include <time.h>

int main () {
    // Resolusi Layar 
    InitWindow(800, 600, "Astra Fest");
    int displayWidth = GetMonitorWidth(0); // Untuk lebar nya
    int displayHeight = GetMonitorHeight(0); // Untuk Tinggi nya
    SetWindowSize(displayWidth, displayHeight); // nilai nya kosong soalnya cuma buat variabel aja
    ToggleFullscreen(); // Karna kita mau buat full screen layarnya

    // Ini buat ambil PNG nya lalu dibuat jadi variabel
    Texture2D logo = LoadTexture("Assets/Logo.png"); // Gambar akan muncul dalam bentuk 2D
    SetTargetFPS(60);     
    
    // Deklarasi untuk variable/wadah jam
    time_t rawtime; // Ambil waktu mentah
    struct tm *timeinfo; 
    char textJam[10];

    // Deklarasi buat garis
    float posisiGaris = 710.0f; // Posisi garis
    int screenW, screenH; // Untuk tempat ujung atas dan bawah

    // Deklarasi Settingan Menu
    int menuPilihan = 0; // Buat simpen posisi tombol 0=Regis, 1=Login, 2=Exit
    // Posisi dan Ukuran Tombol
    int tombolX = 245; // Posisi Horizontal (kiri kekanan layar dititik 245)
    int mulaiY = 575; // Posisi Vertical (atas kebawah layar dititik 575)
    int lebar= 220; // lebar Kotak
    int tinggi = 50; // Tinggi kotak
    int jarakT = 70; // Jarak antar tombol

    // Deklarasi Tombol Keluar
    bool apakahMasihJalan = true;
  
    // Selama window tidak diclose, looping akan terus berjalan
    while (!WindowShouldClose() && apakahMasihJalan) {

        // Logika Keyboard
        if (IsKeyPressed(KEY_DOWN)) { menuPilihan++; } // Kalau pencet panah bawah bakal ditambah 1
        if (menuPilihan > 1) { menuPilihan = 0; } // Untuk pengaman kalau di ditambah terus bakal dibalikin ke pilihan 0
        if (IsKeyPressed(KEY_UP)) { menuPilihan--; } // Kalau pencet panah atas bakal dikurang 1           
        if (menuPilihan < 0) { menuPilihan = 1; } // Sama ini juga buat pengaman

        // Ini buat garisnya
        screenW = GetScreenWidth(); // Ukurannya di ambil dari resolusi layar di deklarasi (Full Screen)
        screenH = GetScreenHeight(); // begitu juga ini

        // Logika Waktu/Jam
        time(&rawtime); // Mengambil detik saat ini juga dan disimpan ke (rawtime)
        timeinfo = localtime(&rawtime);
        strftime(textJam, 10, "%H:%M", timeinfo); // String Time, ambil jam dan menit dari (time info)

    BeginDrawing();

            // Bagian Background, Logo, dan Tulisan
            ClearBackground(PURPLE); // Setup Background
            DrawTexture(logo, 45, 105, BLACK); // Sebenernya sama aja kayak dibawah, cuma ngide aja biar ada efek 3d nya :v
            DrawTexture(logo, 40, 100, WHITE); // Manggil Logo

            // Tulisan pilih menu
            DrawText("PILIH MENU", 233, 500, 40, WHITE); 
            DrawText("*Tekan ENTER untuk memilih", 210, 900, 20, WHITE);

             // Tombol Login 0
            if (menuPilihan == 0) { // == 0. berarti ini kotak regitrasi
                DrawRectangle(tombolX, mulaiY, lebar, tinggi, WHITE); // Buat kotak untuk pilih atas bawah
                DrawText("LOGIN", tombolX + 85, mulaiY + 15, 20, BLUE);
            } else {
                DrawRectangleLines(tombolX, mulaiY, lebar, tinggi, WHITE); 
                DrawText("LOGIN", tombolX + 85, mulaiY + 15, 20, WHITE);
            }   // Kondisi else, saat kondisi tombol tidak dipilih, pakai rectanglelines (bolong tengahnya/cuma border)

            // Tombol Keluar 1
            if (menuPilihan == 1) { // == 1, kotak login
                DrawRectangle(tombolX, mulaiY + jarakT, lebar, tinggi, WHITE); // mulaiY + jarakT, biar posisi turun 1 tingkat kebawah secara otomatis
                DrawText("KELUAR", tombolX + 75, mulaiY + jarakT + 15, 20, BLUE);
            } else {
                DrawRectangleLines(tombolX, mulaiY + jarakT, lebar, tinggi, WHITE);
                DrawText("KELUAR", tombolX + 75, mulaiY + jarakT + 15, 20, WHITE);
            }

            // Bagian Garis dan Clock/Jam
            DrawLineEx((Vector2){posisiGaris, 0}, (Vector2){posisiGaris, (float)screenH}, 5.0f, WHITE); // Munculin garis
            DrawText(textJam, screenW - 130, 30, 40, WHITE); // Munculin Jam

        EndDrawing();
    }
    CloseWindow();  

    return 0;
}