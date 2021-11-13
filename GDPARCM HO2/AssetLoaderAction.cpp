#include "AssetLoaderAction.h"
#include "StringUtils.h"
#include "TextureManager.h"

AssetLoaderAction::AssetLoaderAction(string path, IExecutionEvent* execution_event)
{
	this->path = path;
	this->execution_event = execution_event;
}

AssetLoaderAction::~AssetLoaderAction()
{
}

void AssetLoaderAction::OnStartTask()
{
	std::vector<string> tokens = StringUtils::split(this->path, '/');
	string assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];

	TextureManager::getInstance()->instantiateAsTexture(path, assetName, true);

	this_thread::sleep_for(chrono::milliseconds(100));
	
	std::cout << "[TextureManager] Loaded streaming Texture" << assetName << endl;
	this->execution_event->OnFinishedExecution();
	
}

void AssetLoaderAction::SetPath(string path)
{
	this->path = path;
}

void AssetLoaderAction::setExecEvent(IExecutionEvent* execution_event)
{
	this->execution_event = execution_event;
}
