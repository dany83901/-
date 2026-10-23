#include <iostream>
#include <bitset>
#include <clocale>
using namespace std;

int main() {
//Задание 1
    cout << "bool        - " << sizeof(bool)        << endl;
    cout << "char        - " << sizeof(char)        <<  endl;
    cout << "short int   - " << sizeof(short int)   <<  endl;
    cout << "int         - " << sizeof(int)         <<  endl;
    cout << "long int    - " << sizeof(long int)    <<  endl;
    cout << "long long   - " << sizeof(long long)   <<  endl;
    cout << "float       - " << sizeof(float)       <<  endl;
    cout << "double      - " << sizeof(double)      <<  endl;
    cout << "long double - " << sizeof(long double) <<  endl;
    cout << endl;


// Задание 2
    int a;
    cout << "Число: ";
    cin >> a;

    int order_i = sizeof(int) * 8;
    unsigned int mask_i = 1u << (order_i - 1);

    for (int i = 0; i < order_i; i++) {
        cout << ((a & (mask_i >> i)) ? '1' : '0');

        if (i == 0) {
            cout << "  ";
        }
    }
    cout << endl;


    ///Задание 3
    union {
        float f;
        unsigned int u;
    } fu;
    cout << "Число тип float: ";
    cin >> fu.f;

    int order_f = sizeof(float) * 8;
    unsigned int mask_f = 1u << (order_f - 1);

    cout << "Число: " << fu.f << endl;
    cout << "Знак | Порядок | Мантисса" << endl;
    for (int i = 0; i < order_f; i++) {
        cout << ((fu.u & (mask_f >> i)) ? '1' : '0');
        if (i == 0 || i == 8) cout << " | ";
    }
    cout << endl;

//Задание 4
    union {
        double d;
        unsigned long long u;
    } du;
    cout << "Введи число типа double: ";
    cin >> du.d;

    int order_d = sizeof(double) * 8;
    unsigned long long mask_d = 1ULL << (order_d - 1);

    cout << "Число: " << du.d << endl;
    cout << "Знак | Порядок | Мантисса" << endl;
    for (int i = 0; i < order_d; i++) {
        cout << ((du.u & (mask_d >> i)) ? '1' : '0');
        if (i == 0 || i == 11) cout << " | ";
    }
  cout << endl << "=== Задание 5 ===" << endl;
    int type, pos, op;

    cout << "Тип числа (1 - int, 2 - float, 3 - double): ";
    cin >> type;

    if (type == 1) {
        int x;
        cout << "Введите int: ";
        cin >> x;
        cout << "Номер бита (0..31): ";
        cin >> pos;
        cout << "Операция (1 - сбросить, 2 - установить, 3 - инвертировать): ";
        cin >> op;

        unsigned int u = x;
        unsigned int mask = 1u << pos;

        if (op == 1) {
            u = u & (~mask);
        } else if (op == 2) {
            u = u | mask;
        } else {
            u = u ^ mask;
        }

        cout << "Результат: " << (int)u << endl;
    }
    
//Задание 5
    else if (type == 2) {
        union {
            float f;
            unsigned int u;
        } x;
        cout << "Введите float: ";
        cin >> x.f;
        cout << "Номер бита (0..31): ";
        cin >> pos;
        cout << "Операция (1 - сбросить, 2 - установить, 3 - инвертировать): ";
        cin >> op;

        unsigned int mask = 1u << pos;

        if (op == 1) {
            x.u = x.u & (~mask);
        } else if (op == 2) {
            x.u = x.u | mask;
        } else {
            x.u = x.u ^ mask;
        }

        cout << "Результат: " << x.f << endl;
    }
    else if (type == 3) {
        union {
            double d;
            unsigned long long u;
        } x;
        cout << "Введите double: ";
        cin >> x.d;
        cout << "Номер бита (0..63): ";
        cin >> pos;
        cout << "Операция (1 - сбросить, 2 - установить, 3 - инвертировать): ";
        cin >> op;

        unsigned long long mask = 1ULL << pos;

        if (op == 1) {
            x.u = x.u & (~mask);
        } else if (op == 2) {
            x.u = x.u | mask;
        } else {
            x.u = x.u ^ mask;
        }

        cout << "Результат: " << x.d << endl;
    }

//ИДЗ Округление вниз до четного
int n;
    cout << "Число: ";
    cin >> n;

    cout << "Биты до:    ";
    for (int i = 31; i >= 0; i--) {
        if ((n >> i) & 1) {
            cout << '1';
        } else {
            cout << '0';
        }
        if (i == 31) {
            cout << "  ";
        }
    }
    cout << "  = " << n << endl;

    int res = n << 1;

    cout << "Биты после: ";
    for (int i = 31; i >= 0; i--) {
        if ((res >> i) & 1) {
            cout << '1';
        } else {
            cout << '0';
        }
        if (i == 31) {
            cout << "  ";
        }
    }
    cout << "  = " << res << endl;
}