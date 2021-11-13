#include "TextureDisplay.h"
#include <iostream>
#include "TextureManager.h"
#include "BaseRunner.h"
#include "GameObjectManager.h"
#include "IconObject.h"
TextureDisplay::TextureDisplay(): AGameObject("TextureDisplay")
{
}

void TextureDisplay::initialize()
{
	
}

void TextureDisplay::processInput(sf::Event event)
{
	
}

void TextureDisplay::update(sf::Time deltaTime)
{
	this->ticks += BaseRunner::TIME_PER_FRAME.asMilliseconds();
	
	//<code here for spawning icon object periodically>
	if (streamingType == StreamingType::SINGLE_STREAM)
	{
		if (this->ticks > STREAMING_LOAD_DELAY)
		{
			TextureManager::getInstance()->loadSingleStreamAsset(iconIndex, this);
			iconIndex++;
			this->ticks -= STREAMING_LOAD_DELAY;
		}
	}
	else if (streamingType == StreamingType::BATCH_LOAD)
	{
		if (this->ticks > 1000.0f)
		{
			TextureManager::getInstance()->loadBatchAsset(iconIndex, BATCH_SIZE, this);
			iconIndex += BATCH_SIZE;
			this->ticks -= 1000.0f;
		}
	}
}

void TextureDisplay::OnFinishedExecution()
{
	this->spawnObject();
}


void TextureDisplay::spawnObject()
{
	String objectName = "Icon_" + to_string(this->iconList.size());
	IconObject* iconObj = new IconObject(objectName, this->iconList.size() % 480);
	this->iconList.push_back(iconObj);

	//set position
	int IMG_WIDTH = 68; int IMG_HEIGHT = 68;
	float x = this->columnGrid * IMG_WIDTH;
	float y = this->rowGrid * IMG_HEIGHT;
	iconObj->setPosition(x, y);

	std::cout << "Set position: " << x << " " << y << std::endl;

	this->columnGrid++;
	if(this->columnGrid == this->MAX_COLUMN)
	{
		this->columnGrid = 0;
		this->rowGrid++;
	}
	GameObjectManager::getInstance()->addObject(iconObj);
}
