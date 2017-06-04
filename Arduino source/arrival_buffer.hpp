/*
  TKL Bus stop data array helpper
  Stores two entries, line number and expected arrival time in array as pairs
  Ketturi Fox 2017
*/

#include <Arduino.h>

class Arrival {
  public:
    // Maximum length not including the terminating null character.
    static const int MAX_LINE_LENGTH = 4;
    static const int MAX_TIME_LENGTH = 25;

    Arrival() {
      _line[0] = '\0';
      _time[0] = '\0';
    }

    Arrival(const char* line, const char* time) {
      // strncpy copies also the terminating null character, unless maximum length is reached.
      strncpy(_line, line, MAX_LINE_LENGTH);
      strncpy(_time, time, MAX_TIME_LENGTH);

      // Add terminating null character for cases where the maximum length is reached.
      _line[MAX_LINE_LENGTH] = '\0';
      _time[MAX_TIME_LENGTH] = '\0';
    }

    const char* line() const {
      return _line;
    }
    const char* time() const {
      return _time;
    }

  private:
    // Arrays, unlike pointers, are copied properly by the default generated assignment operator and copy constructor.
    char _line[MAX_LINE_LENGTH + 1];
    char _time[MAX_TIME_LENGTH + 1];
};


class ArrivalBuffer {
  public:
    static const int CAPACITY = 8;

    ArrivalBuffer() : _next(0), _size(0) {}

    void insert(const char* line, const char* time) {
      _list[_next++] = Arrival(line, time);
      _next = _next % CAPACITY;
      if (_size < 8) {
        _size++;
      }
    }

    int  size() const {
      return _size;
    }
    void clear()      {
      _size = 0;
    }

    const Arrival& operator [](const int i) const {
      return _list[static_cast<unsigned>(i + _next + CAPACITY - _size) % static_cast<unsigned>(CAPACITY)];
    }

  private:
    Arrival _list[CAPACITY];

    int _next;
    int _size;
};

