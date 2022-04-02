//
// Created by jadjer on 01.04.2022.
//

#include "PingPong.hpp"

int main(int argc, char**argv) {
  auto connection = std::make_shared<jcl::Connection>("pingpong", "me.jadjer");

  auto pingPong = std::make_shared<PingPong>(connection);
  pingPong->initialize();
  pingPong->ping();

  return 0;
}
