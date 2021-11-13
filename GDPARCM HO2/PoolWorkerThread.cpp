#include "PoolWorkerThread.h"
#include "IWorkerAction.h"
#include "IFinishedTask.h"

PoolWorkerThread::PoolWorkerThread(int id, IFinishedTask* finished_task)
{
	this->id = id;
	this->finishedTask = finished_task;
}

PoolWorkerThread::~PoolWorkerThread()
{
}

int PoolWorkerThread::getThreadID()
{
	return this->id;
}

void PoolWorkerThread::AssignTask(IWorkerAction* action)
{
	this->action = action;
}

void PoolWorkerThread::run()
{
	this->action->OnStartTask();
	this->finishedTask->onFinished(this->id);
}
