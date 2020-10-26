#include "headers/headers.h"

/*
  Function:  getProductIndex
  Purpose:   get the index of a product in the product array of the store given the product ID
       in:   pointer to the InventoryType structure (the store)
       in:   id of the product
   return:   -1 if the product is not in the array, else the index of the product
*/
int getProductIndex(struct InventoryType* store, int productId) {
    int size = store->productArr->size;
    for(int i = 0; i < size; ++i) {
        if(store->productArr->productTypeArr[i].id == productId) {
            return i;
        }
    }
    return -1;
}