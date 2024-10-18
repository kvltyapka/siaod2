#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <string>
#include <vector>

#define TABLE_SIZE 11

struct HashTableElement
{
    std::string word;
    int count;
    int index;
    bool prK;

    HashTableElement() : word(""), count(0), index(-1), prK(false) {}
};

class HashTable
{
public:
    HashTable();
    int hashFunction(const std::string &word);
    void insertKey(const std::string &word, int index);
    void deleteKey(const std::string &word);
    int findKey(const std::string &word);
    void printTable();
    void rehashTable();
    void createHashTable(const std::vector<std::string> &words);

private:
    std::vector<HashTableElement> table;
    int size;
};

#endif