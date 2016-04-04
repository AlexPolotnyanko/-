#include <iostream>
#include <string>
using namespace std;

/* Класс-контейнер stack типа стэк */
class st
{
    st* Next;
    string Data;
public:
    st(): Next(nullptr), Data("") {};
    void push(string data);
    void get();
    string pop();
    ~st(){if(Next!= nullptr) delete Next;}
}St;

/* Добавляет в стек новый элемент и помещает в него указанную информацию
 * @param data - информация, помещаемая в элемент стека
 */
void st::push(string data)
{
    if(Next== nullptr)
        if(Data!="")
            Next = new stack();
        else
        {
            Data = data;
            return;
        }
    Next->push(Data);
    Data = data;
}

/* Выводит информацию первого(верхнего) элемента стека */
void st::get()
{
    cout << Data << endl;
}

/* Возвращает содержимое первого элемента стека и удаляет его
 * @return - содержимое первого(верхнего) элемента стека
 */
string st::pop()
{
    string temp = Data;
    if(Next!= nullptr)
        Data = Next->pop();
    else
        Data = "";
    return temp;
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
            St.push(line);
        }
        else if(line=="get")
            St.get();
        else if(line=="del")
            St.pop();
        else
            return 1;

    }

    return 0;
}
