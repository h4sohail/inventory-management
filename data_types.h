#define MAX_NAME_LENGTH 32

// Data types
struct ProductType {
    unsigned int id;
    char name[MAX_NAME_LENGTH];
    unsigned int units;
    float price;
};

struct ProductArrType {
    unsigned id;
    int size;
    struct ProductType* productTypeArr;
};

struct InventoryType {
    char name[MAX_NAME_LENGTH];
    struct ProductArrType* productArr;
};

