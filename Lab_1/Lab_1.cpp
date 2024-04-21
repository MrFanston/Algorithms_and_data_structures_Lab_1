#include <iostream>
using namespace std;

struct Node
{
    string name;
    string number;
    string model;
    int move;
    Node* next;
};

class Garage
{
private:
    Node* head;
public:
    //Конструктор
    Garage()
    {
        head = nullptr;
    }
    //Деструктор
    ~Garage()
    {
        for (Node* del = head; del != nullptr; del = del->next)
            delete del;
    }
    //Функция прибытия машины
    void comming(string NameCar, string NumberCar, string ModelCar)
    {
        Node* new_Node;
        new_Node = new Node();
        new_Node->name = NameCar;
        new_Node->number = NumberCar;
        new_Node->model = ModelCar;
        new_Node->move = 0;
        new_Node->next = head;
        head = new_Node;
        cout << "Машина " << NumberCar << " прибыла\n\n";
    }
    //Функция отбытия машины
    void leave(string SelectionCar)
    {
        // Вспомогательные указатели на прошлый и текущий элемент
        Node* current, * prev;
        current = head;
        prev = head;

        //Если в списке нет элементов
        if (head == nullptr)
        {
            cout << "В гараже нет машин\n\n";
        }
        else
        {
            bool first = true;
            //Перебирвем все элементы
            while (current != nullptr)
            {
                //Если первый элемент
                if (first)
                {
                    //Соответствует
                    if (current->number == SelectionCar)
                    {
                        cout << "Машина: " << SelectionCar << ", отбыла из гаража\n";
                        cout << "Кол-во удалений со стоянки: " << head->move << "\n\n";
                        head = head->next; // Голова списка сдвигается на след элемент
                        delete current; // Прошлая голова списка удаляется
                        break;
                    }
                    //Не соответствует
                    else
                    {
                        current->move = current->move + 1; // Засчитываем выезд со стоянки для текущей машины
                        current = current->next; // Перемещаемся к следующему элементу
                        first = false;
                    }

                }
                //Все следующик элементы
                else
                {
                    //Соответствует
                    if (current->number == SelectionCar)
                    {
                        prev->next = current->next; // Меняем ссылку на текущей элемент на следующий
                        cout << "Машина: " << SelectionCar << ", отбыла из гаража\n";
                        cout << "Кол-во удалений со стоянки: " << current->move << "\n\n";
                        delete current; //Удаляем текущий элемент
                        break;
                    }
                    //Не соответствует
                    else
                    {
                        current->move = current->move + 1; // Засчитываем выезд со стоянки для текущей машины
                        current = current->next; // Перемещаемся к следующему элементу
                        prev = prev->next; // Прошлый элемент тоже перемещаем
                    }
                }
            }
        }
            
    }
    void search(int opt, string variable)
    {
        Node* current, * prev;
        current = head;
        bool first = true;
        
        switch (opt)
        {
        case 1: // По фамилии
            while (current != nullptr)
            {
                if (current->name == variable)
                {
                    if (first)
                    {
                        first = false;
                        cout << "Найденные машины:" << endl;
                    }
                    cout << current->number << ", " << current->model << ", " << current->name << ", кол-во выездов: " << current->move << endl;
                }
                current = current->next;
            }
            if (first)
                cout << "Не найдены машины" << endl;
            cout << '\n';
            return;
        case 2: // По номеру
            while (current != nullptr)
            {
                if (current->number == variable)
                {
                    if (first)
                    {
                        first = false;
                        cout << "Найденные машины:" << endl;
                    }
                    cout << current->number << ", " << current->model << ", " << current->name << ", кол-во выездов: " << current->move << endl;
                }
                current = current->next;
            }
            if (first)
                cout << "Не найдены машины" << endl;
            cout << '\n';
            return;
        case 3: // По моделе
            while (current != nullptr)
            {
                if (current->model == variable)
                {
                    if (first)
                    {
                        first = false;
                        cout << "Найденные машины:" << endl;
                    }
                    cout << current->number << ", " << current->model << ", " << current->name << ", кол-во выездов: " << current->move << endl;
                }
                current = current->next;
            }
            if (first)
                cout << "Не найдены машины" << endl;
            cout << '\n';
            return;
        }
    }
    void list()
    {
        Node* current, * prev;
        current = head;
        bool first = true;
        while (current != nullptr)
        {
            if (first)
            {
                first = false;
                cout << "Машины в гараже:" << endl;
            }
            cout << current->number << ", " << current->model << ", " << current->name << ", кол-во выездов: " << current->move << endl;
            current = current->next;
        }
        if (first)
            cout << "В гараже нет машин" << endl;
        cout << '\n';
    }
};

void main()
{
    bool stop = true;
    int option;
    string Name;
    string Number;
    string Model;
    //setlocale(LC_ALL, "Rus");
    system("chcp 1251");
    Garage MyGarage;
    while (stop)
    {
        cout << "Меню:\n1)Прибытие машины\n2)Отъезд машины\n3)Поиск машины\n4)Список машин в гараже\n5)Выход\n";
        cout << "Введите команду: ";
        cin >> option;
        cout << '\n';
        switch (option)
        {
        case 1: // Прибытие машины
            cout << "Фамилия владельца: ";
            cin >> Name;
            cout << "Номер машины: ";
            cin >> Number;
            cout << "Модель машины: ";
            cin >> Model;
            cout << '\n';
            MyGarage.comming(Name, Number, Model);
            break;
        case 2: // Отъезд машины
            cout << "Номер машины: ";
            cin >> Name;
            cout << '\n';
            MyGarage.leave(Name);
            break;
        case 3: // Поиск машины
            cout << "Варианты поиска:\n1)Фамилия владельца\n2)Номер машины\n3)Модель машины\n";
            cout << "Фильтр поиска: ";
            cin >> option;
            start:
            switch (option)
            {
            case 1: // По фамилии
                cout << "Фамилия владельца: ";
                cin >> Name;
                cout << '\n';
                MyGarage.search(option, Name);
                break;
            case 2: // По номеру
                cout << "Номер машины: ";
                cin >> Number;
                cout << '\n';
                MyGarage.search(option, Number);
                break;
            case 3: // По моделе
                cout << "Модель машины: ";
                cin >> Model;
                cout << '\n';
                MyGarage.search(option, Model);
                break;
            default:
                cout << "Некорректная команда\n";
                goto start;
            }
            break;
        case 4: // Вывод списка машин
            MyGarage.list();
            break;
        case 5: // Выход из функции
            stop = false;
            break;
        default:
            cout << "Некорректная команда\n";
            break;
        }
    }
}
