#ifndef AVLDICTEXCEPTIONS_H
#define AVLDICTEXCEPTIONS_H

#include <exception>

class WrongWord : public std::exception
{
public:
  WrongWord():
    reason_("Wrong word\n")
  {}
  const char* what() const
  {
    return reason_;
  }
private:
  const char* reason_;
};

class EmptyWord : public std::exception
{
public:
  EmptyWord():
    reason_("Empty word\n")
  {}
  const char* what() const
  {
    return reason_;
  }
private:
  const char* reason_;
};

class WrongTranslate : public std::exception
{
public:
  WrongTranslate():
    reason_("Wrong translate\n")
  {}
  const char* what() const
  {
    return reason_;
  }
private:
  const char* reason_;
};

class EmptyTranslate : public std::exception
{
public:
  EmptyTranslate():
    reason_("Empty translate\n")
  {}
  const char* what() const
  {
    return reason_;
  }
private:
  const char* reason_;
};

class NoTranslate : public std::exception
{
public:
  NoTranslate():
    reason_("No translate\n")
  {}
  const char* what() const
  {
    return reason_;
  }
private:
  const char* reason_;
};

class NoWord : public std::exception
{
public:
  NoWord():
    reason_("No word\n")
  {}
  const char* what() const
  {
    return reason_;
  }
private:
  const char* reason_;
};

#endif
