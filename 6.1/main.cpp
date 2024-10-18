#include "hash_table.h"

using namespace std;

void testHeshT()
{
    cout << "testHeshT" << endl;

    HashTable hashTable;
    std::vector<std::string> words = {
        "apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon",
        "mango", "nectarine", "orange", "papaya", "quince", "raspberry", "strawberry", "tangerine", "ugli", "vanilla"};

    hashTable.createHashTable(words);
    hashTable.printTable();

    std::cout << "\nInserting word 'watermelon'...\n";
    hashTable.insertKey("watermelon", 20);
    hashTable.printTable();

    std::cout << "\nDeleting word 'cherry'...\n";
    hashTable.deleteKey("cherry");
    hashTable.printTable();

    std::cout << "\nFinding word 'date'...\n";
    int index = hashTable.findKey("date");
    if (index != -1)
    {
        std::cout << "Word 'date' found at index " << index << std::endl;
    }
    else
    {
        std::cout << "Word 'date' not found" << std::endl;
    }

    std::cout << "\nRehashing table...\n";
    hashTable.rehashTable();
    hashTable.printTable();
}

int main()
{
    cout << "program start" << endl;
    testHeshT();
    return 0;
}