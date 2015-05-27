## ISO 8601 time format to struct tm sample with cpp

2015-05-27 Mitsuru Horigome.

---

ISO8601 (ex:2015-05-27T10:30:20+09:00) to struct tm samplecode.

Build

    > g++ iso2tm.cpp

Run

    *input
     iso8601 - 2015-05-15T05:01:22+09:00
    *result:
     year    - 2015
     mounth  - 5
     day     - 15
     hour    - 5
     min     - 22
     sec     - 22
     Tue Jun 15 05:01:22 3915


CPP Code

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

---
