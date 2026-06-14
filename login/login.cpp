#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <conio.h>

using namespace std;

struct User {
    string username;
    string password;
};

User customer[100];
User mitra[100];
User kurir[100];

int jumlahCustomer = 0;
int jumlahMitra = 1;
int jumlahKurir = 0;

void Registrasi();
void Login();
string inputPasswordTersembunyi();

string spasi = "                    ";

int main() {
    int pilihan;

    mitra[0].username = "mitra1";
    mitra[0].password = "12345";

    cout << setw(50) << "Selamat datang di aplikasi SayurGo!" << endl;
    Sleep(3000);
    system("cls");

    do {
        cout << spasi << "======================================" << endl;
        cout << spasi << "| Silahkan pilih role yang tersedia! |" << endl;
        cout << spasi << "======================================" << endl;
        cout << spasi << "| Menu:                              |" << endl;
        cout << spasi << "| 1. Register                        |" << endl;
        cout << spasi << "| 2. Login                           |" << endl;
        cout << spasi << "| 3. Keluar                          |" << endl;
        cout << spasi << "+------------------------------------+" << endl;
        cout << spasi << "| Pilihan: ";

        cin >> pilihan;
        system("cls");

        switch (pilihan) {
        case 1:
            Registrasi();
            break;
        case 2:
            Login();
            system("pause");
            system("cls");
            break;
        case 3:
            cout << "Terima kasih";
            system("pause");
            system("cls");
            break;
        default:
            cout << spasi << "Pilihan tidak valid!" << endl;
            system("pause");
            system("cls");
            break;
        }

    } while (pilihan != 3);

    return 0;
}

string inputPasswordTersembunyi() {
    string password = "";
    char ch;
    while (true) {
        ch = _getch(); 
        if (ch == '\r') { 
            break;
        }
        else if (ch == '\b') { 
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b"; 
            }
        }
        else if (ch >= 32 && ch <= 126) {
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

void Registrasi() {
    bool regis = true;
    do {
        int role;

        cout << spasi << "======================================" << endl;
        cout << spasi << "| Silahkan pilih role yang tersedia! |" << endl;
        cout << spasi << "======================================" << endl;
        cout << spasi << "| Menu:                              |" << endl;
        cout << spasi << "| 1. Customer                        |" << endl;
        cout << spasi << "| 2. Kurir                           |" << endl;
        cout << spasi << "+------------------------------------+" << endl;
        cout << spasi << "| Pilihan: ";
        cin >> role;

        string user, pass;

        cout << spasi << "| Username: ";
        cin >> user;

        cout << spasi << "| Password: ";
        pass = inputPasswordTersembunyi();

        switch (role) {
        case 1:
            customer[jumlahCustomer].username = user;
            customer[jumlahCustomer].password = pass;
            jumlahCustomer++;
            cout << spasi << "======================================" << endl;
            cout << spasi << "| Register Customer berhasil!       |" << endl;
            cout << spasi << "======================================" << endl;
            system("pause");
            system("cls");
            regis = false;
            break;

        case 2:
            kurir[jumlahKurir].username = user;
            kurir[jumlahKurir].password = pass;
            jumlahKurir++;
            cout << spasi << "======================================" << endl;
            cout << spasi << "| Register Kurir berhasil!          |" << endl;
            cout << spasi << "======================================" << endl;
            system("pause");
            system("cls");
            regis = false;
            break;

        default:
            cout << spasi << "======================================" << endl;
            cout << spasi << "| Role tidak valid!                 |" << endl;
            cout << spasi << "======================================" << endl;
            system("pause");
            system("cls");
            regis = false;
            break;
        };

    } while (regis);
}

void Login() {
    do {
        int role;
        bool ditemukan = false;

        cout << spasi << "======================================" << endl;
        cout << spasi << "| Silahkan pilih menu yang tersedia! |" << endl;
        cout << spasi << "======================================" << endl;
        cout << spasi << "| Menu:                              |" << endl;
        cout << spasi << "| 1. Customer                        |" << endl;
        cout << spasi << "| 2. Mitra                           |" << endl;
        cout << spasi << "| 3. Kurir                           |" << endl;
        cout << spasi << "+------------------------------------+" << endl;
        cout << spasi << "| Pilihan: ";
        cin >> role;

        string user, pass;

        cout << spasi << "| Username: ";
        cin >> user;

        cout << spasi << "| Password: ";
        pass = inputPasswordTersembunyi();

        switch (role) {
        case 1:
            for (int i = 0; i < jumlahCustomer; i++) {
                if (customer[i].username == user &&
                    customer[i].password == pass) {
                    ditemukan = true;
                    cout << spasi << "======================================" << endl;
                    cout << spasi << "| Login Customer berhasil!          |" << endl;
                    cout << spasi << "======================================" << endl;
                    break;
                }
            }
            break;

        case 2:
            for (int i = 0; i < jumlahMitra; i++) {
                if (mitra[i].username == user &&
                    mitra[i].password == pass) {
                    ditemukan = true;
                    cout << spasi << "======================================" << endl;
                    cout << spasi << "| Login Mitra berhasil!             |" << endl;
                    cout << spasi << "======================================" << endl;
                    break;
                }
            }
            break;

        case 3:
            for (int i = 0; i < jumlahKurir; i++) {
                if (kurir[i].username == user &&
                    kurir[i].password == pass) {
                    ditemukan = true;
                    cout << spasi << "======================================" << endl;
                    cout << spasi << "| Login Kurir berhasil!             |" << endl;
                    cout << spasi << "======================================" << endl;
                    break;
                }
            }
            break;

        default:
            cout << spasi << "======================================" << endl;
            cout << spasi << "| Role tidak valid!                 |" << endl;
            cout << spasi << "======================================" << endl;
            break;
        }

        if (!ditemukan) {
            cout << spasi << "======================================" << endl;
            cout << spasi << "| Username atau Password salah      |" << endl;
            cout << spasi << "======================================" << endl;
        }

        break;
    } while (true);
}