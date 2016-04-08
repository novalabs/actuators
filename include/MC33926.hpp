#pragma once

#include <Configuration.hpp>

#ifdef USE_ACTUATOR_MC33926

#include <Core/HW/PWM.hpp>
#include <Core/HW/GPIO.hpp>
#include <Core/MW/CoreActuator.hpp>

namespace actuators {
	class MC33926
	{
public:
		MC33926(
				Core::HW::PWMChannel& channel0,
				Core::HW::PWMChannel& channel1,
				Core::HW::Pad&        enable,
				Core::HW::Pad&        d1
		);

		virtual
		~MC33926();

public:
		bool
		probe();


public:
		Core::HW::PWMChannel& _channel0;
		Core::HW::PWMChannel& _channel1;
		Core::HW::Pad&        _enable;
		Core::HW::Pad&        _d1;
	};


	class MC33926_SignMagnitude:
		public Core::MW::CoreActuator<float>
	{
public:
		MC33926_SignMagnitude(
				MC33926& device
		);

		virtual
		~MC33926_SignMagnitude();

public:
		bool
		init();

		bool
		start();

		bool
		stop();

		bool
		waitUntilReady();

		bool
		set(
				DataType& data
		);


protected:
		Core::MW::Time _set_timestamp;

private:
		MC33926& _device;
	};
}
#endif // ifdef USE_ACTUATOR_MC33926
