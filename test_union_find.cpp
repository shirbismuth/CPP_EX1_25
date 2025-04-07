#include "union_find.hpp"
#include <cassert>
#include <iostream>

void testUnionFindUnite() {
    graph::UnionFind uf(5);  // יצירת UnionFind עם 5 אלמנטים
    uf.unite(0, 1);  // חיבור בין קודקודים 0 ו-1
    uf.unite(1, 2);  // חיבור בין קודקודים 1 ו-2
    assert(uf.connected(0, 2) == true);  // קודקודים 0 ו-2 חייבים להיות מחוברים

}

void testUnionFindConnected() {
    graph::UnionFind uf(5);  // יצירת UnionFind עם 5 אלמנטים
    uf.unite(0, 1);
    uf.unite(1, 2);
    assert(uf.connected(0, 1) == true);  // 0 ו-1 מחוברים
    assert(uf.connected(0, 2) == true);  // 0 ו-2 מחוברים
    assert(uf.connected(0, 3) == false); // 0 ו-3 לא מחוברים

}

void testUnionFindFind() {
    graph::UnionFind uf(5);  // יצירת UnionFind עם 5 אלמנטים
    uf.unite(0, 1);
    uf.unite(1, 2);
    assert(uf.find(0) == uf.find(2));  // 0 ו-2 צריכים להיות באותו קבוצה
    assert(uf.find(0) != uf.find(3));  // 0 ו-3 לא צריכים להיות באותו קבוצה

}

void testUnionFindInvalidIndex() {
    try {
        graph::UnionFind uf(5);
        uf.unite(0, 6);  // אינדקס מחוץ לטווח
        assert(false);  // אם הגעת לכאן, הטסט נכשל
    } catch (const std::out_of_range& e) {
        std::cout << "testUnionFindInvalidIndex passed! " << e.what() << std::endl;
    }
}

