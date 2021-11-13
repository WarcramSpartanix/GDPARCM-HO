#pragma once
#include "IETThread.h"
#include <string>
#include "IExecutionEvent.h"
class StreamAssetLoader :
    public IETThread
{
public:
	StreamAssetLoader(std::string path, IExecutionEvent* execEvent);
	~StreamAssetLoader();

private:
	void run() override;
	std::string path;
	IExecutionEvent* execEvent;
};

