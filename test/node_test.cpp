//
// Created by jadjer on 29.03.2022.
//

#include <catch2/catch.hpp>
#include <jcllib/Node.hpp>

SCENARIO("Test Node object's constructor") {
  GIVEN("An node's object") {
    auto node = std::make_unique<jcl::Node>("Test", "test");

    THEN("The object created") {
      REQUIRE(node != nullptr);
      REQUIRE(node->getName() == "Test");
      REQUIRE(node->getNamespace() == "test");
    }

//    WHEN("push_back() is called") {
//      v.push_back("hullo");
//
//      THEN("The size changes") {
//        REQUIRE(v.size() == 1);
//        REQUIRE(v.capacity() >= 1);
//      }
//    }
  }
}

SCENARIO("Test service") {
  GIVEN("Node") {
    auto node = std::make_unique<jcl::Node>("Test", "test");


  }
}
