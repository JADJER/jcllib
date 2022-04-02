//
// Created by jadjer on 01.04.2022.
//

#ifndef JCLLIB_INCLUDE_JCLLIB_CLIENT_HPP_
#define JCLLIB_INCLUDE_JCLLIB_CLIENT_HPP_

#include <jcllib/Connection.hpp>
#include <jcllib/exception/NotConnectionException.hpp>
#include <dbus/dbus.h>
#include <memory>

namespace jcl {

/**
 * @brief Class of client
 * @tparam T Send data type
 */
template<class T>
class Client {
 public:
  Client() = delete;
  explicit Client(std::shared_ptr<Connection> const& connection) {
    if (connection == nullptr) {
      throw NotConnectionException();
    }

    m_connection = connection;
  }

  /**
   * @brief Send data's method
   * @param data Data
   * @return True when sending data successfully, otherwise false
   */
  bool sendSignal(T&& data) {
//    DBusMessage* msg;
//    DBusMessageIter args;
//    DBusPendingCall* pending;
//
//    msg = dbus_message_new_method_call("test.method.server", // target for the method call
//                                       "/test/method/Object",// object to call on
//                                       "test.method.Type",   // interface to call on
//                                       "Method");            // method name
//    if (NULL == msg) {
//      fprintf(stderr, "Message Null\n");
//      exit(1);
//    }
//
//    // append arguments
//    dbus_message_iter_init_append(msg, &args);
//    if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &param)) {
//      fprintf(stderr, "Out Of Memory!\n");
//      exit(1);
//    }
//
//    // send message and get a handle for a reply
//    if (!dbus_connection_send_with_reply(m_connection, msg, &pending, -1)) {// -1 is default timeout
//      fprintf(stderr, "Out Of Memory!\n");
//      exit(1);
//    }
//    if (NULL == pending) {
//      fprintf(stderr, "Pending Call Null\n");
//      exit(1);
//    }
////    dbus_connection_flush(m_connection);
//
//    // free message
//    dbus_message_unref(msg);
//
//    bool stat;
//    dbus_uint32_t level;
//
//    // block until we receive a reply
//    dbus_pending_call_block(pending);
//
//    // get the reply message
//    msg = dbus_pending_call_steal_reply(pending);
//    if (NULL == msg) {
//      fprintf(stderr, "Reply Null\n");
//      exit(1);
//    }
//    // free the pending message handle
//    dbus_pending_call_unref(pending);
//
//    // read the parameters
//    if (!dbus_message_iter_init(msg, &args))
//      fprintf(stderr, "Message has no arguments!\n");
//    else if (DBUS_TYPE_BOOLEAN != dbus_message_iter_get_arg_type(&args))
//      fprintf(stderr, "Argument is not boolean!\n");
//    else
//      dbus_message_iter_get_basic(&args, &stat);
//
//    if (!dbus_message_iter_next(&args))
//      fprintf(stderr, "Message has too few arguments!\n");
//    else if (DBUS_TYPE_UINT32 != dbus_message_iter_get_arg_type(&args))
//      fprintf(stderr, "Argument is not int!\n");
//    else
//      dbus_message_iter_get_basic(&args, &level);
//
//    printf("Got Reply: %d, %d\n", stat, level);
//
//    // free reply and close connection
//    dbus_message_unref(msg);

    return false;
  }

  void callMethod() {
  }

 private:
  std::shared_ptr<Connection> m_connection;
};

}// namespace jcl

#endif//JCLLIB_INCLUDE_JCLLIB_CLIENT_HPP_
