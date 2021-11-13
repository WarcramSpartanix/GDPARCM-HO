#pragma once
#include "IWorkerAction.h"
#include "IExecutionEvent.h"
class BatchAssetLoaderAction :
    public IWorkerAction
{
public:
    BatchAssetLoaderAction(int startIndex, int batchSize, IExecutionEvent* execEvent);
    ~BatchAssetLoaderAction();
    void OnStartTask() override;
    void SetValues(int startIndex, int batchSize, IExecutionEvent* execEvent);

private:
    int startIndex;
    int batchSize;
    IExecutionEvent* execEvent;
};

