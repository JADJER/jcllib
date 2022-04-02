//
// Created by jadjer on 01.04.2022.
//

#include "PingPong.hpp"

#include <string>

PingPong::PingPong(std::shared_ptr<jcl::Connection> const& connection)
    : Node("ping_pong", "jcl", connection) {

  m_client = createClient<std::string>();
}

void PingPong::initialize() {

}

void PingPong::ping() {
//  m_client->send("test");
}

void PingPong::pong() {
}
