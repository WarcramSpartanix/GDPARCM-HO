#include "BatchWorkerCreator.h"

BatchWorkerCreator::BatchWorkerCreator(int size = 0)
{
	this->size = size;
}

BatchWorkerCreator::~BatchWorkerCreator()
{
}

void BatchWorkerCreator::OnStartTask()
{
	
}

void BatchWorkerCreator::SetSize(int size)
{
	this->size = size;
}
