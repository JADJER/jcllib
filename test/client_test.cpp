//
// Created by jadjer on 01.04.2022.
//

#include <catch2/catch.hpp>

#include <jcllib/Node.hpp>

class Client : public jcl::Node {
 public:
  ~Client() override = default;

  void test() {
    auto client = createClient<int>();
  }
};