#include <iostream>

struct Pila
{
    void Push(int ci, int edad)
    {
        auto nodo = new Nodo{ci, edad, top};
        top = nodo;
    }

    void Pop(int ci)
    {
        if (top)
        {
            if (top->ci == ci)
            {
                auto nodo = top;
                top = top->siguiente;
                delete nodo;
            }
            else if (auto nodo = buscar_anterior(ci))
            {
                auto borrar = nodo->siguiente;
                nodo->siguiente = borrar->siguiente;
                delete borrar;
            }
        }
    }
    
private:

    struct Nodo
    {
        int ci = 0, edad = 0;
        Nodo *siguiente = nullptr;
    };
    
    Nodo *buscar_anterior(int ci)
    {
        for (auto nodo = top; nodo && nodo->siguiente; nodo = nodo->siguiente)
            if (nodo->siguiente->ci == ci)
                return nodo;

        return nullptr;
    }
    
    Nodo *top = nullptr;

    friend std::ostream &operator<<(std::ostream &, const Pila &);
    friend std::ostream &operator<<(std::ostream &, const Pila::Nodo &);
};

std::ostream &operator<<(std::ostream &o, const Pila::Nodo &nodo)
{
    if (nodo.siguiente)
    {
        o << *nodo.siguiente;
    }
    
    return o << '{' << nodo.ci << ',' << nodo.edad << '}';
}

std::ostream &operator<<(std::ostream &o, const Pila &p)
{
    return p.top ? o << *p.top : o;
}

int main()
{
    Pila p;
    p.Push(1,10);
    p.Push(2,20);
    p.Push(3,30);
    p.Push(4,40);
    p.Push(5,50);
    p.Push(6,60);
    std::cout << p << '\n' << '\n';
    p.Pop(4);
    std::cout << p << '\n' << '\n';
    p.Pop(1);
    std::cout << p << '\n' << '\n';
    return 0;
}
