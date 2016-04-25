#pragma once

#include "ofxMachineVision/Device/Blocking.h"

namespace ofxMachineVision {
	namespace Device {
		class UEye : public ofxMachineVision::Device::Blocking {
		public:
			struct InitialisationSettings : Base::InitialisationSettings {
			public:
				InitialisationSettings() {
					add(useCameraIDAsDeviceID.set("Use Device ID as Camera ID", true));

					add(useImageFormat.set("Use Image Format", false));
					add(imageFormat.set("Image Format", 1));

					this->deviceID = 1;
				}

				ofParameter<bool> useCameraIDAsDeviceID;

				ofParameter<bool> useImageFormat;
				ofParameter<int> imageFormat;
			};

			UEye();
			virtual string getTypeName() const override;
			virtual shared_ptr<Base::InitialisationSettings> getDefaultSettings() override {
				return make_shared<InitialisationSettings>();
			}
			Specification open(shared_ptr<Base::InitialisationSettings> = nullptr) override;
			virtual void close() override;
			virtual bool startCapture() override;
			virtual void stopCapture() override;
			virtual void setExposure(ofxMachineVision::Microseconds) override;
			virtual void setGain(float) override;
			virtual void setBinning(int binningX = 1, int binningY = 1) override;
			virtual void setROI(const ofRectangle &) override;
			/*void setTriggerMode(const ofxMachineVision::TriggerMode &, const ofxMachineVision::TriggerSignalType &) override;
			virtual void setGPOMode(const ofxMachineVision::GPOMode &) override;*/
			virtual void getFrame(shared_ptr<ofxMachineVision::Frame>) override;

		protected:
			unsigned int cameraHandle;
			ofPixels pixels;
			int imageMemoryID;
			int maxClock;
			double fps;
			int frameIndex;
		};
	}
}
