#include "headers.h"

int main() {
    struct InventoryType* store = malloc(sizeof(struct InventoryType));
    makeStore(store);
    startInterface(store);
    free(store);
    return 0;
}