#ifndef CAMERA_CONTROL_H
#define CAMERA_CONTROL_H

#include "../CommandBase.h"
#include "WPILib.h"

class CameraControl: public CommandBase
{
private:
	IMAQdxSession session;
	Image *frame;
	unsigned int currentCamera;
    unsigned char frameSkip;

public:
	CameraControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
