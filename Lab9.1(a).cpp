#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

enum Specialty {KN, INF, ME, PI, TD};

string specialtyStr[] = {"Комп'ютерні науки", "Інформатика", "Математика та екноміка", " Фізика та інформатика", "Трудове навчання"};

struct Student {
    string prizv;
    unsigned kurs;
    Specialty specialty;
    unsigned gradePhys;
    unsigned gradeMath;
    unsigned gradeInf;
};

void Create(Student* s, const int k);
void Print(Student* s, const int k);
void physStat(Student *s, const int k, int& threeCount, int& fourCount, int& fiveCount);
int goodMathPhys(Student* s, const int k);



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int k; 
    int threeCount = 0, fourCount = 0, fiveCount = 0;
    cout << "Кількість студентів: "; cin >> k;

    Student* s = new Student[k];

    Create(s, k);
    Print(s, k);
    physStat(s, k, threeCount, fourCount, fiveCount);

    cout << "Кількість 3 за фізику: " << threeCount << endl;
    cout << "Кількість 4 за фізику: " << fourCount << endl;
    cout << "Кількість 5 за фізику: " << fiveCount << endl;

    cout << "Кількість учнів із заданим критерієм: " << goodMathPhys(s, k) << endl;

    system("pause");
    cin.get();
    return 0;
}

void Create(Student *s, const int k) {
    int specialty;
    for (int i = 0; i < k; i++) {
        cout << "Студент №: " << i + 1 << ": " << endl;
        cin.ignore();
        cout << "Прізвище: ";
        getline(cin, s[i].prizv);
        cout << "Курс: "; cin >> s[i].kurs;
        cout << "Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та екноміка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
        cin >> specialty;
        s[i].specialty = (Specialty)specialty;
        cout << "Оцінка з фізики: "; cin >> s[i].gradePhys;
        cout << "Оцінка з математики: "; cin >> s[i].gradeMath;
        cout << "Оцінка з інформатики: "; cin >> s[i].gradeInf;
        cout << endl;
    }

}

void Print(Student* s, const int k) {
    cout << "========================================================================================================================================" << endl;
    cout << "|  No  |    Прізвище    |  Курс  |      Спеціальність      |   Оцінка з фізкики   |   Оцінка з математики   |   Оцінка з інформатики   |" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < k; i++) {
        cout << "| " << setw(3) << right << i + 1 << "  ";
        cout << "| " << setw(15) << left << s[i].prizv 
             << "|   " << setw(3) << right << s[i].kurs << "  "
             << "| " << setw(24) << left << specialtyStr[s[i].specialty]
             << "| " << setw(20) << right << s[i].gradePhys << " "
             << "| " << setw(23) << right << s[i].gradeMath << " "
             << "| " << setw(24) << right << s[i].gradeMath << " "
             << "|" << endl;
    }
    cout << "========================================================================================================================================" << endl;
    cout << endl;

}

void physStat(Student *s, const int k, int &threeCount, int &fourCount, int &fiveCount) {
    for (int i = 0; i < k; i++) {
        if (s[i].gradePhys == 3) {
            threeCount++;
        }
        else if (s[i].gradePhys == 4) {
            fourCount++;
        }
        else if (s[i].gradePhys == 5){
            fiveCount++;
        }
    }
}

int goodMathPhys(Student* s, const int k) {
    int n = 0;
    for (int i = 0; i < k; i++) {
        if ((s[i].gradeMath == 4 || s[i].gradeMath == 5) && (s[i].gradePhys == 4 || s[i].gradePhys == 5))
            n++;
    }
    return n;
}