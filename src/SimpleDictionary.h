//inspired by: https://forum.arduino.cc/t/dictionary-object/651568/8

#ifndef SIMPLE_DICTIONARY_H
#define SIMPLE_DICTIONARY_H

//template<typename ValueType, size_t ElementSize=5, size_t KeySize=10>

template<typename ValueType, size_t ElementSize, size_t KeySize>
class SimpleDictionary
{
    static_assert(std::is_same<ElementSize, int>::value, "ElementSize must be int");
    static_assert(std::is_same<KeySize, int>::value, "KeySize must be int");

public:
    SimpleDictionary() :
        Keys{{}},
        Values{}
    {
    }

    ValueType& operator[](const char* InKey)
    {
        int Index = LocateKey(InKey);
        if (Index == -1)
        {
            Index = LocateKey("");
        }
        if (Index != -1)
        {
            strncpy(Keys[Index], InKey, KeySize);
        } else
        {
            //The dictionary is full at this point
            //no handle
        }
        return Values[Index];
    }

    char* getKey(int index)
    {
        if (index >= 0 && index < ElementSize) {
            return Keys[index];
        } else {
            return nullptr; // or handle the error appropriately
        }
    }

    ValueType getValue(int index)
    {
        if (index >= 0 && index < ElementSize) {
            return Values[index];
        } else {
            return ValueType(); // Return a default-constructed ValueType;            
        }
    }

    // void insert(const char* InKey, ValueType value) {
    //     char buffer[20];
    //     int value = millis();
    //     sprintf(buffer, "t%d", value);
    // }


    int size()
    {
        return ElementSize;
    }
private:
    char Keys[ElementSize][KeySize];
    ValueType Values[ElementSize];
    int LocateKey(const char* InKey)
    {
        for (size_t i=0; i<ElementSize; ++i)
        {
            if (strncmp(Keys[i], InKey, KeySize) == 0)
            {
                return i;
            }
        }
        return -1;
    }
};


#endif //SIMPLE_DICTIONARY_H