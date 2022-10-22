#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int start = 3;
struct Turizm
{
    string place;
    int count;
    int cost;
};

struct vector<Turizm> tur(start);

void print()
{
    cout << setiosflags(ios::left);
    cout << "   Count   " << "Place   " << "  Cost" << endl;

    for (int i = 0; i < tur.size(); i++)
    {
        cout << i + 1 << ".  ";
        cout << setw(6) << tur[i].count;
        cout << setw(11) << tur[i].place;
        cout << setw(5) << tur[i].cost;
        cout << endl;
    }
    cout << endl;
}

void add()
{
    Turizm turizm;
    tur.push_back(turizm);

    cout << "Enter count"; cin >> tur[tur.size() - 1].count;
    cout << "Enter place"; cin >> tur[tur.size() - 1].place;
    cout << "Enter cost"; cin >> tur[tur.size() - 1].cost;

    cout << setiosflags(ios::left);
    cout << "   Count   " << "Place   " << "  Cost" << endl;

    for (int i = 0; i < tur.size(); i++)
    {
        cout << i + 1 << ".  ";
        cout << setw(6) << tur[i].count;
        cout << setw(11) << tur[i].place;
        cout << setw(5) << tur[i].cost;
        cout << endl;
    }
    cout << endl;
}

void del()
{
    int num;
    cout << "Enter the number of line you want to delete: " << endl;
    cin >> num;

    tur.erase(tur.begin() + num);

    cout << setiosflags(ios::left);
    cout << "   Count   " << "Place   " << "  Cost" << endl;
    for (int i = 0; i < tur.size(); i++)
    {
        cout << i + 1 << ".  ";
        cout << setw(6) << tur[i].count;
        cout << setw(11) << tur[i].place;
        cout << setw(5) << tur[i].cost;
        cout << endl;
    }
    cout << endl;
}

void change()
{
    int num, cnt, cst;
    string plc;

    cout << "If you dont want to change the element, psl write -1" << endl;
    cout << "Enter the number of line you want to change: " << endl;

    cin >> num;
    
    cout << setiosflags(ios::left);
    cout << "   Count   " << "Place   " << "  Cost" << endl;
    cout << setw(6) << tur[num - 1].count;
    cout << setw(11) << tur[num - 1].place;
    cout << setw(5) << tur[num - 1].cost;
    cout << endl;

	cout << "Enter count"; cin >> cnt;
    cout << "Enter place"; cin >> plc;
    cout << "Enter cost"; cin >> cst;

    if (cnt != -1)
        tur[num - 1].count = cnt;
    if (plc != "-1")
        tur[num - 1].place = plc;
    if (cst != -1)
        tur[num - 1].cost = cst;

    cout << setiosflags(ios::left);
    cout << "   Count   " << "Place   " << "  Cost" << endl;

    for (int i = 0; i < tur.size(); i++)
    {
        cout << i + 1 << ".  ";
        cout << setw(6) << tur[i].count;
        cout << setw(11) << tur[i].place;
        cout << setw(5) << tur[i].cost;
        cout << endl;
    }
    cout << endl;
}

void save()
{
    ofstream write("finish.txt", ios_base::trunc);
    for (int i = 0; i < tur.size(); i++)
    {
        write << tur[i].count << "\t" << tur[i].place << "\t" << tur[i].cost << endl;
    }
}

int main()
{
    int choose;
    ifstream file("start.txt", ios_base::in);
    for (int i = 0; i < start; i++)
    {
        file >> tur[i].count >> tur[i].place >> tur[i].cost;
    }
    file.close();

    cho:
    cout << "1. Initial array\n2. Delete line\n3. Change elements\n4. Exit" << endl;
    cout << "Choose the variant and enter the number:" << endl;
    cin >> choose;
    switch(choose)
    {
    case 1:
        print();
    	goto cho;
    case 2:
    	del();
    	goto cho;
    case 3:
        change();
        goto cho;
    case 4:
        save();
        return 0;
    }
}