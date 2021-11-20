#ifndef LIST_H
#define LIST_H

struct Link{
    int pos;                   //позиция
    int data;
    Link* next = nullptr;
};

class List{
private:
    Link* first;
public:
    List(){
        first = nullptr;
    }
    ~List(){
        delete first;
        first = nullptr;
    }
    void add_first(int);
    void add_last(int);
    void show();
    int list_size();
    void insert(int, int);
    void delete_all();
    void delete_first();
    void delete_last();
    void delete_pos(int);
    void del_interval(int, int);
};

#endif // LIST_H
