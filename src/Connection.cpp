//
// Created by jadjer on 02.04.2022.
//

#include "jcllib/Connection.hpp"

#include <iostream>
#include <sstream>

namespace jcl {

Connection::Connection(std::string const& name, std::string const& ns) {
  DBusError connectionError;
  dbus_error_init(&connectionError);

  m_connection = dbus_bus_get(DBUS_BUS_SESSION, &connectionError);

  if (dbus_error_is_set(&connectionError)) {
    std::cerr << "Connection Error (" << connectionError.message << ")" << std::endl;
    dbus_error_free(&connectionError);
  }

  if (m_connection == nullptr) {
    throw std::runtime_error("DBus connection error");
  }

  auto address = getAddress(name, ns);
  auto ret = dbus_bus_request_name(m_connection, address.c_str(), DBUS_NAME_FLAG_REPLACE_EXISTING, &connectionError);

  if (dbus_error_is_set(&connectionError)) {
    std::cerr << "Name Error (" << connectionError.message << ")" << std::endl;
    dbus_error_free(&connectionError);
  }

  if (ret != DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER) {
    throw std::runtime_error("DBus name error");
  }
}

Connection::~Connection() {
  dbus_connection_flush(m_connection);
}

std::string Connection::getAddress(std::string const& name, std::string const& ns) {
  std::stringstream ss;

  ss << ns << "." << name;

  return ss.str();
}

}
