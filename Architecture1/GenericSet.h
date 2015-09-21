//
// Created by alexey on 20.09.15.
//

#ifndef ARCHITECTURE1_GENERICSET_H
#define ARCHITECTURE1_GENERICSET_H

#include <set>
#include <algorithm>

using namespace std;

template <class Type>
class GenericSet {
public:
    /*
     * Конструктор за замовченням.
     */
    GenericSet(){
        s = set<Type>();
    };

    /*
     * Деструктор за замовченням.
     */
    ~GenericSet(){
        s.clear();
    };

    /*
     * Додає елемент у множину.
     */
    void add(const Type& element){
        s.insert(element);
    };

    /*
     * Видаляє елемент із множини.
     */
    void remove(const Type& element){
        s.erase(element);
    };

    /*
     * Виконує операцію об'єднання з іншою множиною.
     */
    void combine(const GenericSet& other){
        for(typename set<Type>::iterator it = other.s.cbegin(), end = other.s.cend(); it != end; it++){
            add(*it);
        }
    };

    /*
     * Виконує операцію перетину з іншою множиною.
     */
    void intersect(const GenericSet& other){

        /*
         * Якщо елемент знаходиться у вихідній множині та його немає у іншій,
         * то він з вихідної множини видаляється.
         */
        for(typename set<Type>::iterator it = s.cbegin(), end = s.cend(); it != end; it++){
            if(other.s.end() == other.s.find(*it)){
                remove(*it);
            }
        }
    }

    /*
     * Виконує операцію різниці з іншою множиною.
     */
    void differentiate(const GenericSet& other){

        /*
         * Якщо елемент знаходиться у вихідній множині та у іншій,
         * то він з вихідної множини видаляється.
         */
        for(typename set<Type>::iterator it = s.cbegin(), end = s.cend(); it != end; it++){
            if(other.s.end() != other.s.find(*it)){
                s.erase(*it);
            }
        }
    }

private:
    set<Type> s;
};


#endif //ARCHITECTURE1_GENERICSET_H
