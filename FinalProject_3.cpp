#include <iostream>
#include <algorithm>
#include <conio.h>
using namespace std;
class binary
{
public:
    int BinaryToDecimal(int n)
    {
        int decimal = 0;
        int base = 1;
        while (n > 0)
        {
            int last_digit = n % 10;
            n /=10;
            decimal += last_digit * base;
            base *=2;
        }
        return decimal;
    }
    int BinaryToOctal(int n)
    {
        int octal = 0;
        int decimal = BinaryToDecimal(n);
        int base = 1;
        while (decimal > 0)
        {
            int last_digit = decimal % 8;
            decimal = decimal / 8;
            octal += last_digit * base;
            base = base * 10;
        }
        return octal;
    }
    string BinaryToHexadecimal(int n)
    {
        int decimal = BinaryToDecimal(n);
        int base = 1;
        string Hexa_values = "0123456789ABCDEF";
        string hexa = "";
        while (decimal > 0)
        {
            int last_digit = decimal % 16;
            decimal = decimal / 16;
            hexa += Hexa_values[last_digit];
        }
        reverse(hexa.begin(), hexa.end());
        return hexa;
    }
};
class decimal
{
public:
    int DecimalToBinary(int n)
    {
        int binary = 0;
        int i = 1;
        while (n > 0)
        {
            int last_digit = n % 2;
            n = n / 2;
            binary += last_digit * i;
            i *= 10;
        }
        return binary;
    }
    int DecimalToOctal(int n)
    {
        int octal = 0, i = 1;
        while (n > 0)
        {
            int last_digit = n % 8;
            n = n / 8;
            octal += (last_digit * i);
            i *= 10;
        }
        return octal;
    }
    string decimalToHexadecimal(int n)
    {
        int decimal = n;
        int base = 1;
        string Hexa_values = "0123456789ABCDEF";
        string hexa = "";
        while (decimal > 0)
        {
            int last_digit = decimal % 16;
            decimal = decimal / 16;
            hexa += Hexa_values[last_digit];
        }
        reverse(hexa.begin(), hexa.end());
        return hexa;
    }
};
class octal : public decimal
{
public:
    int OctalToDecimal(int n)
    {
        int dec_value = 0, base = 1;
        while (n)
        {
            int last_digit = n % 10;
            n = n / 10;
            dec_value += last_digit * base;
            base = base * 8;
        }
        return dec_value;
    }
    int OctalToBinary(int n)
    {
        int x = OctalToDecimal(n);
        return DecimalToBinary(x);
    }
    string OctalToHexadecimal(int n)
    {
        int x = OctalToDecimal(n);
        return decimalToHexadecimal(x);
    }
};
class hexadecimal : public decimal
{
public:
    int HexadecimalToDecimal(string n)
    {
        int len = n.size(), dec = 0;
        int base = 1;
        for (int i = len - 1; i >= 0; i--)
        {
            if (n[i] >= '0' && n[i] <= '9')
            {
                dec += ((int(n[i])) - 48) * base;
                base *= 16;
            }
            else if (n[i] >= 'A' && n[i] <= 'F')
            {
                dec += (int(n[i]) - 55) * base;
                base *= 16;
            }
        }
        return dec;
    }
    int HexadecimalToBinary(string n)
    {
        int x = HexadecimalToDecimal(n);
        return DecimalToBinary(x);
    }
    int HexadecimalToOctal(string n)
    {
        int x = HexadecimalToDecimal(n);
        return DecimalToOctal(x);
    }
};
int main()
{
    int choice;
    cout << "Which conversion do want to perform?" << endl;
    cout << "1. binary conversions" << endl;
    cout << "2. octal conversions" << endl;
    cout << "3. hexadecimal conversions" << endl;
    cout << "4. decimal conversions" << endl;
    cout << "5. exit" << endl;
    cin >> choice;
    if (choice == 5)
    {
        return 0;
    }
    switch (choice)
    {
    case 1:
    {
        int n;
        cout << "Which binary conversion do you want to perform?" << endl;
        cout << "1. binary to decimal" << endl;
        cout << "2. binary to octal" << endl;
        cout << "3. binary to hexadecimal" << endl;
        cout << "4. exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "Enter the binary number:" << endl;
            cin >> n;
            binary obj;
            cout << obj.BinaryToDecimal(n) << endl;
            break;
        }
        case 2:
        {

            cout << "Enter the binary number:" << endl;
            cin >> n;
            binary obj;
            cout << obj.BinaryToOctal(n) << endl;
            break;
        }
        case 3:
        {
            cout << "Enter the binary number:" << endl;
            cin >> n;
            binary obj;
            int x = obj.BinaryToDecimal(n);
            cout << obj.BinaryToHexadecimal(x) << endl;
            break;
        }
        case 4:
        {
            break;
        }
        }
        break;
    }
    case 2:
    {
        int n;
        cout << "Which octal conversion do you want to perform?" << endl;
        cout << "1. octal to decimal" << endl;
        cout << "2. octal to binary" << endl;
        cout << "3. octal to hexadecimal" << endl;
        cout << "4. exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "Enter the octal number:" << endl;
            cin >> n;
            octal obj;
            cout << obj.OctalToDecimal(n) << endl;
            break;
        }
        case 2:
        {
            cout << "Enter the octal number:" << endl;
            cin >> n;
            octal obj;
            cout << obj.OctalToBinary(n) << endl;
            break;
        }
        case 3:
        {
            cout << "Enter the octal number:" << endl;
            cin >> n;
            octal obj;
            cout << obj.OctalToHexadecimal(n) << endl;
            break;
        }
        case 4:
        {
            break;
        }
        }
        break;
    }
    case 3:
    {
        int n;
        cout << "Which hexadecimal conversion do you want to perform?" << endl;
        cout << "1. hexadecimal to decimal" << endl;
        cout << "2. hexadecimal to binary" << endl;
        cout << "3. hexadecimal to octal" << endl;
        cout << "4. exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            string x;
            cout << "Enter the hexadecimal number:" << endl;
            cin >> x;
            hexadecimal obj;
            cout << obj.HexadecimalToDecimal(x) << endl;
            break;
        }
        case 2:
        {
            string x;
            cout << "Enter the hexadecimal number:" << endl;
            cin >> n;
            hexadecimal obj;
            cout << obj.HexadecimalToBinary(x) << endl;
            break;
        }
        case 3:
        {
            string x;
            cout << "Enter the hexadecimal number:" << endl;
            cin >> n;
            hexadecimal obj;
            cout << obj.HexadecimalToOctal(x) << endl;
            break;
        }
        case 4:
        {
            break;
        }
        }
        break;
    }
    case 4:
    {
        int n;
        cout << "Which decimal conversion do you want to perform?" << endl;
        cout << "1. decimal to binary" << endl;
        cout << "2. decimal to octal" << endl;
        cout << "3. decimal to hexadecimal" << endl;
        cout << "4. exit";
        cout << "Enter your choice:" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << "Enter the decimal number:" << endl;
            cin >> n;
            decimal obj;
            cout << obj.DecimalToBinary(n) << endl;
            break;
        }
        case 2:
        {
            cout << "Enter the decimal number:" << endl;
            cin >> n;
            decimal obj;
            cout << obj.DecimalToOctal(n) << endl;
            break;
        }
        case 3:
        {
            cout << "Enter the decimal number:" << endl;
            cin >> n;
            decimal obj;
            cout << obj.decimalToHexadecimal(n) << endl;
            break;
        }
        case 4:
        {
            break;
        }
        break;
        }
    }
    break;
    }
    return 0;
}