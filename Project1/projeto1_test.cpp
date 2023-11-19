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
            if(q >= tileList->quality) {//first step in wich i insert in the front   good
                *tileLinkedList = newTile;
                newTile->next = tileList;
                q = 0;//bullshit
            } else if (tileList->next != NULL && tileList->next->quality < q) { //Case to add in the middle 
                tile* tileAuxiliar = tileList->next;//auxiliar tile pointer to save the integrity of the linked list
                tileList->next = newTile;
                newTile->next = tileAuxiliar;
                q = 0;//bullshit
            } else if (tileList->next == NULL) { //Case to add in the end
                tileList->next = newTile;
                q = 0;//bullshit
            }
            tileList = tileList->next;
        }
    }
}


int totalTileValuation(tile** tileLinkedList, int x, int y) {
    tile* tileList = *tileLinkedList;


    if (tileList == NULL) {
        return 0;
    } else if (tileList->x > x && tileList->y > y) { //Review
        return 0;
    } else if (x == 0 || y == 0) {
        return 0;
    } else if (tileList->x > x || tileList->y > y) {
        // Verify linked list
        return totalTileValuation(&tileList->next, x, y);
    } else {
        return tileList->price + totalTileValuation(&tileList, tileList->x, (y - tileList->y)) +
           totalTileValuation(&tileList, (x - tileList->x), tileList->y) + 
           totalTileValuation(&tileList, (x - tileList->x), (y - tileList->y));
    }
}

int main() {
    int x, y, n, a, b, p;
    tile *tileLinkedList = NULL;
    std::cin >> x >> y;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::cin >> a >> b >> p;
        int quality = p / (a * b);
        insertFuntion(&tileLinkedList, a, b, p, quality);
    } 
    printf("%d", totalTileValuation(&tileLinkedList, x, y));
    return 0;
}   