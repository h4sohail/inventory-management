#include "headers/headers.h"

/*
  Function:  printInventory
  Purpose:   print every product in the store's inventory
       in:   pointer to the InventoryType structure (the store)
   return:   void
*/
void printInventory(struct InventoryType* store) {
    int size = store->productArr->size;
    for (int i = 0; i < size; ++i) {
       
        unsigned int id = store->productArr->productTypeArr[i].id;
        char* name = store->productArr->productTypeArr[i].name;
        unsigned int units = store->productArr->productTypeArr[i].units;
        float price = store->productArr->productTypeArr[i].price;

        printf("---------------\n");
        printf("Product ID: %i \n", id);
        printf("Product name: %s \n", name);
        printf("Product units: %i \n", units);
        printf("Product price: $%.2f \n", price);
    }
}

/*
  Function:  addUnits
  Purpose:   add units to an existing product in the store
       in:   pointer to the InventoryType structure (the store)
       in:   ID of the product
       in:   amount to of units to add
   return:   status code of 0 if successful otherwise -1
*/
void addUnits(struct InventoryType* store, int productId, int productAmount) {
    unsigned int idx = getProductIndex(store, productId);

    if (idx == -1) {
        printf("Invalid product ID or the product does not exist! \n");
        return;
    }

    store->productArr->productTypeArr[idx].units += productAmount;
    char* name = store->productArr->productTypeArr[idx].name;

    printf("Added %i units to %s \n", productAmount, name);
}

/*
  Function:  buyProduct
  Purpose:   buy a unit of the product in the store inventory if it exists and is in stock
       in:   pointer to the InventoryType structure (the store)
       in:   the ID of the product
   return:   status code of 0 if successful otherwise -1
*/
int buyProduct(struct InventoryType* store, int productId) {
    int idx = getProductIndex(store, productId);
    if (idx == -1) {
        printf("Invalid product ID or the product does not exist! \n");
        return -1;
    }

	int units = store->productArr->productTypeArr[idx].units;
	char* name = store->productArr->productTypeArr[idx].name;

    if (units == 0) {
        printf("The product %s is out of stock! \n", name);
        return -1;
    }

	if (units != 0) {
		store->productArr->productTypeArr[idx].units -= 1;
		printf("Succesfully purchased 1 unit of %s", name);
        return 0;
	}
    
    return -1;
}