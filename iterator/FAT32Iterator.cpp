#include "FAT32Iterator.h"

Cluster FAT32Iterator::GetCurrent()
{
    Cluster item;
    if (!fat32->ReadCluster(&item, cursor)) {
        throw std::invalid_argument("Error read cluster!");
    }
    return item;
}
