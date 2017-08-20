#ifndef MOMENT_MOMENT_HPP_
#define MOMENT_MOMENT_HPP_

#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <string>


namespace moment {

	using std::chrono::system_clock;
	using std::chrono::time_point;
	using std::chrono::duration_cast;

	class moment
	{
		time_point<system_clock> m_unix;
		std::tm local_tm;
		unsigned milliSecond;

	private:
		void setTimePoint()
		{
			m_unix = system_clock::from_time_t(mktime(&local_tm));
			m_unix += std::chrono::milliseconds(milliSecond);
		}

		void setLocalTm()
		{
			auto current_time = system_clock::to_time_t(m_unix);

			local_tm = *localtime(&current_time);

			auto tm_point = system_clock::from_time_t(mktime(&local_tm));

			milliSecond = duration_cast<std::chrono::milliseconds> (m_unix.time_since_epoch()).count()
							- duration_cast<std::chrono::milliseconds> (tm_point.time_since_epoch() ).count();
		}
		
	public:

		moment()
		{
			m_unix = system_clock::now();
			setLocalTm();
		}

		moment(const long long& timestamp_milliseconds)
		{
			m_unix = time_point<system_clock>(std::chrono::milliseconds(timestamp_milliseconds));
			setLocalTm();
		}


		moment(int year, int month, int day, int hour=0, int min=0, int sec=0, int millisec=0)
		{
			local_tm = {sec,min,hour,day,month-1,year-1900};

			milliSecond = millisec;

			setTimePoint();
		}


		int year() const
		{
			return local_tm.tm_year+1900;
		}

		moment& year(int newyear)
		{

			local_tm.tm_year = newyear-1900;
			setTimePoint();


			return *this;
		}

		int years() const
		{
			return year();
		}

		moment& years(int newyear)
		{
			return year(newyear);
		}

		int month() const
		{
			return local_tm.tm_mon;
		}

		moment& month(int newmonth)
		{
			int year_diff = newmonth / 12;
			newmonth %= 12;

			local_tm.tm_year += year_diff;
			local_tm.tm_mon = newmonth;

			setTimePoint();

			return *this;
		}

		int months() const
		{
			return month();
		}

		moment& months(int newmonth)
		{
			return  month(newmonth);
		}

		int date() const
		{
			return local_tm.tm_mday;
		}

		moment& date(int newday)
		{

			local_tm.tm_mday = newday;
			setTimePoint();


			return *this;
		}

		int dates() const
		{
			return date();
		}

		moment& dates(int newday)
		{
			return date(newday);
		}

		int hour() const
		{
			return local_tm.tm_hour;
		}

		moment& hour(int newhour)
		{
			int hour_diff = newhour - local_tm.tm_hour;

			m_unix += std::chrono::hours(hour_diff);
			
			setLocalTm();

			return *this;
		}

		int hours() const
		{
			return hour();
		}

		moment& hours(int newhour)
		{
			return hour(newhour);
		}

		int minute() const
		{
			return local_tm.tm_min;
		}

		moment& minute(int newminute)
		{
			int minute_diff = newminute - local_tm.tm_min;

			m_unix += std::chrono::minutes(minute_diff);

			setLocalTm();

			return *this;
		}

		int minutes() const
		{
			return minute();
		}

		moment& minutes(int newminute)
		{
			return minutes(newminute);
		}

		int second() const
		{
			return local_tm.tm_sec;
		}

		moment& second(int newsecond)
		{
			int second_diff = newsecond - local_tm.tm_sec;

			m_unix += std::chrono::seconds(second_diff);

			setLocalTm();

			return *this;
		}

		int seconds() const
		{
			return second();
		}

		moment& seconds(int newsecond)
		{
			return second(newsecond);
		}

		int millisecond() const
		{
			return milliSecond;
		}

		moment& millisecond(int newmillisecond)
		{
			int millisecond_diff = newmillisecond - milliSecond;

			m_unix += std::chrono::milliseconds(millisecond_diff);

			setLocalTm();

			return *this;
		}

		int milliseconds() const
		{
			return millisecond();
		}

		moment& milliseconds(int newmillisecond)
		{
			return millisecond(newmillisecond);
		}

		long long unix()const
		{
			return duration_cast<std::chrono::seconds> (m_unix.time_since_epoch()).count();
		}

		moment& unix(const long long& timestamp_seconds)
		{

			m_unix = time_point<system_clock>( std::chrono::seconds(timestamp_seconds) );
			setLocalTm();

			return *this;
		}

		long long valueOf()const
		{
			return duration_cast<std::chrono::milliseconds> (m_unix.time_since_epoch()).count();
		}

		operator long long()const
		{
			return valueOf();
		}

		std::string toString() const
		{
			auto current_time = system_clock::to_time_t(m_unix);
			return std::ctime(&current_time);
		}

	};

	std::ostream& operator<<(std::ostream& os, const moment& m)
	{
		char prev = std::cout.fill('0');
		os << m.year()<<'-'<<m.month()+1<<'-'<<m.date()<<' '<< std::setw(2) <<m.hour()<<':' << std::setw(2) <<m.minute()<<':' << std::setw(2) <<m.second()<<'.' << std::setw(3) <<m.millisecond();
		return os<< std::setw(0) << std::setfill(prev) << std::endl;
	}

}  // namespace moment



#endif  // MOMENT_MOMENT_HPP
