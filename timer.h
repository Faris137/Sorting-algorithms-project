#ifndef TIMER_H
#define TIMER_H

#include <windows.h>
#include <iostream>
#include <iomanip>
using namespace std;

LARGE_INTEGER _timer_start;
LARGE_INTEGER _timer_stop;
LARGE_INTEGER _timer_frequency;

bool _timer_init = QueryPerformanceFrequency(&_timer_frequency);

#define TICK() if( _timer_init == false ) {                                    \
    cout << "Failed to query the performance frequency." << endl;              \
    cout << "Please do not use timer.h" << endl;                               \
    exit(1);                                                                   \
  }                                                                            \
  QueryPerformanceCounter(&_timer_start);

#define TOCK() QueryPerformanceCounter(&_timer_stop);


// How many counter count elapsed between TICK() and TOCK()
#define TICK_ELAPSED() (_timer_stop.QuadPart - _timer_start.QuadPart)

// Duration in seconds
#define DURATION() ( TICK_ELAPSED() / (double) _timer_frequency.QuadPart)

// A few more macro for quick and dirty measurements
#define SHOW_DURATION() cout << "Duration: "                                   \
                             << setprecision(20) << DURATION() << "s" << endl;
#define MEASURE(THIS) TICK(); THIS ; TOCK(); SHOW_DURATION();

// A few more macro for quick and dirty measurements, with message
#define MSHOW_DURATION(MESSAGE) cout << MESSAGE << endl                        \
                                     << " Duration: " << setprecision(20)      \
                                     << DURATION() << "s" << endl;
#define MMEASURE(MESSAGE, THIS) TICK(); THIS ; TOCK(); MSHOW_DURATION(MESSAGE);
#endif

