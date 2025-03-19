#include <iostream>
#include <map>
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text;
    cout << "Введите текст: ";
    getline(cin, text);

    map<char, int> fMap;

    for (char c = 'А'; c <= 'Я'; ++c) {
        fMap[c] = 0;
    }
    fMap[' '] = 0;
    int count = 0;

    for (char c : text) {
        if ((c >= 'А' && c <= 'Я') || c == ' ') {
            fMap[c]++;
        }
        count++;
    }
    vector<pair<char, int>> fVec(fMap.begin(), fMap.end());

    for (size_t i = 0; i < fVec.size(); ++i) {
        for (size_t j = 0; j < fVec.size() - 1; ++j) {
            if (fVec[j].second < fVec[j + 1].second) {
                swap(fVec[j], fVec[j + 1]);
            }
        }
    }

    cout << "Частота встречаемости каждого символа:\n";
    for (const auto& pair : fVec) {
        cout << "'" << pair.first << "': " << pair.second << "\n";
    }
    cout << "Всего символов: " << count << endl;


    vector<int> arr;

    for (const auto& pair : fVec) {
        arr.push_back(pair.second);
    }
    
    int n = 1;
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;


    arr.push_back(0);
    cout << "Какая мощьность алфавита (2 или 4): ";
    int m;
    cin >> m;

    while (arr.size() > 1) {

        int sum;

        if (m == 2) {
            //B={0,1}
            sum = arr[arr.size() - 1] + arr[arr.size() - 2];
            cout << arr[arr.size() - 1] << "+" << arr[arr.size() - 2] << "=" << sum << endl;

            arr.pop_back();
            arr.pop_back();
        }
        else {
            //B={0,1,2,3}
            sum = arr[arr.size() - 1] + arr[arr.size() - 2] + arr[arr.size() - 3] + arr[arr.size() - 4];
            cout << arr[arr.size() - 1] << "+" << arr[arr.size() - 2] << "+" << arr[arr.size() - 3] << "+" << arr[arr.size() - 4] << "=" << sum << endl;

            arr.pop_back();
            arr.pop_back();
            arr.pop_back();
            arr.pop_back();
        }
        
        

        bool inserted = false;
        for (size_t i = 0; i < arr.size(); ++i) {
            if (sum >= arr[i]) {
                arr.insert(arr.begin() + i, sum);
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            arr.push_back(sum);
        }

        cout << n << ") ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << "\n";
        n++;
    }


    return 0;
}


//И ОТДЕЛАВШИСЬ ОТ МОЛОДОГО ЧЕЛОВЕКА НЕ УМЕЮЩЕГО ЖИТЬ ОНА ВОЗВРАТИЛАСЬ К СВОИМ ЗАНЯТИЯМ ХОЗЯЙКИ ДОМА И ПРОДОЛЖАЛА ПРИСЛУШИВАТЬСЯ И ПРИГЛЯДЫВАТЬСЯ ГОТОВАЯ ПОДАТЬ ПОМОЩЬ НА ТОТ ПУНКТ ГДЕ ОСЛАБЕВАЛ РАЗГОВОР КАК ХОЗЯИН ПРЯДИЛЬНОЙ МАСТЕРСКОЙ ПОСАДИВ РАБОТНИКОВ ПО МЕСТАМ ПРОХАЖИВАЕТСЯ ПО ЗАВЕДЕНИЮ ЗАМЕЧАЯ НЕПОДВИЖНОСТЬ ИЛИ НЕПРИВЫЧНЫЙ СКРИПЯЩИЙ СЛИШКОМ ГРОМКИЙ ЗВУК ВЕРЕТЕНА ТОРОПЛИВО ИДЕТ СДЕРЖИВАЕТ ИЛИ ПУСКАЕТ ЕГО В НАДЛЕЖАЩИЙ ХОД ТАК И АННА ПАВЛОВНА ПРОХАЖИВАЯСЬ ПО СВОЕЙ ГОСТИНОЙ ПОДХОДИЛА К ЗАМОЛКНУВШЕМУ ИЛИ СЛИШКОМ МНОГО ГОВОРИВШЕМУ КРУЖКУ И ОДНИМ СЛОВОМ ИЛИ ПЕРЕМЕЩЕНИЕМ ОПЯТЬ ЗАВОДИЛА РАВНОМЕРНУЮ ПРИЛИЧНУЮ РАЗГОВОРНУЮ МАШИНУ НО СРЕДИ ЭТИХ ЗАБОТ ВСЕ ВИДЕН БЫЛ В НЕЙ ОСОБЕННЫЙ СТРАХ ЗА ПЬЕРА


