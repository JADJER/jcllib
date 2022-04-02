//
// Created by jadjer on 01.04.2022.
//

#ifndef JCLLIB_EXAMPLE_PINGPONG_HPP_
#define JCLLIB_EXAMPLE_PINGPONG_HPP_

#include <jcllib/Node.hpp>

class PingPong : public jcl::Node {
 public:
  explicit PingPong(std::shared_ptr<jcl::Connection> const& connection);
  ~PingPong() override = default;

 public:
  void initialize();
  void ping();
  void pong();

 private:
  std::shared_ptr<jcl::Client<std::string>> m_client;
};

#endif//JCLLIB_EXAMPLE_PINGPONG_HPP_
