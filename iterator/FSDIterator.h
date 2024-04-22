#pragma once
#include "DIterator.h"
#include "Cluster.h"
#include <iostream>
class FSDIterator :public DIterator<Cluster>
{
private:
	FileTypeEnum TargetFile;
public:
	FSDIterator(Iterator<Cluster>* it, FileTypeEnum targetFile) : DIterator(it) {
		TargetFile = targetFile;
	}
	void First();
	void Next();
};

