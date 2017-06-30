#ifndef ANGLIB_HPP
#define ANGLIB_HPP 1

#include <cmath>
#include <iostream>

namespace anglib
{
	namespace Const 
	{
		const short SEC_IN_DEG = 3600;
		const short MIN_IN_DEG = 60;
		const short DEG_IN_HOUR = 15;
		const double SEC_IN_RAD = 360 * 60 * 60 / (2 * M_PI);
		const double MIN_AT_HOUR = double(1) / MIN_IN_DEG;
		const double SEC_AT_HOUR = double(1) / SEC_IN_DEG;
	}

	template <typename IntType>
	class Deg
	{
		double sec;
		IntType min, deg;

	public:

		Deg() noexcept : sec(0), min(0), deg(0) {}

		Deg(const Deg & d) noexcept : sec(d.sec), min(d.min), deg(d.deg) {}

		Deg(const IntType deg_, const IntType min_, const double sec_) noexcept : sec(sec_), min(min_), deg(deg_)
		{}

		Deg(double rad) noexcept 
		{
    		sec = Const::SEC_IN_RAD * rad;
			deg = sec / Const::SEC_IN_DEG;
			sec -= Const::SEC_IN_DEG * deg;
			min = sec / Const::MIN_IN_DEG;
			sec -= Const::MIN_IN_DEG * min;
		}

		double toRad() const noexcept 
		{
			return (sec / Const::SEC_IN_DEG + double(min) / Const::MIN_IN_DEG + deg) * M_PI / 180;
		}

		double toSec() const noexcept
		{
			return deg * Const::SEC_IN_DEG + min * Const::MIN_IN_DEG + sec;
		}

		double toHour() const noexcept
		{
			return toSec() / (Const::SEC_IN_DEG * Const::DEG_IN_HOUR);
		}

		friend std::ostream & operator<<(std::ostream & s, const Deg & dg)
		{
			s << dg.deg << " deg " << dg.min << " min " << dg.sec << " sec";
			return s;
		}

		const Deg & operator+(const Deg & dg) noexcept
		{
			return Deg(this->toRad() + dg.toRad());
		}

		const Deg & operator-(const Deg & dg) noexcept
		{
			return Deg(this->toRad() - dg.toRad());
		}

		template <typename AriphmeticType>
		const Deg & operator*(const AriphmeticType & mult) noexcept
		{
			return Deg(this->toRad() * mult);
		}

		template <typename AriphmeticType>
		const Deg & operator/(const AriphmeticType & divs) noexcept
		{
			return Deg(this->toRad() / divs);
		}
	};

	template <typename IntType>
	class Hour
	{
		double sec;
		IntType min, hour;
	};

	namespace Const
	{
		Deg<short> pi = Deg<short>(180, 0, 0);
	}
}
#endif
