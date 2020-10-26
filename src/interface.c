#include "headers/headers.h"

/*
  Function:  startInterface
  Purpose:   start the command line interface to let a client interact with the store
       in:   pointer to the InventoryType structure (the store)
   return:   void
*/
void startInterface(struct InventoryType* store) {
    int productId;
    int productAmount;
    float total = 0;
    unsigned int choice;

    do {
        printf("\nCommands: \n");
        printf("1: Show the inventory\n2: Add a stock to a product\n3: Buy a product\n4: Exit\n");
        printf("\n-The current total is $%.2f\n", total);
        printf("->");
        scanf("%u", &choice);

        switch(choice) {
            case 1:
                printInventory(store);
                break;
            case 2:
                printf("\nPlease enter the product ID: \n");
                printf("->");
                scanf("%i", &productId);
                
                if (productId < 1) {
                    printf("Incorrect selection, please try again.\n");
                    break;
                }

                printf("\nPlease enter the amount of units to add: ");
                printf("->");
                scanf("%i", &productAmount);

                if (productAmount < 1) {
                    printf("Incorrect selection, please try again.\n");
                    break;
                }

                addUnits(store, productId, productAmount);
                break;
            case 3:
                printf("\nPlease enter the product ID: \n");
                printf("->");
                scanf("%d", &productId);  

                if (productId < 1) {
                    printf("Incorrect selection, please try again.\n");
                    break;
                }

                // Check the response code returned by buyProduct
                int status = buyProduct(store, productId);
                
                if (status != -1) {
                    // Get the index of the product in the store and the price
                    int idx = getProductIndex(store, productId);
                    float price = store->productArr->productTypeArr[idx].price;
                    total += price; // Update the total
                    break;
                }
                break;
            case 4:
                printf("Good bye!\n");
                return;
            default:
                printf("The input was invalid!\n");
                return;
        }
    } while(choice != 4);
}
