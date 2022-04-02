//
// Created by jadjer on 28.03.2022.
//

#ifndef JCLLIB_INCLUDE_JCLLIB_NODE_HPP_
#define JCLLIB_INCLUDE_JCLLIB_NODE_HPP_

#include <jcllib/Client.hpp>
#include <jcllib/Connection.hpp>
#include <jcllib/Service.hpp>
#include <jcllib/exception/NotConnectionException.hpp>
#include <memory>
#include <string>

/**
 * @namespace jcl
 * @brief JCL library's main namespace
 */
namespace jcl {

/**
 * @class Node
 * @brief
 */
class Node {
 public:
  /**
   * @brief Default constructor is deleted
   */
  Node() = delete;

  /**
   * @brief Constructor with two arguments
   * @param name Node name
   * @param ns Node namespace
   */
  Node(std::string const& name, std::string const& ns);

  /**
   * @brief Constructor with three arguments
   * @param name Node name
   * @param ns Node namespace
   * @param connection Connection for DBus
   */
  Node(std::string const& name, std::string const& ns, std::shared_ptr<Connection> const& connection);

  /**
   * @brief Default virtual destructor
   */
  virtual ~Node() = default;

 public:
  /**
   * @brief Get the node name
   * @return String
   */
  [[nodiscard]] std::string getName() const;
  /**
   * @brief Get the node namespace
   * @return String
   */
  [[nodiscard]] std::string getNamespace() const;

 public:
  /**
   * @brief
   * @param connection
   */
  void setConnection(std::shared_ptr<Connection> const& connection);

  /**
   * @brief
   * @return
   */
  template<class T>
  [[nodiscard]] std::shared_ptr<Client<T>> createClient() const {
    if (m_connection == nullptr) {
      throw NotConnectionException();
    }

    auto client = std::make_shared<Client<T>>(m_connection);
    return std::move(client);
  }

  /**
   * @brief
   * @return
   */
  [[nodiscard]] std::shared_ptr<Service> createService() const {
    if (m_connection == nullptr) {
      throw NotConnectionException();
    }

    auto service = std::make_shared<Service>();
    return std::move(service);
  }

 private:
  std::string m_nodeName;
  std::string m_nodeNamespace;
  std::shared_ptr<Connection> m_connection;
};

}// namespace jcl

#endif//JCLLIB_INCLUDE_JCLLIB_NODE_HPP_
