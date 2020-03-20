#include "Lista.h"

using namespace std;

// Constructor por defecto
template <typename T>
Lista<T>::Lista()
{
    sizeL = 0;
    m_head = NULL;
    m_last = NULL;
}

//devuelve el tamanio de la lista

// Insertar al inicio
template <typename T>
void Lista<T>::add_headS(T data_)
{
    Node<T> *new_node = new Node<T>(data_);
    if (m_head == nullptr)
    {
        m_head = m_last = new_node;
    }
    else
    {
        new_node->setNext(m_head);
        m_head = new_node;
    }
    sizeL++;
}

// Insertar al final
template <typename T>
void Lista<T>::add_endS(T data_)
{
    Node<T> *new_node = new Node<T>(data_);

    if (isEmptyS())
    {
        m_head = m_last = new_node;
    }
    else
    {
        m_last->setNext(new_node);
        m_last = new_node;
    }
    sizeL++;
}

// Insertar de manera ordenada
template <typename T>
void Lista<T>::add_sort(T data_)
{
    Node<T> *new_node = new Node<T>(data_);
    Node<T> *temp = m_head;

    if (!m_head)
    {
        m_head = new_node;
    }
    else
    {
        if (m_head->getData() > data_)
        {
            new_node->setNext(m_head);
            m_head = new_node;
        }
        else
        {
            while ((temp->getNext() != NULL) && (temp->getNext()->getData() < data_))
            {
                temp = temp->getNext();
            }
            new_node->setNext(temp->getNext());
            temp->setNext(new_node);
        }
    }
    sizeL++;
}

//agregar al final de una lista cicular
template<typename T>
void Lista<T>::add_endC(T data_){
    Node<T>* new_node = new Node<T>(data_);
    if (m_last == nullptr) {
        m_last = new_node;
        m_last->setNext(m_last);
        sizeL++;
    } else {
        new_node->setNext(m_last->getNext());
        m_last->setNext(new_node);
        m_last = new_node;
        sizeL++;
    }
}

//eliminar al principio tipo pop para pila
template <typename T>
void Lista<T>::del_headS()
{
    if (!isEmptyS())
    {
        m_head = m_head->getNext();
        sizeL--;
    }
    else
    {
        cout<<"Lista vacia\n";
    }
}

// Eliminar todos los nodos
template <typename T>
void Lista<T>::del_all()
{
    m_head->delete_all();
    m_head = 0;
}

// Eliminar por data del nodo
//template<typename T>
//void Lista<T>::del_by_data(T data_)
//{
//    Node<T> *temp = m_head;
//    Node<T> *temp1 = m_head->next;
//
//    int cont = 0;
//
//    if (m_head->data == data_) {
//        m_head = temp->next;
//    } else {
//        while (temp1) {
//            if (temp1->data == data_) {
//                Node<T> *aux_node = temp1;
//                temp->next = temp1->next;
//                delete aux_node;
//                cont++;
//                sizeL--;
//            }
//            temp = temp->next;
//            temp1 = temp1->next;
//        }
//    }
//
//    if (cont == 0) {
//        cout << "No existe el dato " << endl;
//    }
//}
//
//// Eliminar por posición del nodo
//template<typename T>
//void Lista<T>::del_by_position(int pos)
//{
//    Node<T> *temp = m_head;
//    Node<T> *temp1 = temp->next;
//
//    if (pos < 1 || pos > sizeL) {
//        cout << "Fuera de rango " << endl;
//    } else if (pos == 1) {
//        m_head = temp->next;
//    } else {
//        for (int i = 2; i <= pos; i++) {
//            if (i == pos) {
//                Node<T> *aux_node = temp1;
//                temp->next = temp1->next;
//                delete aux_node;
//                sizeL--;
//            }
//            temp = temp->next;
//            temp1 = temp1->next;
//        }
//    }
//}
//

//// Invertir la lista
//template<typename T>
//void Lista<T>::invert()
//{
//    Node<T> *prev = NULL;
//    Node<T> *next = NULL;
//    Node<T> *temp = m_head;
//
//    while (temp) {
//        next = temp->next;
//        temp->next = prev;
//        prev = temp;
//        temp = next;
//    }
//    m_head = prev;
//}

// Imprimir la Lista
template <typename T>
void Lista<T>::printS()
{
    Node<T> *temp = m_head;
    if (!m_head)
    {
        cout << "La Lista está vacía " << endl;
    }
    else
    {
        while (temp != nullptr)
        {
            cout << temp->getData() << "-->";
            temp = temp->getNext();
        }
        cout << "\n";
    }
}
//iprimir una lista circular
template<typename T>
void Lista<T>::printC() {
    Node<T>* aux = m_last->getNext();
    if (!isEmptyC()) {
        do {
            std::cout << aux->getData() <<"==>";
            aux = aux->getNext();
        } while (aux != m_last->getNext());
    } else {
        std::cout << "Lista Vacia";
    }
    cout<<"\n";
}

// metod privado para busqueda en general
template<typename T>
Node<T>* Lista<T>::searchAll(Node<T>* n, T data_)
{
    if (n==m_head)
    {
        while (n!=nullptr)
        {
            if (n->getData()==data_)
            {
                return n;
            }
            n = n->getNext();
        }
        cout<<"No se encontro el dato\n";
        return nullptr; 
    }else if (n == m_last)
    {
        Node<T>* aux = m_last->getNext();
        do
        {
            if (aux->getData() == data_)
            {
               return aux;
            }
            aux = aux->getNext();
        } while (aux!= m_last->getNext());
        cout<<"No existe el dato\n";
        return nullptr;
    }
}

//metodo publico para buscar
template<typename T>
Node<T>* Lista<T>::search(T data_){
    if (m_head!=nullptr)
    {
        searchAll(m_head, data_);
    }else if (m_last!=nullptr )
    {
        searchAll(m_last, data_);
    }
} 

// Ordenar de manera ascendente
//template<typename T>
//void Lista<T>::sort()
//{
//    T temp_data;
//    Node<T> *aux_node = m_head;
//    Node<T> *temp = aux_node;
//
//    while (aux_node) {
//        temp = aux_node;
//
//        while (temp->getNext()) {
//            temp = temp->getNext();
//
//            if (aux_node->getData() > temp->getData()) {
//                temp_data = aux_node->getData();
//                aux_node->data = temp->data;
//                temp->data = temp_data;
//            }
//        }
//        aux_node = aux_node->next;
//    }
//}
//
// Guardar una lista en un archivo
//template<typename T>

//devuelve un true si simple la lista esta vacia
template <typename T>
bool Lista<T>::isEmptyS()
{
    if (m_head != nullptr)
    {
        return false;
    }
    return true;
}

//devuelve un true si la lista ciruclar esta vacia
template<typename T>
bool Lista<T>::isEmptyC(){
    if (m_last == nullptr)
    {
        return true;
    }
    return false;
}


template <typename T>
Lista<T>::~Lista() {}