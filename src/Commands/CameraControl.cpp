#include "CameraControl.h"

CameraControl::CameraControl():
frameSkip(0)
{
	Requires(camera);
	//session = new IMAQdxSession();
}
// Called just before this Command runs the first time
void CameraControl::Initialize()
{
	frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	//IMAQdxSession session;

	IMAQdxError imaqError;

	currentCamera = 1;

	imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
	}

	imaqError = IMAQdxConfigureGrab(session);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
	}

	imaqError = IMAQdxStartAcquisition(session);
	//robot.win(truerwr);
	if(imaqError != IMAQdxErrorSuccess)
		DriverStation::ReportError("IMAQdxStartAcquisition error: " + std::to_string((long)imaqError) + "\n");
}

// Called repeatedly when this Command is scheduled to run
void CameraControl::Execute()
{
	IMAQdxError imaqError;

	if (((frameSkip++)%4)==0)
	{

	unsigned int camNumber = oi->getCameraNumber();

	if (camNumber != currentCamera)
	{
		imaqError = IMAQdxStopAcquisition(session);
		if(imaqError != IMAQdxErrorSuccess)
			DriverStation::ReportError("IMAQdxStopAcquisition error: " + std::to_string((long)imaqError) + "\n");

		imaqError = IMAQdxCloseCamera(session);
		if(imaqError != IMAQdxErrorSuccess)
			DriverStation::ReportError("IMAQdxCloseCamera error: " + std::to_string((long)imaqError) + "\n");


		if (camNumber ==1)
		{
			imaqError = IMAQdxOpenCamera("cam1", IMAQdxCameraControlModeController, &session);
			if(imaqError != IMAQdxErrorSuccess) {
				DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
			}

			imaqError = IMAQdxConfigureGrab(session);
			if(imaqError != IMAQdxErrorSuccess) {
				DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
			}

			imaqError = IMAQdxStartAcquisition(session);
			if(imaqError != IMAQdxErrorSuccess)
				DriverStation::ReportError("IMAQdxStartAcquisition error: " + std::to_string((long)imaqError) + "\n");
		}
		else
		{
			imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
			if(imaqError != IMAQdxErrorSuccess) {
				DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
			}

			imaqError = IMAQdxConfigureGrab(session);
			if(imaqError != IMAQdxErrorSuccess) {
				DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
			}

			imaqError = IMAQdxStartAcquisition(session);
			if(imaqError != IMAQdxErrorSuccess)
				DriverStation::ReportError("IMAQdxStartAcquisition error: " + std::to_string((long)imaqError) + "\n");

		}

		currentCamera = camNumber;
	}


	imaqError = IMAQdxGrab(session, frame, true, NULL);


	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
	}
	else {
		CameraServer::GetInstance()->SetImage(frame);
	}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool CameraControl::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CameraControl::End()
{
	IMAQdxStopAcquisition(session);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CameraControl::Interrupted()
{
	IMAQdxError imaqError;
	imaqError = IMAQdxStopAcquisition(session);
	if(imaqError != IMAQdxErrorSuccess)
		DriverStation::ReportError("IMAQdxStopAcquisition error: " + std::to_string((long)imaqError) + "\n");

	imaqError = IMAQdxCloseCamera(session);
	if(imaqError != IMAQdxErrorSuccess)
		DriverStation::ReportError("IMAQdxCloseCamera error: " + std::to_string((long)imaqError) + "\n");

}

