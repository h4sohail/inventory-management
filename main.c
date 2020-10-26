#include "src/headers/headers.h"

int main() {
    struct InventoryType* store = malloc(sizeof(struct InventoryType));
    makeStore(store);
    startInterface(store);

    // Free the memory allocated for the store
    free(store->productArr->productTypeArr);
    free(store->productArr);
    free(store);
    return 0;
}