/**
 *  ISO 8601 time format string to struct tm sample code
 *  2015-05-27 Mitsuru Horigome
 *
 *  > g++ xxx.cpp
 */
#include <time.h>
#include <memory.h>
#include <iostream>
#include <time.h>

/**
 * @brief ISO 8601 string to struct tm function
 *
 * @param[in] iso_string .. ISO 8601 format (yyyy-mm-ddThh:mm:ss+hh:mm)
 */
tm mktm_from_iso8601( const char* iso_string ) {

    char t    = 0x00;
    int  year = 0, mon = 0, mday = 0,
         hour = 0, min = 0, sec = 0,
         zh   = 0, zm  = 0; 

    sscanf( iso_string, "%d-%d-%dT%d:%d:%d%c%d:%d", 
            &year, &mon, &mday, &hour, &min, &sec, &t, &zh, &zm );

    tm _tm;
    memset( &_tm, 0x00, sizeof( _tm ) );

    _tm.tm_year = year;
    _tm.tm_mon  = mon;
    _tm.tm_mday = mday;
    _tm.tm_hour = hour;
    _tm.tm_min  = min;
    _tm.tm_sec  = sec;

    return _tm;
}

/**
 * main
 */
int main( int , char ** ) {

    char _iso[] = "2015-05-15T05:01:22+09:00";
    //char _iso[] = "2015-05-15T05:01:22Z";
    //

    // Call function
    tm _tm = mktm_from_iso8601( _iso );

    std::cout << "*input : "    << std::endl;
    std::cout << "  iso8601 - " << _iso << std::endl;
    std::cout << "*result:"     << std::endl;
    std::cout << "  year    - " << _tm.tm_year << std::endl;
    std::cout << "  mounth  - " << _tm.tm_mon  << std::endl;
    std::cout << "  day     - " << _tm.tm_mday << std::endl;
    std::cout << "  hour    - " << _tm.tm_hour << std::endl;
    std::cout << "  min     - " << _tm.tm_sec  << std::endl;
    std::cout << "  sec     - " << _tm.tm_sec  << std::endl;

    time_t _time = mktime(&_tm);
    std::cout << ctime(&_time);

    return 0;
}
