#include "FSDIterator.h"

void FSDIterator::First()
{
	It->First();
	while (!It->IsDone() && It->GetCurrent().GetFileType() != TargetFile) {
		It->Next();
	}

}
void FSDIterator::Next()
{
	do {
		It->Next();
	} while (!It->IsDone() && It->GetCurrent().GetFileType() != TargetFile);
}
