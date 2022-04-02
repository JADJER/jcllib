//
// Created by jadjer on 02.04.2022.
//

#ifndef JCLLIB_INCLUDE_JCLLIB_EXCEPTION_NOTCONNECTIONEXCEPTION_HPP_
#define JCLLIB_INCLUDE_JCLLIB_EXCEPTION_NOTCONNECTIONEXCEPTION_HPP_

#include <exception>

/**
 * @class NotConnectionException
 * @brief
 */
class NotConnectionException : public std::exception {
 public:
  ~NotConnectionException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {}
  char const* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
    return "Not connection";
  }
};

#endif//JCLLIB_INCLUDE_JCLLIB_EXCEPTION_NOTCONNECTIONEXCEPTION_HPP_
