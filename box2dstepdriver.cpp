#include "box2dstepdriver.h"
#include "box2dworld.h"

AnimationDriver::AnimationDriver(Box2DWorld *world) :
	QAbstractAnimation(),
	mWorld(world)
{
	setLoopCount(-1); // loop forever
}

int AnimationDriver::duration() const
{
	return 1000;
}

void AnimationDriver::start()
{
	QAbstractAnimation::start();
}

void AnimationDriver::stop()
{
	QAbstractAnimation::stop();
}

void AnimationDriver::updateCurrentTime(int)
{
	mWorld->step();
}

EngineDriver::EngineDriver(Box2DWorld *world) :
	QObject(),
	mWorld(world),
	mActive(false)
{}

void EngineDriver::start()
{
	qDebug("SPEEEEEEEED");
	mActive = true;
	doStep();
}

void EngineDriver::stop()
{
	mActive = false;
}

void EngineDriver::doStep()
{
	mWorld->step();
	QMetaObject::invokeMethod(this, "doStep");
}
