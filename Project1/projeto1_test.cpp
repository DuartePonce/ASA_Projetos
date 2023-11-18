#include <iostream>
#include <list>
#include <vector>

typedef struct tile{
    int x, y, price, quality; //Variable quality is only for testing for now i will work it out
    struct tile* next;
} tile;

void createTile (tile* tile, int a, int b, int p, int q) { //Function that creates and gives the values of a tile
    tile->x = a;
    tile->y = b;
    tile->price = p;
    tile->quality = q;
    tile->next = NULL;
}

void insertFuntion (tile** tileLinkedList, int a, int b, int p, int q) {
    tile* tileList = *tileLinkedList;
    tile* newTile = (tile*) malloc(sizeof(tile));
    createTile(newTile, a, b, p, q);
    if (tileList == NULL) { //Verifies if the linked list has anyting
        *tileLinkedList = newTile;//creates the first element of the list
    } else {
        while(tileList != NULL && q != 0){//iteration to go through the list q is bulshit for now there
            if(q >= tileList->quality) {//first step in wich i insert in the front
                *tileLinkedList = newTile;
                newTile->next = tileList;
                q = 0;//bullshit
            }

            tileList = tileList->next;
        }
    }
}

int main() {
    int x, y, n, a, b, p;
    tile *tileLinkedList = NULL;
    std::cin >> x >> y;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::cin >> a >> b >> p;
        int quality = i;
        insertFuntion(&tileLinkedList, a, b, p, quality);
    }   

    return 0;
}