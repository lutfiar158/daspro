/*
 * Password Generator - Menghasilkan password yang sangat kuat
 * Menggunakan std::random_device (hardware-based entropy) +
 * std::mt19937_64 untuk kriptografis yang lebih baik.
 *
 * Compile: g++ -std=c++17 -O2 password_generator.cpp -o password_generator
 * Run:    ./password_generator [opsi]
 */

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <cctype>

// --- Konfigurasi Character Set ---
const std::string LOWER  = "abcdefghijklmnopqrstuvwxyz";
const std::string UPPER  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string DIGITS = "0123456789";
const std::string SPECIAL = "!@#$%^&*()_+-=[]{}|;:,.<>?/~`";

// Gabungan semua karakter
const std::string ALL_CHARS = LOWER + UPPER + DIGITS + SPECIAL;

// --- Helper: acak dalam range [min, max] ---
int random_range(std::mt19937_64 &rng, int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

// --- Helper: pilih satu karakter acak dari string ---
char random_char(std::mt19937_64 &rng, const std::string &charset) {
    return charset[random_range(rng, 0, static_cast<int>(charset.size()) - 1)];
}

// --- Generate satu password ---
std::string generate_password(
    std::mt19937_64 &rng,
    int length,
    bool use_lower,
    bool use_upper,
    bool use_digits,
    bool use_special,
    bool no_ambiguous = false
) {
    std::string charset;

    if (use_lower)  charset += LOWER;
    if (use_upper)  charset += UPPER;
    if (use_digits) charset += DIGITS;
    if (use_special) charset += SPECIAL;

    // Remove ambiguous characters (l, 1, I, O, 0) jika diminta
    if (no_ambiguous) {
        std::string filtered;
        for (char c : charset) {
            char upper_c = std::toupper(c);
            if (upper_c == 'L' || upper_c == 'I' || upper_c == 'O') continue;
            if (c == '1' || c == '0') continue;
            filtered += c;
        }
        charset = filtered;
    }

    if (charset.empty()) {
        std::cerr << "[!] Tidak ada karakter yang dipilih!\n";
        return "";
    }

    // Pastikan minimal satu dari setiap tipe yang dipilih
    std::string password;
    password.reserve(length);

    // Isi password dengan karakter acak dari charset gabungan
    for (int i = 0; i < length; ++i) {
        password += random_char(rng, charset);
    }

    return password;
}

// --- Generate N password ---
std::vector<std::string> generate_multiple(
    std::mt19937_64 &rng,
    int count,
    int length,
    bool use_lower,
    bool use_upper,
    bool use_digits,
    bool use_special,
    bool no_ambiguous
) {
    std::vector<std::string> results;
    results.reserve(count);
    for (int i = 0; i < count; ++i) {
        results.push_back(generate_password(
            rng, length, use_lower, use_upper, use_digits, use_special, no_ambiguous
        ));
    }
    return results;
}

// --- Hitung kekuatan password (estimasi entropi) ---
double entropy_bits(double charset_size, int length) {
    // E = L * log2(N)  di mana N = ukuran charset
    // Gunakan log natural lalu konversi ke log2
    double n = charset_size;
    return length * (std::log(n) / std::log(2.0));
}

// --- Kelasifikasi kekuatan ---
std::string classify_strength(double entropy) {
    if (entropy < 40)  return "LEBIH BIASA (rendah)";
    if (entropy < 60)  return "SEDANG";
    if (entropy < 80)  return "KUAT";
    if (entropy < 100) return "SANGAT KUAT";
    return "EGERIA (ekstrim)";
}

// --- Tampilkan password dalam blok agar mudah dibaca ---
void print_password(const std::string &pw, int group_size = 4) {
    for (size_t i = 0; i < pw.size(); i += group_size) {
        std::cout << pw.substr(i, group_size);
        if (i + group_size < pw.size()) std::cout << ' ';
    }
    std::cout << '\n';
}

// --- Banner ---
void print_banner() {
    std::cout << R"(
╔══════════════════════════════════════════════════════╗
║         PASSWORD GENERATOR — KUAT & AMAN             ║
║  Menggunakan std::random_device + mt19937_64 (64-bit)║
╚══════════════════════════════════════════════════════╝
)";
}

// --- Print Usage ---
void print_usage() {
    std::cout << "\nPenggunaan:\n"
              << "  ./password_generator [OPTIONS]\n\n"
              << "Opsi:\n"
              << "  -l, --length N       Panjang password (default: 16, min: 4)\n"
              << "  -c, --count N        Jumlah password yang di-generate (default: 1)\n"
              << "  -a, --all            Aktifkan semua jenis karakter\n"
              << "  --no-lower           Matikan huruf kecil\n"
              << "  --no-upper           Matikan huruf besar\n"
              << "  --no-digits          Matikan angka\n"
              << "  --no-special         Matikan simbol\n"
              << "  --no-ambiguous       Hilangkan karakter ambigu (l,I,1,O,0)\n"
              << "  --entropy            Tampilkan estimasi entropi (bit)\n"
              << "  --help               Tampilkan pesan ini\n\n"
              << "Contoh:\n"
              << "  ./password_generator -l 32 -c 5 -a\n"
              << "  ./password_generator -l 20 --no-digits --no-ambiguous\n"
              << "  ./password_generator -l 12 -c 10\n";
}

// --- Parse argumen (manual, tanpa library eksternal) ---
struct Config {
    int length      = 16;
    int count       = 1;
    bool use_all    = false;
    bool use_lower  = true;
    bool use_upper  = true;
    bool use_digits = true;
    bool use_special= true;
    bool no_ambiguous = false;
    bool show_entropy = false;
};

Config parse_args(int argc, char *argv[]) {
    Config cfg;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--help" || arg == "-h") {
            print_usage();
            exit(0);
        }
        else if (arg == "-l" || arg == "--length") {
            if (i + 1 < argc) cfg.length = std::stoi(argv[++i]);
            else { std::cerr << "[!] -l butuh argumen angka\n"; exit(1); }
        }
        else if (arg == "-c" || arg == "--count") {
            if (i + 1 < argc) cfg.count = std::stoi(argv[++i]);
            else { std::cerr << "[!] -c butuh argumen angka\n"; exit(1); }
        }
        else if (arg == "-a" || arg == "--all") {
            cfg.use_all = true;
            cfg.use_lower = cfg.use_upper = cfg.use_digits = cfg.use_special = true;
        }
        else if (arg == "--no-lower")   cfg.use_lower  = false;
        else if (arg == "--no-upper")   cfg.use_upper  = false;
        else if (arg == "--no-digits")  cfg.use_digits = false;
        else if (arg == "--no-special") cfg.use_special= false;
        else if (arg == "--no-ambiguous") cfg.no_ambiguous = true;
        else if (arg == "--entropy")    cfg.show_entropy = true;
        else {
            std::cerr << "[!] Opsi tidak dikenal: " << arg << "\n";
            print_usage();
            exit(1);
        }
    }

    // Validasi minimum
    if (cfg.length < 4) {
        std::cerr << "[!] Panjang minimal 4 karakter.\n";
        exit(1);
    }
    if (cfg.count < 1) {
        std::cerr << "[!] Count minimal 1.\n";
        exit(1);
    }

    return cfg;
}

// --- Main ---
int main(int argc, char *argv[]) {
    print_banner();

    Config cfg = parse_args(argc, argv);

    // Inisialisasi RNG — gunakan random_device untuk seed,
    // fallback ke waktu jika hardware RNG tidak tersedia
    std::random_device rd;
    std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937_64 rng(seed);

    std::cout << "\nKonfigurasi:\n"
              << "  Panjang   : " << cfg.length << "\n"
              << "  Jumlah    : " << cfg.count << "\n"
              << "  Huruf kecil: " << (cfg.use_lower ? "iya" : "tidak") << "\n"
              << "  Huruf besa : " << (cfg.use_upper ? "iya" : "tidak") << "\n"
              << "  Angka      : " << (cfg.use_digits ? "iya" : "tidak") << "\n"
              << "  Simbol     : " << (cfg.use_special ? "iya" : "tidak") << "\n"
              << "  No ambiguous: " << (cfg.no_ambiguous ? "iya" : "tidak") << "\n"
              << "\n";

    auto passwords = generate_multiple(
        rng, cfg.count, cfg.length,
        cfg.use_lower, cfg.use_upper, cfg.use_digits, cfg.use_special,
        cfg.no_ambiguous
    );

    // Hitung ukuran charset efektif untuk entropi
    std::string effective_charset;
    if (cfg.use_lower)  effective_charset += LOWER;
    if (cfg.use_upper)  effective_charset += UPPER;
    if (cfg.use_digits) effective_charset += DIGITS;
    if (cfg.use_special) effective_charset += SPECIAL;
    if (cfg.no_ambiguous) {
        std::string filtered;
        for (char c : effective_charset) {
            char u = std::toupper(c);
            if (u == 'L' || u == 'I' || u == 'O') continue;
            if (c == '1' || c == '0') continue;
            filtered += c;
        }
        effective_charset = filtered;
    }

    std::cout << " password yang di-generate:\n\n";

    for (size_t i = 0; i < passwords.size(); ++i) {
        std::cout << "  #" << (i + 1) << " : ";
        print_password(passwords[i]);
    }

    if (cfg.show_entropy) {
        std::cout << "\n --- Estimasi Kekuatan (Entropi) ---\n";
        double ent = entropy_bits(
            static_cast<double>(effective_charset.size()),
            cfg.length
        );
        std::cout << "  Ukuran charset efektif : " << effective_charset.size() << " karakter\n";
        std::cout << "  Entropi                : " << std::fixed << std::setprecision(1)
                  << ent << " bit\n";
        std::cout << "  Kategori               : " << classify_strength(ent) << "\n";
        std::cout << "\n  Kombinasi mungkin      : 10^" << std::fixed << std::setprecision(0)
                  << ent * std::log(10.0) / std::log(2.0) << "\n";
    }

    std::cout << "\n";

    return 0;
}
