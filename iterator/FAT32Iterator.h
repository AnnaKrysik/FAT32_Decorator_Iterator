#pragma once
#include "Iterator.h"
#include "FAT32.h"

class FAT32Iterator : 
    public Iterator<Cluster> 
{
private:
    FAT32* fat32;
    unsigned int count; //общее кол-во кластеров
    unsigned int cursor; //указатель текущей позиции итератора
public:
    FAT32Iterator(FAT32* fsItem) : Iterator<Cluster>(fsItem->ClusterCount()) {
        fat32 = fsItem;
        count = fat32->ClusterCount();
        cursor = 0;
    }

    void First() { cursor = 0; }
    void Next() { cursor++; }
    bool IsDone() const { return (cursor >= count); }
    Cluster GetCurrent();
};