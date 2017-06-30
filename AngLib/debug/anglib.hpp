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
		const short DEG_IN_2PI = 360;
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

		~Deg() noexcept {}

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

		template <typename AIntType>
		AIntType mod_2pi() const noexcept
		{
			AIntType z = fabs(double(this->deg) / Const::DEG_IN_2PI);
			return z;
		}

		void mod_2pi() noexcept
		{
			this->deg = this->deg % Const::DEG_IN_2PI;
		}

		friend std::ostream & operator<<(std::ostream & s, const Deg & dg)
		{
			s << dg.deg << " deg " << dg.min << " min " << dg.sec << " sec";
			return s;
		}

		friend const Deg operator+(const Deg & dl, const Deg & dr) noexcept
		{
			return Deg(dr.toRad() + dl.toRad());
		}

		template <typename AriphmeticType>
		friend const Deg operator+(const Deg & dl, const AriphmeticType & add) noexcept
		{
			return Deg(dl.toRad() + add);
		}

		template <typename AriphmeticType>
		friend const Deg operator+(const AriphmeticType & add, const Deg & dl) noexcept
		{
			return Deg(dl.toRad() + add);
		}

		friend const Deg operator-(const Deg & dl, const Deg & dr) noexcept
		{
			return Deg(dl.toRad() - dr.toRad());
		}

		template <typename AriphmeticType>
		friend const Deg operator-(const Deg & dl, const AriphmeticType & subd) noexcept
		{
			return Deg(dl.toRad() - subd);
		}

		template <typename AriphmeticType>
		friend const Deg operator*(const Deg & dl, const AriphmeticType & mult) noexcept
		{
			return Deg(dl.toRad() * mult);
		}

		template <typename AriphmeticType>
		friend const Deg operator/(const Deg & dl, const AriphmeticType & divs) noexcept
		{
			return Deg(dl.toRad() / divs);
		}

		template <typename AriphmeticType>
		const Deg operator*(const AriphmeticType & mult) noexcept
		{
			return Deg(this->toRad() * mult);
		}

		template <typename AriphmeticType>
		const Deg operator/(const AriphmeticType & divs) noexcept
		{
			return Deg(this->toRad() / divs);
		}
	};

	template <typename IntType>
	class Hour
	{
		double sec;
		IntType min, hour;

	public:

		Hour() noexcept : sec(0), min(0), hour(0) {}

		Hour(const Hour & h) noexcept : sec(h.sec), min(h.min), hour(h.hour) {}
		Hour(short hour_, short min_, double sec_) noexcept : sec(sec_), min(min_), hour(hour_)
		{}

		Hour(double rad) noexcept
		{
    		sec = Const::SEC_IN_RAD * rad / 15;
			hour = sec / Const::SEC_IN_DEG;
			sec -= Const::SEC_IN_DEG * hour;
			min = sec / Const::MIN_IN_DEG;
			sec -= Const::MIN_IN_DEG * min;
		}

		double toSec() const noexcept
		{
			return (hour * Const::SEC_IN_DEG + min * Const::MIN_IN_DEG +
						sec) * 15 ;
		}

		double toHour() const noexcept
		{
			return toSec() / (Const::SEC_IN_DEG * 15);
		}

		double toRad() const noexcept
		{
			return toSec() / Const::SEC_IN_RAD;
		}

		friend std::ostream & operator<<(std::ostream &s, const Hour &hr)
		{
			s << hr.hour << " h " << hr.min << " m " << hr.sec << " s";
			return s;
		}

		const Hour & operator+(const Hour & hr) noexcept
		{
			return Hour(this->toRad() + hr.toRad());
		}

		const Hour & operator-(const Hour & hr) noexcept
		{
			return Hour(this->toRad() - hr.toRad());
		}

		template <typename AriphmeticType>
		const Hour & operator*(const AriphmeticType & mult) noexcept
		{
			return Hour(this->toRad() * mult);
		}

		template <typename AriphmeticType>
		const Hour & operator/(const AriphmeticType & divs) noexcept
		{
			return Hour(this->toRad() / divs);
		}
	};

	namespace Const
	{
		Deg<short> pi = Deg<short>(180, 0, 0);
	}
}
#endif
