#include <iostream>
#include<string.h>
using namespace std;
class String
{
public: size_t _Size;
    char * _String;
public: String();
    String(const char * Str);
    String(const String & Str);
    ~String();
    // atribuirea sirului
    String & operator = (const String & Str);
    // concatenarea sirurilor
    String & operator += (const char * Str);
    String & operator += (String & Str);
    String & operator += (char Ch);
    String & Copy(const char * s);
    String & Copy(String & s);
    String & Cat(const char * Str);
    String & Cat(char Ch);
    String & Cat(String & Str);
    size_t Length(void)
    {
        return _Size;
    }

    // String s = new String[50];
    // String s();
    // s[20];

    string operator[](string rhs)
    {
        int k = 0, x;
        char Ch;
        for (rhs.begin(); k < rhs.length(); rhs.end())
            cout << "[" << rhs[k++] << "]";
        cout << endl;
        k = 0;
        for (rhs.begin(); k < rhs.length(); rhs.end()) cout << "[" << k++ << "]";
        cout << endl;
        cout << "\nIntroduceti pozitia unui element x care doriti sa schimbati: ";
        cin >> x;
        cout << "Introduceti un character: ";
        cin >> Ch;
        k = 0;
        for (rhs.begin(); k < rhs.length(); rhs.end()) {
            if (k == x) rhs[k] = Ch;
            k++;
        }
        cout << endl;
        k = 0;
        for (rhs.begin(); k < rhs.length(); rhs.end()) cout << "[" << rhs[k++] << "]";
        system("pause");
        return rhs;
    }
    // compararea sirurilor
    bool operator == (const char * Str) const;
    bool operator == (const String & Str) const;
    bool operator != (const char * Str) const;
    bool operator != (const String & Str) const;
    bool operator < (const char * Str);
    bool operator < (String & Str);
    bool operator > (const char * Str);
    bool operator > (String & Str);
    int Compare(const char * Str) const;
    int Compare(String & Str) const;
    void Set(const char * Str);
    void Set(const String & Str);
    char * Get() const;
};
String::String()
{
    _Size = 0;
    _String = 0;
}
String::~String()
{
    delete[] _String;
    _String = NULL;
}
String::String(const char * Str)
{
    _String = new char[strlen(Str) + 1];
    strcpy(_String, Str);
}
String::String(const String & Str)
{
    _String = new char[strlen(Str._String) + 1];
    strcpy(_String, Str._String);
}
// suprascrierea operatorului  +
String operator + ( String & S1, String & S2)
{
    char * t = new char[S1.Length() + S2.Length() + 1];
    strcpy(t, S1.Get());
    strcat(t, S2.Get());
    return String(t);
}
// copiem sirurile *char
String & String::Copy(const char * Str)
{
    delete[] _String;
    _Size = strlen(Str);
    _String = new char[_Size + 1];
    strcpy(_String, Str);
    return *this;
}
// copiem string
String & String::Copy(String & Str)
{
    Copy(Str._String);
    return *this;
}
// concatenarea sirurilor *char
String & String::Cat(char  const * Str)
{
    _Size = Length() + strlen(Str);
    char * t = new char[_Size + 1];
    strcpy(t, _String);
    strcat(t, Str);
    delete[] _String;
    _String = t;
    return *this;
}
// concaternarea stringurilor
String & String::Cat(String & Str)
{
    Cat(Str._String);
    return *this;
}
// concatenarea simbolurilor
String & String::Cat(char Ch)
{
    _Size++;
    char * t = new char[_Size + 1];
    strcpy(t, _String);
    delete[] _String;
    _String = t;
    t += _Size;* t = '\0';
    t--;
    * t = Ch;
    return *this;
}
// suprascrierea operatorului += argumentul de tip * char
String & String::operator += (const char * Str)
{
    Cat(Str);
    return *this;
}
// suprascrierea operatorului += argumentul de tip clasa
String & String::operator += (String & Str)
{
    Cat(Str);
    return *this;
}
// suprascrierea operatorului += argumentul simbol
String & String::operator += (char Ch)
{
    Cat(Ch);
    return *this;
}
// suprascrierea operatorului
String & String::operator = (const String & Str)
{
    char * t = new char[strlen(Str._String) + 1];
    strcpy(t, Str._String);
    delete[] _String;
    _String = t;
    return *this;
}

// suprascrierea operatorului == argumentul de tip * char
bool String::operator == (const char *Str) const
{
    if (Compare(Str) == 0)
        return true;
    return false;
}
// suprascrierea operatorului == argumentul de tip clasei
bool String::operator == (const String & Str) const
{
    if (Compare(Str._String) == 0) return true;
    return false;
}
// suprascrierea operatorului != argumentul * char
bool String::operator != (const char * Str) const
{
    if (Compare(Str) != 0)
        return true;
    return false;
}
// suprascreierea oepratorului != argumentul clasei
bool String::operator != (const String &Str) const
{
    if (Compare(Str._String) != 0)
        return true;
    return false;
}
// suprascreirea oepratorlui < argument de tip * char
bool String::operator < (const char * Str)
{
    if (Compare(Str) < 0)
        return true;
    return false;
}
// suprascrierea operatorului < argumentul clasei
bool String::operator < (String &Str)
{
    if (Compare(Str._String) < 0)
        return true;
    return false;
}
// suprascrierea operatorului > argumentul de tip  * char
bool String::operator > (const char * Str)
{
    if (Compare(Str) > 0)
        return true;
    return false;
}
// suprascrierea opertorului > argumentul clasei
bool String::operator > (String &Str)
{
    if (Compare(Str._String) > 0)
        return true;
    return false;
}
// argumentul de tip * char trimis de către obiect este comparat cu membrul String
int String::Compare(const char * Str) const
{
    return (strcmp(_String, Str));
}
// in timpul comparației între siruri argumentul de tip clasa, trimis de catre obiect, este comparat cu membrul _String
int String::Compare(String & Str) const
{
    return (strcmp(_String, Str._String));
}
// Găsim lungimea șirului transmis ca argument și îl trimitem ca argument în funcția Set
void String::Set(const char * Str)
{
    Set(String(Str));
}
// adaugam
void String::Set(const String & Str)
{
    * this = Str;
}
//  returnam linia de String
char * String::Get() const
{
    return _String;
}
istream & operator >> (istream & Input, String & Str)
{
    Input >> Str._String;
    return Input;
}
ostream & operator << (ostream & Output, String & Str)
{
    Output << Str._String;
    return Output;
}
int main() {
    int op;
    String IsSpace = " ", ObjectA, ObjectB, ObjectC;
    char FirstStr[128], SecondStr[128];
    String ObjectArray;
    while (1) {
        cout << "Meniu\n";
        cout << "[1]: Introducerea sirurilor de caractere\n";
        cout << "[2]: Operator \"+ \" | Concatinarea sirurilor de caractere\n";
        cout << "[3]: Operator \"= \" | Atribuire\n";
        cout << "[4]: Operator \"+=\" | Concatinare cu atribuire\n";
        cout << "[5]: Operator \"==\" | Compararea sirurilor pentru egalitate\n";
        cout << "[6]: Operator \"!=\" | Compararea sirurilor pentru inegalitate\n";
        cout << "[7]: Operator \"< \" | Compararea sirului care este mai mic decit \n";
        cout << "[8]: Operator \"> \" | Compararea sirului care este mai mare decit\n";
        cout << "[9]: Operator \"[]\" | Acces la fiecare simbol\n";
        cout << "[0]: Iesire\n\n";
        cout << "Introduceti optiunea:" << endl;
        cin >> op;
        switch (op) {
            case 1:
                cout << "Introduceti primul sir: ";
                cin >> FirstStr;
                cout << "Introduceti al doilea sir: ";
                cin >> SecondStr;
                ObjectA = FirstStr;
                ObjectB = SecondStr;
                cout << "Sirurile sunt :" << endl;
                cout << " << " << ObjectA << " >> \n";
                cout << " << " << ObjectB << " >> \n";
                break;
            case 2:
                cout << "Sirurile sunt :" << endl;
                cout << " << " << ObjectA << " >> \n";
                cout << " << " << ObjectB << " >> \n";
                cout << "Sirul concatinat: ";
                ObjectC = ObjectA + IsSpace;
                ObjectC = ObjectC + ObjectB;
                ObjectC.Get();
                cout << " << " << ObjectC << " >> \n";
                break;
            case 3:

                ObjectC = "Acesta este un exemplu de sir atribuit...\n";
                ObjectC.Get();
                cout << ObjectC;
                break;
            case 4:
                ObjectC = ObjectA + ObjectB;
                ObjectC.Get();
                cout << "\nAtribuirea sirurilor combinate: ";
                cout << ObjectC << endl;
                break;
            case 5:
                if (ObjectA == ObjectB)
                    cout << "Sirurile sunt egale!" << endl;
                else {
                    cout << "Sirurile nu sunt egale!" << endl;
                }
                break;
            case 6:
                if (ObjectA != ObjectB) {
                    cout << "Sirurile nu sunt egale!" << endl;
                } else
                    cout << "Sirurile sunt egale" << endl;
                break;
            case 7:
                cout << " << " << ObjectA << " >> ";
                cout << " << " << ObjectB << " >> \n";
                if (ObjectA < ObjectB) cout << "Sirul << " << ObjectA << " >> este mai mic!" << endl;
                else cout << "Sirul << " << ObjectB << " >> este mai mic!" << endl;
                break;
            case 8:
                cout << " << " << ObjectA << " >> ";
                cout << " << " << ObjectB << " >> \n";
                if (ObjectA > ObjectB) cout << "Sirul << " << ObjectA << " >> este mai mare!" << endl;
                else
                    cout << "Sirul << " << ObjectB << " >> este mai mare!" << endl;
                break;
            case 9:
                ObjectArray["C++. The best programming language!"];
                break;
            case 0:
                return 0;
            default:
                cout << "Ati introdus o optiune gresita!" << endl;
                break;
        }}}
