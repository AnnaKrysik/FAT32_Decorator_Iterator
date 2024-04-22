#include "Cluster.h"
#include <iostream>
using namespace std;

Cluster::~Cluster()
{
    delete[] content;
}

FileTypeEnum Cluster::GetFileType()
{
    if (content[0] == 0x46 && content[1] == 0x4F && content[2] == 0x52 && content[3] == 0x4D) {
        return  FileTypeEnum::Txt;
    }
    else if (content[0] == 0x89 && content[1] == 0x50 && content[2] == 0x4E && content[3] == 0x47) {
        return  FileTypeEnum::Png;
    }
    return FileTypeEnum::Underfind;
}


Cluster::Cluster(BYTE* data, unsigned int num, unsigned int ClusterSize)
{
    content = new BYTE[ClusterSize];
    std::memcpy(content, data, sizeof(BYTE) * ClusterSize);
    clusterNum = num;
}
void Cluster::SetContent(BYTE* data, unsigned int ClusterSize)
{
    content = new BYTE[ClusterSize];
    std::memcpy(content, data, sizeof(BYTE) * ClusterSize);
}
