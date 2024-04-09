#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <functional>

// Hash table class using separate chaining
template <typename K, typename V>
class HashTable {
private:
    std::vector<std::list<std::pair<K, V>>> table;
    size_t size;
    size_t buckets;
    std::function<size_t(const K&)> hashFunction;

  void resizeTable() {
  // Double the table size and rehash all elements
  size_t newTableSize = table.buckets() * 2;
  std::vector<std::list<std::pair<K, V>>> newTable(newTableSize);

  for (const auto& chain : table) {
      for (const auto& pair : chain) {
          size_t index = hashFunction(pair.first) % newTableSize;
          newTable[index].push_back(pair);
      }
    }
    table = std::move(newTable);
    buckets = newTableSize;
  }

  public:
    HashTable(size_t initialSize = 10, std::function<size_t(const K&)>   hashFunc = std::hash<K>{}) : size(0), hashFunction(hashFunc) {
        table.resize(initialSize);
        buckets = table.capacity();
    }

    void insert(const K& key, const V& value) {
        size_t index = hashFunction(key) % buckets;
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                // Key already exists; update the value
                pair.second = value;
                return;
            }
        }
        // Key doesn't exist; add a new key-value pair
        table[index].push_back(std::make_pair(key, value));
        size++;
    }

    bool get(const K& key, V& value) {
        size_t index = hashFunction(key) % buckets;
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;  // Key not found
    }

    std::vector<V> getByIndex(size_t index)
    {
      if (table[index].size() > 0)
      {
         std::vector<V> items(table[index].size());
          int i = 0;
          for (const auto &pair : table[index] )
            {
              items[i] = pair.second;
              i++;
            }
          return items;
      }
        return std::vector<V>(); 
    }

    bool remove(const K& key) {
        size_t index = hashFunction(key) % buckets;
        auto& chain = table[index];
        auto it = chain.begin();
        while (it != chain.end()) {
            std::cout << it->first << std::endl;
            if (it->first == key) {
                it = chain.erase(it);
                size--;
                return true;
            } else {
                ++it;
            }
        }
        return false;  // Key not found
    }

    size_t getSize() const {
        return size;
    }

    void display() {
        for (size_t i = 0; i < table.size(); i++) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& pair : table[i]) {
                std::cout << "(" << pair.first << ") ";
            }
            std::cout << std::endl;
        }
    }

    double getLoadFactor() const {
        // Calculate the load factor as the ratio of the number of elements to the size of the table
        return static_cast<double>(size) / table.size();
    }

  int getBuckets() const {
    return buckets;
  }

    int countCollisions() const {
      int collisionCount = 0;
      for (const auto& chain : table) {
          if (chain.size() > 1) {
              collisionCount += static_cast<int>(chain.size()) - 1;
          }
      }
      return collisionCount;
  }

  int maxBucketSize() const{
    int largestBucket = 0;
    for (const auto& chain : table) {
      if (chain.size() > largestBucket) {
          largestBucket = static_cast<int>(chain.size());
      }
    }
    return largestBucket;
  }

  void setHashFunction(std::function<size_t(const K&)> hashFunc) {
      hashFunction = hashFunc;
  }

  size_t hash(const K& key) {
      return hashFunction(key) % table.size();
  }

};


