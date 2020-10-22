#include "headers.h"

int main() {
    struct InventoryType* store = malloc(sizeof(struct InventoryType));
    makeStore(store);
    startInterface(store);
    return 0;
}