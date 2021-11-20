#include <iostream>
#include <List.h>

using namespace std;
// Добавление элементов в начало списка
void List::add_first(int val)
{
    Link* new_link = new Link;
    new_link->data = val;
    new_link->next = first;
    new_link->pos = 1;
    first = new_link;
    Link* temp = first->next;
    while (temp)
    {
        temp->pos++;
        temp = temp->next;
    }
}
// Добавление элементов в конец списка
void List::add_last(int val)
{
    if(!first){
        add_first(val);
        return;
    }
    Link* new_link = new Link;
    new_link->data = val;
    Link* temp = first;
    while (temp->next)
    {
        temp = temp->next;
    }
    new_link->pos = temp->pos + 1;
    temp->next = new_link;
    //delete new_link;
}
// Вывод элементов списка
void List::show()
{
    Link* temp = first;
    while (temp)
    {
      cout << temp->pos << ". " << temp->data << endl;
      temp = temp->next;
    }
    cout << endl;
}
// Получение количества элементов списка
int List::list_size()
{
    if(!first) return 0;
    Link* temp = first;
    while (temp->next)
    {
      temp = temp->next;
    }
    return temp->pos;
}
// Вставка элемента на указанную позицию
void List::insert(int val, int pos)
{
    if(pos == 1) {
        add_first(val);
        return;
    } else if(pos == this->list_size()){
        add_last(val);
        return;
    }
    Link* temp = first;
    while (temp->pos != pos - 1)
    {
      temp = temp->next;
    }
    Link* new_link = new Link;
    new_link->data = val;
    new_link->pos = pos;
    new_link->next = temp->next;
    temp->next = new_link;
    Link* temp1 = new_link->next;
    while (temp1)
    {
        temp1->pos++;
        temp1 = temp1->next;
    }
}
// Удаление всех элементов
void List::delete_all()
{
    this->~List();
}
// Удаление первого элемента списка
void List::delete_first()
{
    Link* temp = first->next;
    delete first;
    first = nullptr;
    first = temp;
    while (temp)
    {
        temp->pos--;
        temp = temp->next;
    }
}
// Удаление последнего элемента списка
void List::delete_last()
{
    Link* temp = first;
    while (temp->pos != this->list_size()-1)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
// Удаление элемента на указанной позиции
void List::delete_pos(int pos)
{
    if(pos == 1){
        delete_first();
        return;
    }
    Link* temp = first;
    while (temp->pos != pos-1)
    {
        temp = temp->next;
    }
    Link* temp1 = temp->next->next;
    delete temp->next;
    temp->next=temp1;
    while (temp1)
    {
        temp1->pos--;
        temp1 = temp1->next;
    }
}
// Удаление элементов в диапазоне между двумя указанными позициями
void List::del_interval(int a, int b)
{
    Link* temp = first;
    while (temp->pos != a)
    {
        temp = temp->next;
    }
    Link* temp1 = first;
    while (temp1->pos != b)
    {
        temp1 = temp1->next;
    }
    delete temp->next;
    temp->next = temp1;
    int i=1;
    while (temp1)
    {
        temp1->pos = a + i;
        temp1 = temp1->next;
        i++;
    }
}

int main()
{
    List list;
    list.add_last(1);
    list.add_last(2);
    list.add_last(3);
    list.add_last(4);
    list.add_last(5);
    list.add_last(6);
    list.add_last(7);
    list.del_interval(2,5);
    list.show();
    //cout << list.list_size() << endl;
    return 0;
}
