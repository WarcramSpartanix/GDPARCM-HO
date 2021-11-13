#include "StreamAssetLoader.h"
#include "StringUtils.h"
#include "TextureManager.h"
using namespace std;
StreamAssetLoader::StreamAssetLoader(std::string path, IExecutionEvent* execEvent)
{
	this->path = path;
	this->execEvent = execEvent;
}

StreamAssetLoader::~StreamAssetLoader()
{
	cout << "Destroying Stream Asset Loader." << endl;
}

void StreamAssetLoader::run()
{
	std::vector<string> tokens = StringUtils::split(this->path, '/');
	string assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];

	IETThread::sleep(1000);
	TextureManager::getInstance()->instantiateAsTexture(path, assetName, true);

	std::cout << "[TextureManager] Loaded streaming Texture" << assetName << endl;

	this->execEvent->OnFinishedExecution();
	delete this;
}
