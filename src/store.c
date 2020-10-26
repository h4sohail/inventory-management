#include "headers/headers.h"

#define INITIAL_ID 10001
#define MAX_PRODUCTS 10

/*
  Function:  makeStore
  Purpose:   initialize the store by allocating the memory and adding some products
       in:   pointer to the InventoryType structure (the store)
   return:   void
*/
void makeStore(struct InventoryType* store) {
    // Allocate memory
    store->productArr = malloc(sizeof(struct ProductArrType));
    store->productArr->productTypeArr = (struct ProductType*)malloc(10 * sizeof(struct ProductType));
   
    // Initialize the fields
    strcpy(store->name, "Watt's Up Electronic Store");
    store->productArr->id = INITIAL_ID;
    store->productArr->size = 0;

    // Add dummy products
    addProduct(store, "Gaming Desktop", 1999.00, 39);
    addProduct(store, "Business Desktop",999.00, 39);
    addProduct(store, "Server Desktop",799.00, 39);
    addProduct(store, "Gaming Laptop", 1999.89, 25);
    addProduct(store, "Smart Fridge", 2478.98, 11);
    addProduct(store, "Smart TV", 499.89, 9);
    addProduct(store, "Smart Toaster", 55.89, 14);
    addProduct(store, "Quantum Computer", 9999.89, 2);
    addProduct(store, "Smart Nuke", 99999.98, 1);
}

/*
  Function:  addProduct
  Purpose:   add a product to the products array in the store
       in:   pointer to the InventoryType structure (the store)
       in:   name of the store
       in:   price of the product
       in:   amount of units
   return:   void
*/
void addProduct(struct InventoryType* store, char* name, float price, unsigned int units) {
    // Check for the limit of max products
    if (store->productArr->size > MAX_PRODUCTS)
        return;

    // Get the product in the product array
    struct ProductType* product = &store->productArr->productTypeArr[store->productArr->size]; 

    // Set the fields
    product->id = store->productArr->id;
    product->units = units;
    product->price = price;
    strcpy(product->name, name);

    // Increment ID and the size
    store->productArr->size++;
    store->productArr->id++;
}
