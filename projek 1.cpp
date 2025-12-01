#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// ===============================
// Utility input agar tidak error
// ===============================
float inputPositiveFloat(string msg) {
    float x;
    do {
        cout << msg;
        cin >> x;
        if (x < 0) cout << "Input tidak boleh negatif!\n";
    } while (x < 0);
    return x;
}

// ===============================
// Fitur 1 : Kalkulator kebutuhan air
// ===============================
float hitungKebutuhanAir() {
    cout << "=====================================\n";
    cout << "     KALKULATOR KEBUTUHAN AIR\n";
    cout << "=====================================\n";

    float berat = inputPositiveFloat("Masukkan berat badan (kg): ");
    int usia;
    cout << "Masukkan usia: ";
    cin >> usia;
    
    char jk;
    cout << "Jenis kelamin (L/P): ";
    cin >> jk;

    int aktivitas;
    cout << "Tingkat aktivitas (1 = ringan, 2 = sedang, 3 = berat): ";
    cin >> aktivitas;

    float kebutuhan = berat * 0.03; // dasar 30ml/kg

    // Faktor usia
    if (usia < 18) kebutuhan *= 1.05;
    else if (usia > 55) kebutuhan *= 0.95;

    // Faktor gender
    if (jk == 'L' || jk == 'l') kebutuhan *= 1.1;

    // Faktor aktivitas
    if (aktivitas == 2) kebutuhan *= 1.2;
    else if (aktivitas == 3) kebutuhan *= 1.4;

    // Output
    cout << "\nKebutuhan air harianmu: " << kebutuhan << " Liter\n";
    cout << "Kamu disarankan minum sekitar " << kebutuhan << " Liter per hari.\n";

    return kebutuhan;
}

// ===============================
// Fitur 2 : Tracker konsumsi air TANPA LOOPING
// ===============================
float trackerKonsumsi(float kebutuhanAir, float &totalMinum) {
    cout << "\n=====================================\n";
    cout << "       TRACKER KONSUMSI HARIAN\n";
    cout << "=====================================\n";

    totalMinum = inputPositiveFloat("Masukkan total air yang sudah diminum hari ini (L): ");

    float persen = (totalMinum / kebutuhanAir) * 100.0f;
    if (persen > 100) persen = 100;

    cout << "\nTotal minum: " << totalMinum << " L (" << round(persen) << "% dari kebutuhan)\n";
    return totalMinum;
}

// ===============================
// Fitur 3 : Tips harian
// ===============================
void tampilkanTips() {
    cout << "\n=====================================\n";
    cout << "            TIPS HARIAN\n";
    cout << "=====================================\n";

    string tips[] = {
        "Minum air sebelum merasa haus.",
        "Gunakan botol minum yang selalu kamu bawa.",
        "Tambahkan lemon agar lebih segar.",
        "Minum sedikit tapi sering.",
        "Awali hari dengan segelas air hangat."
    };

    int totalTips = sizeof(tips) / sizeof(tips[0]);
    srand(time(NULL));
    int idx = rand() % totalTips;

    cout << "Tips hari ini: " << tips[idx] << "\n";
}

// ===============================
// Fitur 4 : Goal setter
// ===============================
float setGoal() {
    cout << "\n=====================================\n";
    cout << "             GOAL SETTER\n";
    cout << "=====================================\n";

    float goal = inputPositiveFloat("Masukkan target minum harian (L): ");
    cout << "Goal berhasil disimpan: " << goal << " L\n";
    return goal;
}

// ===============================
// Fitur 5 : Reminder visual
// ===============================
void tampilkanReminder(float total, float kebutuhan, float goal) {
    cout << "\n=====================================\n";
    cout << "           REMINDER HARIAN\n";
    cout << "=====================================\n";

    float target = (goal > 0) ? goal : kebutuhan;

    if (total < target * 0.5)
        cout << "? Kamu baru minum kurang dari 50%. Ayo minum lagi!\n";
    else if (total < target)
        cout << "?? Bagus! Tinggal sedikit lagi capai target.\n";
    else
        cout << "?? Kamu sudah mencapai target minum hari ini!\n";
}

// ===============================
// Fitur 6 : Grafik progress
// ===============================
void tampilkanGrafik(float total, float kebutuhan) {
    cout << "\n=====================================\n";
    cout << "           GRAFIK PROGRESS\n";
    cout << "=====================================\n";

    float persen = (total / kebutuhan) * 100.0f;
    if (persen > 100) persen = 100;

    int bar = persen / 5; // max 20 bar

    cout << "[";
    for (int i = 0; i < bar; i++) cout << "=";
    for (int i = bar; i < 20; i++) cout << " ";
    cout << "] " << round(persen) << "%\n";
}

// ===============================
// Fitur 7 : FAQ
// ===============================
void tampilkanFAQ() {
    cout << "\n=====================================\n";
    cout << "                 FAQ\n";
    cout << "=====================================\n";

    string tanya[] = {
        "Berapa banyak air yang harus saya minum?",
        "Apa minuman selain air putih dihitung?",
        "Apakah terlalu banyak minum air berbahaya?"
    };

    string jawab[] = {
        "Umumnya 2–3 liter per hari, tergantung berat badan dan aktivitas.",
        "Minuman lain dihitung, tapi air putih tetap terbaik.",
        "Iya, minum berlebihan bisa menyebabkan hiponatremia."
    };

    for (int i = 0; i < 3; i++) {
        cout << "\nQ: " << tanya[i] << "\n";
        cout << "A: " << jawab[i] << "\n";
    }
}

// ===============================
// PAGE SYSTEM
// ===============================
void pagePause() {
    cout << "\nTekan ENTER untuk lanjut...";
    cin.ignore();
    cin.get();
}

// ===============================
// MAIN
// ===============================
int main() {
    float kebutuhan;
    float totalMinum = 0;
    float goal = 0;

    // PAGE 1 ? INPUT KALKULATOR
    kebutuhan = hitungKebutuhanAir();
    pagePause();

    // PAGE 2 ? TRACKER
    trackerKonsumsi(kebutuhan, totalMinum);
    pagePause();

    // PAGE 3 ? TIPS
    tampilkanTips();
    pagePause();

    // PAGE 4 ? GOAL SETTER
    goal = setGoal();
    pagePause();

    // PAGE 5 ? REMINDER
    tampilkanReminder(totalMinum, kebutuhan, goal);
    pagePause();

    // PAGE 6 ? GRAFIK PROGRESS
    tampilkanGrafik(totalMinum, kebutuhan);
    pagePause();

    // PAGE 7 ? FAQ
    tampilkanFAQ();

    cout << "\nProgram selesai.\n";
    return 0;
}

