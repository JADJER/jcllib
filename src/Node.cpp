//
// Created by jadjer on 28.03.2022.
//

#include <jcllib/Node.hpp>
#include <jcllib/exception/NotConnectionException.hpp>
#include <logger/Logger.hpp>

namespace jcl {

Node::Node(std::string const& name, std::string const& ns) {
  m_nodeName = name;
  m_nodeNamespace = ns;

  auto logger = logger::Logger(logger::LEVEL_WARNING);
  logger << "Test";
  logger << " "
         << "from Node constructor";
  logger.commit();
}

Node::Node(std::string const& name, std::string const& ns, std::shared_ptr<Connection> const& connection)
    : Node(name, ns) {

  setConnection(connection);
}

void Node::setConnection(std::shared_ptr<Connection> const& connection) {
  if (connection == nullptr) {
    throw NotConnectionException();
  }

  m_connection = connection;
}

std::string Node::getName() const {
  return m_nodeName;
}

std::string Node::getNamespace() const {
  return m_nodeNamespace;
}

}// namespace jcl
