#include <actuators/MC33926.hpp>
#include <Module.hpp>

#define USE_ACTUATOR_MC33926 // TODO: da levare!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#ifdef USE_ACTUATOR_MC33926

#include <stdlib.h>

#include "ch.h"
#include "hal.h"


namespace actuators {
	MC33926::MC33926(
			Core::HW::PWMChannel& channel0,
			Core::HW::PWMChannel& channel1,
			Core::HW::Pad&        enable,
			Core::HW::Pad&        d1
	) : _channel0(channel0), _channel1(channel1), _enable(enable), _d1(d1) {}

	MC33926_SignMagnitude::MC33926_SignMagnitude(
			MC33926& device
	) : _device(device) {}

	MC33926::~MC33926()
	{}

	MC33926_SignMagnitude::~MC33926_SignMagnitude()
	{}

	bool
	MC33926::probe()
	{
		return true;
	}

	bool
	MC33926_SignMagnitude::init()
	{
		return true;
	}

	bool
	MC33926_SignMagnitude::start()
	{
		_device._enable.set();
		_device._d1.clear();
		_device._channel0.enable();
		_device._channel1.enable();
		return true;
	}

	bool
	MC33926_SignMagnitude::stop()
	{
		_device._channel0.disable();
		_device._channel1.disable();
		_device._d1.set();
		_device._enable.clear();

		return true;
	}

	bool
	MC33926_SignMagnitude::set(
			DataType& data
	)
	{
		int16_t pwm = data * 4095; // TODO: check if max is 4095 or 4096

		if (pwm >= 0) {
			_device._channel0.set(pwm);
			_device._channel1.set(0);
		} else {
			_device._channel0.set(0);
			_device._channel1.set(-pwm);
		}

		return true;
	}

	bool
	MC33926_SignMagnitude::waitUntilReady()
	{
		return true;
	}
}
#endif // ifdef USE_ACTUATOR_MC33926
