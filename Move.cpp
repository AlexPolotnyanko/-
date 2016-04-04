#include <iostream>
#include <string>
using namespace std;

/* Класс-контейнер move типа очередь */
class move
{
    move* Next;
    string Data;
public:
    move(): Next(nullptr), Data("") {};
    void push(string data);
    void get();
    void pop();
    ~move(){if(Next!= nullptr) delete Next;}
}Move;

/* Добавляет в очередь новый элемент и помещает в него указанную информацию
 * @param data - информация, помещаемая в элемент стека
 */
void move::push(string data)
{
    if(Next== nullptr)
        if(Data!="")
            Next = new move();
    else
    {
        Data = data;
        return;
    }
    Next->push(Data);
    Data = data;
}

/* Выводит информацию последнего(выходного) элемента очереди */
void move::get()
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
string move::pop()
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
    size_t n;       //Number of commands
    string line;    //Command name
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> line;
        if(line=="add")
        {
            cin >> line;
            Move.push(line);
        }
        else if(line=="get")
            Move.get();
        else if(line=="del")
            Move.pop();
        else
            return 1;

    }

    return 0;
}
