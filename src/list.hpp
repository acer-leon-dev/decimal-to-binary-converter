#ifndef LIST_CPP
    #define LIST_CPP

#include <iostream>

class list;
struct node;

struct node {
    int value;
    struct node * next;

    friend std::ostream& operator << (std::ostream &out, const list& l);
};

class list {
public:
    list();
    list (const list& other);
    ~list();

    void next();
    void prev();
    int get();
    void set(int value);
    void insert(int value);
    void remove();

    friend std::ostream& operator << (std::ostream &out, const list& l);
private:
    struct node * head;
    struct node * cursor_ptr;
};

#endif // LIST_CPP