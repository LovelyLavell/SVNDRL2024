#ifndef TLIST_H_INCLUDED
#define TLIST_H_INCLUDED
//Apparently C++ has lists now, I don't need to do this but I haven't made a linked list since college
//I will use the C++ list, they are objectively better but there are some things I want to do myself
class TList<T>{
    T * last;
    T * next;
public:
    //Add
    void Push(T &value);
    void Insert(T &value);
    //Remove
    void Pop();
    void Delete(int i);
    void Delete(T &value)
};

#endif // TLIST_H_INCLUDED
