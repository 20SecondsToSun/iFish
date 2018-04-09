#pragma once
#include "ofMain.h"
#include "Tracker.h"

#include "ofxOpenCv.h"

namespace iFish
{
	typedef ofPtr<class CameraTracker> CameraTrackerPtr;

	class CameraTracker : public Tracker
	{
	public:
		CameraTracker();
		CameraTracker(int width_, int height_);

		void start();
		void stop();

		virtual void update() override;
		virtual void draw() override;
		virtual void clear() override;

		virtual ~CameraTracker();

		float getVelocity() const;
		unsigned int getPointsNumStored() const;
		const unsigned int* getTrackColorMin() const;
		const unsigned int* getTrackColorMax() const;

		void setTrackColor(const unsigned int red_min, const unsigned int green_min, \
											const unsigned int blue_min, const unsigned int red_max, \
											const unsigned int green_max, const unsigned int blue_max);
		void setTrackColorAccuracy(const unsigned int acc);
		void setTrackUpdate(const float time);
		void setTrackThreshold(const float min_, const float max_);
		void setColorsFromMousePressed(const int x, const int y, const int acc = 30);
		void setPositionCamera(const ofPoint& position);

	private:
		void thresholdUpdate();
		void updateCurrentTrackValues();
		float calculateVelocity() const;

		ofVideoGrabber vidGrabber;  // ������
		// vector<Camera> - ������ �����; TODO: ������������ listDevices()
		enum cameraType { Front, Side };
		cameraType currentType;

		ofxCvColorImage	colorImg;  // ������� ������� �����������
		ofxCvGrayscaleImage rgbImage[3];  // ������� �����-����� ����������� �� �������
		ofxCvGrayscaleImage thresholdedImage;  // ������� ��������� �����������

		ofxCvContourFinder contours;  // "�������"


		// ����, ������� ������� � ���������� RGB �� �������� �� ���������
		// ������������� ����� ����� SetTrackColor
		unsigned int trackColor_min[3];
		unsigned int trackColor_max[3];

		float trackThreshold_min, trackThreshold_max;  // ������� ������� ��� ��������
		int cameraRect[4];  // TODO: ������������� � ������������, ������� ����� �������� � ��������

		ofVec3f objLocation;  // ������� ������� �������
		float objVelocity;  // �������� �������

		enum trackState { Tracking, NoTracking };  // ��������� ��������
		trackState currenttrackState;  // ������� ��������� ��������

		int width, height;

		float trackUpdate;  // ��� ����o ��������� ������� (� �������������)
		uint64_t currentUpdate;

		unsigned int pointsNumStored;  // ���������� �����, ������� ��������
		std::vector<ofVec3f> trackPoints_one;
		std::vector<ofVec3f> trackPoints_two;
		std::vector<ofVec3f>* currentTrackPoints;

		std::vector<uint64_t> trackTimes_one;
		std::vector<uint64_t> trackTimes_two;
		std::vector<uint64_t>* currentTrackTimes;


		ofPoint positionCamera;  // ��������� ������ � ����������
	};

}