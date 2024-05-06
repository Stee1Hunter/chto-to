#include <iostream>
#include <Windows.h>
#include <algorithm> 
#include <random> 
#include <thread>
#include <chrono> 
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <complex>
using namespace std;

class Gun {
public:
    Gun(string name, double caliber, int magazineCapacity, double price)
        : name(name), caliber(caliber), magazineCapacity(magazineCapacity), price(price) {}

    string name;
    double caliber;
    int magazineCapacity;
    double price;
};

// Функция для добавления оружия
void addGun(vector<Gun>& gunShop) {
    string name;
    double caliber;
    int magazineCapacity;
    double price;

    cout << "Введите название оружия: ";
    getline(cin, name);

    cout << "Введите калибр: ";
    cin >> caliber;
    cin.ignore(); // Игнорировать символ новой строки, оставшийся в буфере ввода

    cout << "Введите емкость магазина: ";
    cin >> magazineCapacity;
    cin.ignore();

    cout << "Введите цену: ";
    cin >> price;
    cin.ignore();

    Gun newGun(name, caliber, magazineCapacity, price);
    gunShop.push_back(newGun);

    cout << "Оружие успешно добавлено!" << endl;
}

// Функция для отображения ассортимента оружия
void displayGunShop(const vector<Gun>& gunShop) {
    cout << "Ассортимент оружия:" << endl;
    for (const auto& gun : gunShop) {
        cout << "Название: " << gun.name << endl;
        cout << "Калибр: " << gun.caliber << endl;
        cout << "Емкость магазина: " << gun.magazineCapacity << endl;
        cout << "Цена: " << gun.price << endl;
        cout << "---------------------" << endl;
    }
}
class Orders {
public:
    Orders(string FIO, string Pass) : FIO(FIO), Pass(Pass) {}
    string FIO;
    string Pass;
};

void addzakaz(vector<Orders>& orders, vector<Gun>& gunShop) {
    string FIO;
    string Pass;
    string gunName;
    bool found = false;

    cout << "Покупка:" << endl;
    cout << "Введите ваше ФИО: ";
    cin >> FIO;

    cout << "Введите ваши паспортные данные: ";
    cin >> Pass;

    cout << "Введите название оружия, которое вы покупаете: ";
    cin >> gunName;

    // Проверяем, есть ли такое оружие в ассортименте
    for (const auto& gun : gunShop) {
        if (gun.name == gunName) {
            found = true;
            Orders newOrder(FIO, Pass);
            orders.push_back(newOrder);
            cout << "Заказ успешно оформлен!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Такого оружия нет в ассортименте." << endl;
    }
}
void vivodzakaza(vector<Orders>& orders, vector<Gun>& gunShop) {
    string Pass;
    bool found = false;
    cout << "Введите ваши паспортные данные, чтобы увидеть ваш заказ: ";
    cin >> Pass;
    // Проверяем, есть ли заказ с введенными паспортными данными
    for (const auto& order : orders) {
        if (order.Pass == Pass) {
            found = true;
            cout << "Ваш заказ:" << endl;
            cout << "ФИО: " << order.FIO << endl;
            cout << "Паспортные данные: " << order.Pass << endl;

            // Находим оружие в ассортименте по названию
            for (const auto& gun : gunShop) {
                cout << "Название оружия: " << gun.name << endl;
                cout << "Калибр: " << gun.caliber << endl;
                cout << "Емкость магазина: " << gun.magazineCapacity << endl;
                cout << "Цена: " << gun.price << endl;
                cout << "---------------------" << endl;
            }
            break;
        }
        break;
    }
    if (!found) {
        cout << "Заказ с такими паспортными данными не найден." << endl;
    }
}



class tir {
public:
    tir(string gunsTwo, double kalibr, double michen, string poza, int strelbas)
        : michen(michen), poza(poza), gunsTwo(gunsTwo), kalibrl(kalibrl), strelbas(strelbas) {}
    string gunsTwo;
    double kalibrl;
    double michen;
    string poza;
    int strelbas;
};

void strelba(vector<tir>& tir) {
    double michen;
    string poza;
    string gunsTwo;
    double kalibrl;
    int strelbas;

    cout << "вы вошли в режим тир" << endl;

    cout << "для начала введите дальность мешени в метрах: ";
    cin >> michen;
    cin.ignore();


    cout << "теперь введите позу в которой будете вести стрельбу: ";
    cin >> poza;
    cin.ignore();


    cout << "введите название оружия из которого будете стрелять: ";
    cin >> gunsTwo;
    cin.ignore();

    cout << "и его калибр: ";
    cin >> kalibrl;
    cin.ignore();

    cout << "хорошо, вы приняли позу " << poza << " и начали стрелять на дистанцию " << michen << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "пив" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "пав" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "скидыш" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "вы закончили стрельбу, через несколько секунд вы будете возвращенны в меню" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
}







int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    vector<Gun> gunShop;
    vector<Orders> orders;
    vector<tir> tir;
    int choice;


    do {
        int nomer;
        cout << "Меню:" << endl;
        cout << "1. Добавить оружие" << endl;
        cout << "2. Показать ассортимент оружия" << endl;
        cout << "3. сделать заказ" << endl;
        cout << "4. вывести заказ" << endl;
        cout << "5. зайти в тир" << endl;
        cout << "0. Выход" << endl;
        cout << "Введите выбор: ";
        cin >> choice;
        cin.ignore(); // Игнорировать символ новой строки, оставшийся в буфере ввода

        switch (choice) {
        case 1:
            addGun(gunShop);
            break;
        case 2:
            displayGunShop(gunShop);
            break;
        case 3:
            addzakaz(orders, gunShop);
            break;
        case 4:
            vivodzakaza(orders, gunShop);
            cin >> nomer;
            break;
        case 5:
            strelba(tir);
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}