#include "hash_table.h"

using namespace std;

HashTable::HashTable() : table(TABLE_SIZE), size(0) {}

int HashTable::hashFunction(const std::string &word)
{
    int hash = 0;
    for (char ch : word)
    {
        hash = (hash + ch) % TABLE_SIZE;
    }
    return hash;
}

void HashTable::insertKey(const std::string &word, int index)
{
    int hashIndex = hashFunction(word);
    while (table[hashIndex].prK)
    {
        if (table[hashIndex].word == word)
        {
            table[hashIndex].count++;
            return;
        }
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
    }
    table[hashIndex].word = word;
    table[hashIndex].count = 1;
    table[hashIndex].index = index;
    table[hashIndex].prK = true;
    size++;
}

void HashTable::deleteKey(const std::string &word)
{
    int hashIndex = hashFunction(word);
    while (table[hashIndex].prK)
    {
        if (table[hashIndex].word == word)
        {
            table[hashIndex].prK = false;
            size--;
            return;
        }
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
    }
}

int HashTable::findKey(const std::string &word)
{
    int hashIndex = hashFunction(word);
    while (table[hashIndex].prK)
    {
        if (table[hashIndex].word == word)
        {
            return table[hashIndex].index;
        }
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
    }
    return -1;
}

void HashTable::printTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i].prK)
        {
            std::cout << "Index: " << i << ", Word: " << table[i].word << ", Count: " << table[i].count << ", Array Index: " << table[i].index << std::endl;
        }
        else
        {
            std::cout << "Index: " << i << ", Empty" << std::endl;
        }
    }
}

void HashTable::rehashTable()
{
    std::vector<HashTableElement> oldTable = table;
    table = std::vector<HashTableElement>(TABLE_SIZE);
    size = 0;
    for (const auto &element : oldTable)
    {
        if (element.prK)
        {
            insertKey(element.word, element.index);
        }
    }
}

void HashTable::createHashTable(const std::vector<std::string> &words)
{
    cout << "createHashTable" << endl;

    for (size_t i = 0; i < words.size(); i++)
    {
        insertKey(words[i], i);
    }
}