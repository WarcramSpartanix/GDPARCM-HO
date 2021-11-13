#pragma once
#include "string"
#include "IWorkerAction.h"
#include "IExecutionEvent.h"

using namespace std;

class AssetLoaderAction : public IWorkerAction
{
public:
	AssetLoaderAction(string path, IExecutionEvent* execution_event = nullptr);
	~AssetLoaderAction();
	void OnStartTask() override;
	void SetPath(string path);
	void setExecEvent(IExecutionEvent* execution_event);
private:
	string path;
	IExecutionEvent* execution_event;
};

