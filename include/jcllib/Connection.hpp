//
// Created by jadjer on 02.04.2022.
//

#ifndef JCLLIB_INCLUDE_JCLLIB_CONNECTION_HPP_
#define JCLLIB_INCLUDE_JCLLIB_CONNECTION_HPP_

#include <dbus/dbus.h>
#include <string>

namespace jcl {

class Connection {
 public:
  Connection() = delete;
  Connection(std::string const& name, std::string const& ns);
  ~Connection();

 public:
  Connection(Connection const&) = delete;
  Connection(Connection&&) noexcept = delete;
  Connection& operator=(Connection const&) = delete;
  Connection& operator=(Connection&&) noexcept = delete;

 private:
  DBusConnection* m_connection;

 private:
  std::string getAddress(std::string const& name, std::string const& ns);
};

}

#endif//JCLLIB_INCLUDE_JCLLIB_CONNECTION_HPP_
