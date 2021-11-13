#include "BatchAssetLoaderAction.h"
#include "TextureManager.h"

BatchAssetLoaderAction::BatchAssetLoaderAction(int startIndex = 0, int batchSize = 0, IExecutionEvent* execEvent = nullptr)
{
	this->startIndex = startIndex;
	this->batchSize = batchSize;
	this->execEvent = execEvent;
}

BatchAssetLoaderAction::~BatchAssetLoaderAction()
{}

void BatchAssetLoaderAction::OnStartTask()
{
	for (int i = startIndex; i < startIndex + batchSize; i++)
	{
		TextureManager::getInstance()->loadBatchAsset(i, new AssetLoaderAction(""), execEvent);
	}
}

void BatchAssetLoaderAction::SetValues(int startIndex, int batchSize, IExecutionEvent* execEvent)
{
	this->startIndex = startIndex;
	this->batchSize = batchSize;
	this->execEvent = execEvent;
}