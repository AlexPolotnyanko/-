#include <iostream>
#include <string>
using namespace std;

/* Класс-контейнер turn типа очередь */
class turn
{
    turn* Next;
    string Data;
public:
    turn(): Next(nullptr), Data("") {};
    void push(string data);
    void get();
    void pop();
    ~turn(){if(Next!= nullptr) delete Next;}
}Turn;

/* Добавляет в очередь новый элемент и помещает в него указанную информацию
 * @param data - информация, помещаемая в элемент стека
 */
void turn::push(string data)
{
    if(Next== nullptr)
        if(Data!="")
            Next = new turn();
    else
    {
        Data = data;
        return;
    }
    Next->push(Data);
    Data = data;
}

/* Выводит информацию последнего(выходного) элемента очереди */
void turn::get()
{
    if(Next== nullptr)
    {
        cout << Data << endl;
        return;
    }
    Next->get();
}

/* Возвращает содержимое последнего(выходного) элемента списка и удаляет его
 * @return - содержимое последнего(выходного) элемента списка
 */
string turn::pop()
{
	string temp = Data;
    if(Next == nullptr)
    {
        Data = "";
        return temp;
    }
    else
        return Next->pop();
}

int main()
{
    size_t n;
    string line;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> line;
        if(line=="add")
        {
            cin >> line;
            Turn.push(line);
        }
        else if(line=="get")
            Turn.get();
        else if(line=="del")
            Turn.pop();
        else
            return 1;

    }

    return 0;
}
