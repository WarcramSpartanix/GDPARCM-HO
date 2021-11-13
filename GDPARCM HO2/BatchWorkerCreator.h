#pragma once
#include "IWorkerAction.h"
class BatchWorkerCreator :
    public IWorkerAction
{
public:
    BatchWorkerCreator(int size);
    ~BatchWorkerCreator();
    void OnStartTask() override;
    void SetSize(int size);
private:
    int size;
};

