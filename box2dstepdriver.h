#ifndef BOX2DSTEPDRIVER_H
#define BOX2DSTEPDRIVER_H

#include <QAbstractAnimation>
#include <QtGlobal>
class Box2DWorld;

class Box2DStepDriver
{
public:
	virtual ~Box2DStepDriver() = default;

	virtual void start() = 0;
	virtual void stop() = 0;
};

class AnimationDriver : public QAbstractAnimation, public Box2DStepDriver
{
	Q_OBJECT

public:
	explicit AnimationDriver(Box2DWorld *world);

	int duration() const;
	void start() override;
	void stop() override;

protected:
	void updateCurrentTime(int);

private:
	Box2DWorld *mWorld;
};

class EngineDriver : public QObject, public Box2DStepDriver
{
	Q_OBJECT

public:
	explicit EngineDriver(Box2DWorld *world);

	void start() override;
	void stop() override;

private slots:
	void doStep();

private:
	Box2DWorld *mWorld;
	bool mActive;
};

#endif // BOX2DSTEPDRIVER_H
